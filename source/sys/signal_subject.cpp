#include "signal_subject.h"


namespace sys {


g_SignalSubject &g_SignalSubject::instance() {
    static g_SignalSubject instance;
    return instance;
}


void g_SignalSubject::registerSignalObserver(ISignalObserver& signal_observer) {
    lock_guard<recursive_mutex> locker(m_lock);
    m_observers.push_back(&signal_observer);
}


void g_SignalSubject::unregisterSignalObserver(ISignalObserver& signal_observer) {
    lock_guard<recursive_mutex> locker(m_lock);
    m_observers.remove(&signal_observer);
}


g_SignalSubject::g_SignalSubject() {
    signal(SIGINT, sigintHandler);
    signal(SIGTERM, sigtermHandler);
}


g_SignalSubject::~g_SignalSubject() {
}


void g_SignalSubject::sigintHandler(int sigint) {
    lock_guard<recursive_mutex> locker(g_SignalSubject::instance().m_lock);
    for (auto &i: g_SignalSubject::instance().m_observers) {
        i->onInterrupt();
    }
}


void g_SignalSubject::sigtermHandler(int sigint) {
    lock_guard<recursive_mutex> locker(g_SignalSubject::instance().m_lock);
    for (auto &i: g_SignalSubject::instance().m_observers) {
        i->onTermination();
    }
}


} /* sys */

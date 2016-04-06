#include "signal_subject.h"


namespace sys {


g_SignalSubject& g_SignalSubject::instance() {
    static g_SignalSubject instance;
    return instance;
}


void g_SignalSubject::registerSignalObserver(ISignalObserver& signal_observer) {
    lock_guard<recursive_mutex> locker(m_lock);

//    if (find(m_observers.begin(), m_observers.end(), signal_observer) == m_observers.end())
//        m_observers.push_back(&signal_observer);
//    else
//        throw std::runtime_error("register duplicase signal obsever");

    m_observers.insert(&signal_observer);
//    if (!m_observers.insert(signal_observer))
//        throw std::runtime_error("register duplicase signal obsever");

}


void g_SignalSubject::unregisterSignalObserver(ISignalObserver& signal_observer) {
    lock_guard<recursive_mutex> locker(m_lock);
//    m_observers.remove(&signal_observer);
    m_observers.erase(&signal_observer);
}


g_SignalSubject::g_SignalSubject() {
    signal(SIGINT, sigintHandler);
    signal(SIGTERM, sigtermHandler);
}


g_SignalSubject::~g_SignalSubject() {
}


void g_SignalSubject::sigintHandler(int sigint) {
    lock_guard<recursive_mutex> locker(g_SignalSubject::instance().m_lock);
    for (auto& i: g_SignalSubject::instance().m_observers) {
        i->onInterrupt();
    }
}


void g_SignalSubject::sigtermHandler(int sigint) {
    lock_guard<recursive_mutex> locker(g_SignalSubject::instance().m_lock);
    for (auto& i: g_SignalSubject::instance().m_observers) {
        i->onTermination();
    }
}


} /* sys */

#include "signal_manager.h"



namespace sys {


g_SignalSubject *g_SignalSubject::instance() {
    if (m_instance == NULL)
        m_instance = new g_SignalSubject();

    return m_instance;
}


void g_SignalSubject::registerSignalObserver(ISignalObserver::WeakPtrT signal_handler) {
    m_handlers.push_back(signal_handler);
}


void g_SignalSubject::unregisterSignalObserver(ISignalObserver::WeakPtrT signal_handler) {
    m_handlers.remove_if(
        [signal_handler] (ISignalObserver::WeakPtrT item) {
            return signal_handler.lock() == item.lock();
    });
}


g_SignalSubject::g_SignalSubject() {
    signal(SIGINT, sigintHandler);
    signal(SIGTERM, sigtermHandler);
}


g_SignalSubject::~g_SignalSubject() {
}


void g_SignalSubject::sigintHandler(int sigint) {
    for (auto &i: instance()->m_handlers) {
        i.lock()->onInterrupt();
    }
}


void g_SignalSubject::sigtermHandler(int sigint) {
    for (auto &i: instance()->m_handlers) {
        i.lock()->onTermination();
    }
}


g_SignalSubject *g_SignalSubject::m_instance = NULL;


} /* sys */

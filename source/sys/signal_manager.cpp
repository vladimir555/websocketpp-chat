#include "signal_manager.h"



namespace sys {


g_SignalManager *g_SignalManager::instance() {
    if (m_instance == NULL)
        m_instance = new g_SignalManager();

    return m_instance;
}


void g_SignalManager::addSignalHandler(ISignalHandler::WeakPtrT signal_handler) {
    m_handlers.push_back(signal_handler);
}


void g_SignalManager::delSignalHandler(ISignalHandler::WeakPtrT signal_handler) {
    m_handlers.remove_if(
        [signal_handler] (ISignalHandler::WeakPtrT item) {
            return signal_handler.lock() == item.lock();
    });
}


g_SignalManager::g_SignalManager() {
    signal(SIGINT, sigintHandler);
    signal(SIGTERM, sigtermHandler);
}


g_SignalManager::~g_SignalManager() {
}


void g_SignalManager::sigintHandler(int sigint) {
    for (auto &i: instance()->m_handlers) {
        i.lock()->onInterrupt();
    }
}


void g_SignalManager::sigtermHandler(int sigint) {
    for (auto &i: instance()->m_handlers) {
        i.lock()->onTermination();
    }
}


g_SignalManager *g_SignalManager::m_instance = NULL;


} /* sys */

#include "server.h"



namespace application {
namespace implementation {


CServer::CServer(IConfig::SharedPtrConstT config)
:
//    m_termination_signal(0),
    m_config(config),
    m_websocket_request_handler(
        new CWebSocketRequestHandler(
            config->getAddress(),
            config->getPort()
        )
    )
{
    g_SignalSubject::instance().registerSignalObserver(*this);
}


CServer::~CServer() {
    g_SignalSubject::instance().unregisterSignalObserver(*this);
}


void CServer::initialize() {
    m_websocket_request_handler->initialize();
}


void CServer::finalize() {
    m_websocket_request_handler->finalize();
}


void CServer::run() {
    m_websocket_request_handler->start();
//    cout << "wait for interrupt" << endl;
//    while(!m_termination_signal) {
//        cout << "m_termination_signal = " << m_termination_signal << endl;
//        sleep(1);
//    }
//    cout << "interrupted" << endl;
}


void CServer::onInterrupt() {
//    m_termination_signal = 1;
    m_websocket_request_handler->stop();
}


void CServer::onTermination() {
    onInterrupt();
}


} /* implementation */
} /* application */

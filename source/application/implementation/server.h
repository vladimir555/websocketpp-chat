#ifndef CSERVER_H
#define CSERVER_H


#include "application/application.h"
#include "service/service.h"
#include "service/implementation/websocket_request_handler.h"
#include "sys/signal_manager.h"
#include "sys/signal_handler.h"
#include "config/config.h"


using service::IService;
using service::implementation::CWebSocketRequestHandler;
using sys::g_SignalManager;
using sys::ISignalHandler;
using config::IConfig;


namespace application {
namespace implementation {


class CServer: public IApplication, public ISignalHandler {
public:
    CServer(IConfig::SharedPtrConstT config);
   ~CServer();

    //IApplication overrides
    void initialize();
    void finalize();
    void run();

private:
    //ISignalHandler overrides
    void onInterrupt();
    void onTermination();

//    g_SignalManager::SignalAtomicT  m_termination_signal;
    ISignalHandler::SharedPtrT      m_this_signal_handler;
    IConfig::SharedPtrConstT        m_config;
    IService::SharedPtrT            m_websocket_request_handler;

};


} /* implementation */
} /* application */


#endif // CSERVER_H
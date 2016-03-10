#ifndef CSERVER_H
#define CSERVER_H


#include <memory>

#include "application/application.h"
#include "service/service.h"
#include "service/implementation/websocket_request_handler.h"
#include "sys/signal_subject.h"
#include "sys/signal_observer.h"
#include "config/config.h"


using service::IService;
using service::implementation::CWebSocketRequestHandler;
using sys::g_SignalSubject;
using sys::ISignalObserver;
using config::IConfig;


namespace application {
namespace implementation {


class CServer:
    public IApplication,
    public ISignalObserver
{
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
    IConfig::SharedPtrConstT        m_config;
    IService::SharedPtrT            m_websocket_request_handler;

};


} /* implementation */
} /* application */


#endif // CSERVER_H

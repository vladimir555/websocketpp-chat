#ifndef CWEBSOCKETREQUESTHANDLER_H
#define CWEBSOCKETREQUESTHANDLER_H


#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <iostream>

#include "service/service.h"
#include "config/config.h"
#include "sys/signal_manager.h"
#include "sys/signal_handler.h"


using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;
using std::cout;
using std::endl;

using config::IConfig;
using sys::g_SignalSubject;
using sys::ISignalObserver;


namespace service {
namespace implementation {


/**
 * @brief pull out the type of messages sent by our config
 */
typedef websocketpp::server<websocketpp::config::asio> WebSocketListenerT;
/**
 * @brief pull out the type of messages sent by our config
 */
typedef WebSocketListenerT::message_ptr MessagePtrT;


/**
 * @brief The CWebSocketRequestHandler class
 */
class CWebSocketRequestHandler: public IService {
public:
    /**
     * @brief constructor
     * @param config
     */
    CWebSocketRequestHandler(const string &address, const int &port);
    /**
     * @brief destructor
     */
   ~CWebSocketRequestHandler();
    /**
     * @brief callback to handle incoming messages
     */
    static void onMessage(WebSocketListenerT* s, websocketpp::connection_hdl hdl, MessagePtrT msg);

    //IService
    void initialize();
    void finalize();
    void start();
    void stop();

private:
    string              m_address;
    int                 m_port;
    WebSocketListenerT  m_websocket_listener;
};


} /* implementation */
} /* service */


#endif // CWEBSOCKETREQUESTHANDLER_H

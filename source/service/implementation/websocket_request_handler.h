#ifndef CWEBSOCKETREQUESTHANDLER_H
#define CWEBSOCKETREQUESTHANDLER_H


#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <iostream>

#include "service/service.h"
#include "config/config.h"


using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;
using std::cout;
using std::endl;

using config::IConfig;


/**
 * @brief pull out the type of messages sent by our config
 */
typedef websocketpp::server<websocketpp::config::asio> WebSocketListenerT;
/**
 * @brief pull out the type of messages sent by our config
 */
typedef WebSocketListenerT::message_ptr message_ptr;


namespace service {
namespace implementation {


class CWebSocketRequestHandler: public IService {
public:
    CWebSocketRequestHandler(const IConfig::SharedPtrConstT config);
   ~CWebSocketRequestHandler();


    /**
     * @brief callback to handle incoming messages
     */
    static void onMessage(WebSocketListenerT* s, websocketpp::connection_hdl hdl, message_ptr msg);


    void initialize();
    void finalize();
    void start();
    void stop();

private:
    IConfig::SharedPtrConstT m_config;
    WebSocketListenerT  m_websocket_listener;
};


} /* implementation */
} /* service */


#endif // CWEBSOCKETREQUESTHANDLER_H

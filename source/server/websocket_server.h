#ifndef WEBSOCKETSERVER_H
#define WEBSOCKETSERVER_H


#include <iostream>
#include <websocketpp/server.hpp>
#include <websocketpp/config/asio_no_tls.hpp>


typedef websocketpp::server<websocketpp::config::asio> server_t;


class CWebsocketServer
{
public:
    CWebsocketServer();
   ~CWebsocketServer();

    typedef websocketpp::server<websocketpp::config::asio>::message_ptr
        MessagePtrT;
    typedef websocketpp::connection_hdl ConnectionHandleT;

    void onMessage(ConnectionHandleT hdl, MessagePtrT msg);
};


#endif // WEBSOCKETSERVER_H

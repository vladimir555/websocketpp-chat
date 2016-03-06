#ifndef WEBSOCKETSERVER_H
#define WEBSOCKETSERVER_H


#include <websocketpp/server.hpp>
#include <websocketpp/config/asio_no_tls.hpp>


class WebsocketServer
{
public:
    WebsocketServer();
   ~WebsocketServer();
};


#endif // WEBSOCKETSERVER_H

#include "websocket_server.h"


CWebsocketServer::CWebsocketServer()
{
}


CWebsocketServer::~CWebsocketServer()
{
}


void CWebsocketServer::onMessage(ConnectionHandleT hdl, MessagePtrT msg)
{
     std::cout << msg->get_payload() << std::endl;
}

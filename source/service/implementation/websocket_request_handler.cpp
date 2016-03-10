#include "websocket_request_handler.h"



namespace service {
namespace implementation {


CWebSocketRequestHandler::CWebSocketRequestHandler(const string &address, const int &port)
:
    m_address   (address),
    m_port      (port)
{}


CWebSocketRequestHandler::~CWebSocketRequestHandler() {
}


void CWebSocketRequestHandler::onMessage(WebSocketListenerT* s, websocketpp::connection_hdl hdl, MessagePtrT msg) {
    cout << "onMessage called with hdl: " << hdl.lock().get()
        << " and message: " << msg->get_payload()
        << endl;
    /*
     * check for a special command to instruct the server to stop listening so
     * it can be cleanly exited.
     */
    if (msg->get_payload() == "stop-listening") {
        s->stop_listening();
        return;
    }

    try {
        s->send(hdl, msg->get_payload(), msg->get_opcode());
    } catch (const websocketpp::lib::error_code& e) {
        cout << "Echo failed because: " << e
            << "(" << e.message() << ")" << endl;
    }
}


void CWebSocketRequestHandler::initialize() {
    cout << "CWebSocketRequestHandler::initialize" << endl;
    // set logging settings
    m_websocket_listener.set_access_channels(websocketpp::log::alevel::all);
    m_websocket_listener.clear_access_channels(websocketpp::log::alevel::frame_payload);
    // initialize asio
    m_websocket_listener.init_asio();
    // register message handler
    m_websocket_listener.set_message_handler(bind(&onMessage, &m_websocket_listener, _1, _2));
}


void CWebSocketRequestHandler::finalize() {
    cout << "CWebSocketRequestHandler::finalize" << endl;
}


void CWebSocketRequestHandler::start() {
    cout << "CWebSocketRequestHandler::run" << endl;
    // Listen on port
    m_websocket_listener.listen(m_port);
    // Start the server accept loop
    m_websocket_listener.start_accept();
    // Start the ASIO io_service run loop
    //FIXME:
//    m_websocket_listener.run();
    sleep(10);
}


void CWebSocketRequestHandler::stop() {
    //TODO: stop listener
    cout << "CWebSocketRequestHandler::stop not implemented" << endl;
}


} /* implementation */
} /* service */

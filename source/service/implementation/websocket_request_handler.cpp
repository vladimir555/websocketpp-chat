#include "websocket_request_handler.h"



namespace service {
namespace implementation {


CWebSocketRequestHandler::CWebSocketRequestHandler(const IConfig::SharedPtrConstT config)
:
    m_config(config)
{}


CWebSocketRequestHandler::~CWebSocketRequestHandler() {
}


void CWebSocketRequestHandler::onMessage(WebSocketListenerT* s, websocketpp::connection_hdl hdl, message_ptr msg) {
    std::cout << "onMessage called with hdl: " << hdl.lock().get()
          << " and message: " << msg->get_payload()
          << std::endl;

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
        std::cout << "Echo failed because: " << e
            << "(" << e.message() << ")" << std::endl;
    }
}


void CWebSocketRequestHandler::initialize() {
    // set logging settings
    m_websocket_listener.set_access_channels(websocketpp::log::alevel::all);
    m_websocket_listener.clear_access_channels(websocketpp::log::alevel::frame_payload);

    // initialize asio
    m_websocket_listener.init_asio();

    // register message handler
    m_websocket_listener.set_message_handler(bind(&onMessage, &m_websocket_listener, _1, _2));
}


void CWebSocketRequestHandler::finalize() {

}


void CWebSocketRequestHandler::start() {
    // Listen on port 9002
    m_websocket_listener.listen(9002);

    // Start the server accept loop
    m_websocket_listener.start_accept();

    // Start the ASIO io_service run loop
    m_websocket_listener.run();
}


void CWebSocketRequestHandler::stop() {
}


} /* implementation */
} /* service */

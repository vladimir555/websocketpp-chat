#include "config/config.h"
#include "config/implementation/default_config.h"

#include "service/service.h"
#include "service/implementation/websocket_request_handler.h"

#include <iostream>
#include <csignal>


using config::IConfig;
using config::implementation::CDefaultConfig;

using service::IService;
using service::implementation::CWebSocketRequestHandler;


int main(int argc, char *argv[]) {
    IConfig::SharedPtrConstT config(new CDefaultConfig());

    std::cout << "port      = " << config->getPort()    << std::endl;
    std::cout << "address   = " << config->getAddress() << std::endl;

    IService::SharedPtrT service(new CWebSocketRequestHandler(config));
    service->initialize();

    try {
        service->start();

        // wait for interrupt or terminate
        while(true) {
            sleep(1);
        }
    } catch(...) {
        std::cout << "interrupt" << std::endl;
    }

    service->stop();
    service->finalize();

    std::cout << "quit" << std::endl;
}

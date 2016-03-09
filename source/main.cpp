#include <iostream>
#include <csignal>

#include "config/config.h"
#include "config/implementation/default_config.h"

#include "application/application.h"
#include "application/implementation/server.h"


using config::IConfig;
using config::implementation::CDefaultConfig;

using application::IApplication;
using application::implementation::CServer;


int main(int argc, char *argv[]) {
    IConfig::SharedPtrConstT config(new CDefaultConfig());

    std::cout << "port      = " << config->getPort()    << std::endl;
    std::cout << "address   = " << config->getAddress() << std::endl;

    IApplication::SharedPtrT server(new CServer(config));

    server->initialize();
    server->run();
    server->finalize();

    std::cout << "quit" << std::endl;
}

#include "config/config.h"
#include "config/implementation/default_config.h"

#include <iostream>


using config::IConfig;
using config::implementation::CDefaultConfig;


int main(int argc, char *argv[]) {
    IConfig::SharedPtrT config(new CDefaultConfig());

    std::cout << "port      = " << config->getPort()    << std::endl;
    std::cout << "address   = " << config->getAddress() << std::endl;
}

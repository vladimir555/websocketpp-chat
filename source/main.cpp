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


//#include "pattern/singleton.h"
//using namespace std;
//class Global: public pattern::CSingleton<Global> {
//private:
//    int i = 0;
//
//    friend pattern::CSingleton<Global>;
//    Global() {
//        cout << "create global" << endl;
//    };
//
//    virtual ~Global() {
//        cout << "destroy global" << endl;
//    };
//
//public:
//
//    void func() {
//        cout << i << endl; i++;
//    };
//};


int main(int argc, char *argv[]) {
//    Global::instance().func();
//    Global::instance().func();
//    return 0;

    IConfig::SharedPtrConstT config(new CDefaultConfig());

    std::cout << "port      = " << config->getPort()    << std::endl;
    std::cout << "address   = " << config->getAddress() << std::endl;

    IApplication::SharedPtrT server(new CServer(config));

    server->initialize();
    server->run();
    server->finalize();

    std::cout << "quit" << std::endl;
}

#include "config/config.h"
#include "config/implementation/default_config.h"


using config::IConfig;
using config::implementation::DefaultConfig;


int main(int argc, char *argv[]) {
    IConfig::SharedPtrT config(new DefaultConfig());
}

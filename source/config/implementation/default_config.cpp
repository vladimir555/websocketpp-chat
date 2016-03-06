#include "default_config.h"



namespace config {
namespace implementation {


DefaultConfig::DefaultConfig()
:
    port    (55555),
    address ("127.0.0.1")
{}


DefaultConfig::~DefaultConfig() {
}


int DefaultConfig::getPort() const {
    return port;
}


string DefaultConfig::getAddress() const {
    return address;
}


} /* implementation */
} /* config */

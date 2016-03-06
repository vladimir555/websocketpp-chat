#include "default_config.h"



namespace config {
namespace implementation {


CDefaultConfig::CDefaultConfig()
:
    m_port    (55555),
    m_address ("127.0.0.1")
{}


CDefaultConfig::~CDefaultConfig() {
}


int CDefaultConfig::getPort() const {
    return m_port;
}


string CDefaultConfig::getAddress() const {
    return m_address;
}


} /* implementation */
} /* config */

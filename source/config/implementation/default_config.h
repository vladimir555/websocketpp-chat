#ifndef DEFAULTCONFIG_H
#define DEFAULTCONFIG_H


#include "config/config.h"

#include <string>


using std::string;


namespace config {
namespace implementation {


/**
 * @brief The DefaultConfig class,
 * config with default values
 */
class CDefaultConfig : public IConfig {
public:
    CDefaultConfig();
   ~CDefaultConfig();

    /**
     * @brief getPort
     * @return server listening port
     */
    int     getPort() const;
    /**
     * @brief getAddress
     * @return server listening ip address
     */
    string  getAddress() const;

private:
    int     m_port;
    string  m_address;
};


} /* implementation */
} /* config */


#endif // DEFAULTCONFIG_H

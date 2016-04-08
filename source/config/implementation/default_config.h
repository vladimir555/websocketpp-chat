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
    virtual int getPort() const override final;
    /**
     * @brief getAddress
     * @return server listening ip address
     */
    virtual string getAddress() const override final;

private:
    int m_port;
    string m_address;
};


} /* implementation */
} /* config */


#endif // DEFAULTCONFIG_H

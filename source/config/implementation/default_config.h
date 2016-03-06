#ifndef DEFAULTCONFIG_H
#define DEFAULTCONFIG_H


#include "config/config.h"

#include <string>


using std::string;


namespace config {
namespace implementation {


class DefaultConfig : public IConfig {
public:
    DefaultConfig();
   ~DefaultConfig();

    int getPort() const;
    string getAddress() const;

private:
    int     port;
    string  address;
};


} /* implementation */
} /* config */


#endif // DEFAULTCONFIG_H

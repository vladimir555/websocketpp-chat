#ifndef CONFIG_H
#define CONFIG_H


#include <string>
#include <memory>


using std::string;


namespace config {


class IConfig
{
public:
    typedef std::shared_ptr<IConfig> SharedPtrT;

    virtual int     getPort() const = 0;
    virtual string  getAddress() const = 0;
};


} /* config */


#endif // CONFIG_H

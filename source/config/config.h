#ifndef CONFIG_H
#define CONFIG_H


#include <string>
#include <memory>


using std::string;


namespace config {


/**
 * @brief The IConfig interface
 * application config
 */
class IConfig
{
public:
    typedef std::shared_ptr<IConfig> SharedPtrT;

    /**
     * @brief getPort
     * @return server listening port
     */
    virtual int     getPort() const = 0;
    /**
     * @brief getAddress
     * @return server listening address
     */
    virtual string  getAddress() const = 0;
};


} /* config */


#endif // CONFIG_H

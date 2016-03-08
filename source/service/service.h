#ifndef ISERVICE_H
#define ISERVICE_H


#include <memory>


namespace service {


class IService {
public:
    typedef std::shared_ptr<IService> SharedPtrT;

    virtual void initialize()   = 0;
    virtual void finalize()     = 0;
    virtual void start()        = 0;
    virtual void stop()         = 0;
};


} /* service */


#endif // CWEBSOCKETREQUESTHANDLER_H

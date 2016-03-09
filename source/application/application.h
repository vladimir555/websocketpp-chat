#ifndef APPLICATION_H
#define APPLICATION_H


#include <memory>


namespace application {


class IApplication {
public:
    typedef std::shared_ptr<IApplication> SharedPtrT;

    virtual void initialize() = 0;
    virtual void finalize() = 0;
    virtual void run() = 0;
};


}


#endif // APPLICATION_H

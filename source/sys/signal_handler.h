#ifndef SIGNAL_HANDLER_H
#define SIGNAL_HANDLER_H


#include <memory>


namespace sys {


class ISignalHandler {
public:
    typedef std::shared_ptr<ISignalHandler> SharedPtrT;
    typedef std::weak_ptr  <ISignalHandler> WeakPtrT;

    virtual void onInterrupt() = 0;
    virtual void onTermination() = 0;
};


} /* sys */


#endif // SIGNAL_HANDLER_H

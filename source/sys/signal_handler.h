#ifndef SIGNAL_HANDLER_H
#define SIGNAL_HANDLER_H


#include <memory>


namespace sys {


class ISignalObserver//: public std::enable_shared_from_this<ISignalHandler>
{
public:
    typedef std::shared_ptr<ISignalObserver> SharedPtrT;
    typedef std::weak_ptr  <ISignalObserver> WeakPtrT;

    virtual void onInterrupt() = 0;
    virtual void onTermination() = 0;

    virtual ~ISignalObserver() {}
};


} /* sys */


#endif // SIGNAL_HANDLER_H

#ifndef SIGNAL_HANDLER_H
#define SIGNAL_HANDLER_H


//#include <memory>


#include "pattern/IEvent.h"
#include "pattern/IObserver.h"


using pattern::IEvent;
using pattern::IObserver;


namespace sys {


//class ISignalEvent: public IEvent {
//
//};
//
//
//class ISignalObserver: public IObserver {
//public:
//
//};


class ISignalObserver {
public:
    typedef std::shared_ptr<ISignalObserver> SharedPtrT;

    virtual void onInterrupt() = 0;
    virtual void onTermination() = 0;

    virtual ~ISignalObserver() {}
};


} /* sys */


#endif // SIGNAL_HANDLER_H

//
// Created by volodja on 28.03.2016.
//

#ifndef WEBSOCKETPP_CHAT_ISUBJECT_H
#define WEBSOCKETPP_CHAT_ISUBJECT_H


#include "IObserver.h"
#include "IEvent.h"


namespace pattern {


class ISubject {
public:
    virtual ~ISubject() = default;

    virtual void attach(IObserver&) = 0;
    virtual void detach(IObserver&) = 0;
    virtual void notifyAll(const IEvent&) = 0;
};


} /* pattern */


#endif //WEBSOCKETPP_CHAT_ISUBJECT_H

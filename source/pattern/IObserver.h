//
// Created by volodja on 28.03.2016.
//


#ifndef WEBSOCKETPP_CHAT_IOBSERVER_H
#define WEBSOCKETPP_CHAT_IOBSERVER_H


#include "IEvent.h"


namespace pattern {


class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void notify(const IEvent &event) = 0;
};


}


#endif //WEBSOCKETPP_CHAT_IOBSERVER_H

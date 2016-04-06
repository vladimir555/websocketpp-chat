//
// Created by volodja on 28.03.2016.
//

#ifndef WEBSOCKETPP_CHAT_COBSERVER_H
#define WEBSOCKETPP_CHAT_COBSERVER_H


#include "pattern/IObserver.h"
#include "pattern/ISubject.h"


namespace pattern {
namespace implementation {


class CObserver: public IObserver {
public:
    CObserver(ISubject& subject);
   ~CObserver();

private:
    ISubject &m_subject;
};


} /* implementation */
} /* pattern */


#endif //WEBSOCKETPP_CHAT_COBSERVER_H

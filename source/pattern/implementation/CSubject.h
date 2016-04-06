//
// Created by volodja on 28.03.2016.
//

#ifndef WEBSOCKETPP_CHAT_CSUBJECT_H
#define WEBSOCKETPP_CHAT_CSUBJECT_H


#include <set>
#include <exception>
#include "pattern/ISubject.h"
#include "pattern/IObserver.h"
#include "pattern/IEvent.h"


using std::set;
using std::logic_error;
using std::reference_wrapper;


namespace pattern {
namespace implementation {


class CSubject: public ISubject {
public:
    CSubject();
   ~CSubject();

    void attach(IObserver &observer);
    void detach(IObserver &observer);
    void notifyAll(const IEvent& event);

private:
    set<IObserver* > m_observers;
};


} /* implementation */
} /* pattern */


#endif //WEBSOCKETPP_CHAT_CSUBJECT_H

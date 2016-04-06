//
// Created by volodja on 28.03.2016.
//

#include "CSubject.h"


namespace pattern  {
namespace implementation {


CSubject::CSubject() {
}


CSubject::~CSubject() {
}


void CSubject::attach(IObserver &observer) {
    if (!m_observers.insert(&observer).second)
        throw logic_error("attach duplicate observer");
}


void CSubject::detach(IObserver &observer) {
    if (m_observers.erase(&observer) == 0)
        throw logic_error("detach unatached observer");
}


void CSubject::notifyAll(const IEvent &event) {
    for (auto i: m_observers)
        i->notify(event);
}


} /* implementation */
} /* pattern */

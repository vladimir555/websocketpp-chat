//
// Created by volodja on 28.03.2016.
//

#include "CObserver.h"


namespace pattern {
namespace implementation {


CObserver::CObserver(ISubject& subject)
:
    m_subject(subject)
{
    m_subject.attach(*this);
}


CObserver::~CObserver() {
    m_subject.detach(*this);
}


} /* implementation */
} /* pattern */

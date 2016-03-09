#ifndef G_SIGNALMANAGER_H
#define G_SIGNALMANAGER_H


#include <list>
#include <csignal>

#include "signal_handler.h"


using std::list;
using std::sig_atomic_t;


namespace sys {


/**
 * @brief global signal handler and multicast to ISignalHandler's
 */
class g_SignalSubject {
public:
    /**
     * @brief SignalAtomicT
     */
    typedef sig_atomic_t SignalAtomicT;
    /**
     * @brief sigletone instance
     * @return
     */
    static g_SignalSubject *instance();
    /**
     * @brief add signal handler to multicast
     * @param signal_handler
     */
    void registerSignalObserver(ISignalObserver::WeakPtrT signal_handler);
    /**
     * @brief delete signal handler from multicast
     * @param signal_handler
     */
    void unregisterSignalObserver(ISignalObserver::WeakPtrT signal_handler);

private:
    /**
     * @brief constructor g_SignalManager
     */
    g_SignalSubject();
    /**
     * @brief destructor
     */
   ~g_SignalSubject();
    /**
     * @brief sigint handler
     * @param sigint
     */
    static void sigintHandler(int sigint);
    /**
     * @brief sigterm handler
     * @param sigint
     */
    static void sigtermHandler(int sig);
    /**
     * @brief singleton instance
     */
    static g_SignalSubject *m_instance;
    /**
     * @brief handlers list for signals multicast
     */
    list<ISignalObserver::WeakPtrT> m_handlers;
};


} /* sys */


#endif // G_SIGNALMANAGER_H

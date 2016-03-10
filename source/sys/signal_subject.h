#ifndef G_SIGNALMANAGER_H
#define G_SIGNALMANAGER_H


#include <list>
#include <csignal>
#include <mutex>

#include "signal_observer.h"


using std::list;
using std::sig_atomic_t;
using std::recursive_mutex;
using std::lock_guard;


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
    static g_SignalSubject &instance();
    /**
     * @brief add signal handler to multicast
     * @param signal_handler
     */
    void registerSignalObserver(ISignalObserver& signal_observer);
    /**
     * @brief delete signal handler from multicast
     * @param signal_handler
     */
    void unregisterSignalObserver(ISignalObserver& signal_observer);

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
     * @brief deny copy constructor
     */
    g_SignalSubject(const g_SignalSubject&);
    /**
     * @brief deny operator =
     * @return
     */
    g_SignalSubject& operator=(const g_SignalSubject&);
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
     * @brief handlers list for signals multicast
     */
    list<ISignalObserver*> m_observers;
    /**
     * @brief mutex for lock singleton during signal processing
     */
    recursive_mutex m_lock;
};


} /* sys */


#endif // G_SIGNALMANAGER_H

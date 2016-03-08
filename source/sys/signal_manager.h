#ifndef G_SIGNALMANAGER_H
#define G_SIGNALMANAGER_H


#include <list>
#include <csignal>

#include "signal_handler.h"


using std::list;


namespace sys {


/**
 * @brief global signal handler and multicast to ISignalHandler's
 */
class g_SignalManager {
public:
    /**
     * @brief sigletone instance
     * @return
     */
    static g_SignalManager *instance();
    /**
     * @brief add signal handler to multicast
     * @param signal_handler
     */
    void addSignalHandler(ISignalHandler::WeakPtrT signal_handler);
    /**
     * @brief delete signal handler from multicast
     * @param signal_handler
     */
    void delSignalHandler(ISignalHandler::WeakPtrT signal_handler);

private:
    /**
     * @brief constructor g_SignalManager
     */
    g_SignalManager();
    /**
     * @brief destructor
     */
   ~g_SignalManager();
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
    static g_SignalManager *m_instance;
    /**
     * @brief handlers list for signals multicast
     */
    list<ISignalHandler::WeakPtrT> m_handlers;
};


} /* sys */


#endif // G_SIGNALMANAGER_H

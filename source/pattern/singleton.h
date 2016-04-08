//
// Created by volodja on 29.03.2016.
//

#ifndef WEBSOCKETPP_CHAT_SINGLETON_H
#define WEBSOCKETPP_CHAT_SINGLETON_H


namespace pattern {


template<typename T>
class CSingleton {
public:
    static T& instance();

protected:
    /**
     * default contructor
     */
    CSingleton() = default;
    /**
     * default destructor
     */
    virtual ~CSingleton() = default;

private:
    /**
     * delete copy constructor
     */
    CSingleton(CSingleton const&) = delete;
    /**
     * delete move constructor
     */
    CSingleton(CSingleton&&) = delete;
    /**
     * delete copy assign
     */
    CSingleton& operator=(CSingleton const&) = delete;
    /**
     * delete move assign
     */
    CSingleton& operator=(CSingleton&&) = delete;
};


template<typename T>
T& CSingleton<T>::instance() {
    /*
     * C++11:
     * §6.7 [stmt.dcl] p4
     * If control enters the declaration concurrently
     * while the variable is being initialized,
     * the concurrent execution shall wait for completion
     * of the initialization.
     */
    static T instance;
    return instance;
}


} /* pattern */


#endif //WEBSOCKETPP_CHAT_SINGLETON_H

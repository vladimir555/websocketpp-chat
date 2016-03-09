cmake_minimum_required(VERSION 2.8)
project(websocketpp-chat)

#BUILD
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin CACHE PATH "Single Directory for all")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin CACHE PATH "Single Directory for all")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib CACHE PATH "Single Directory for all")

add_compile_options("-std=c++11")
add_compile_options("-Wall")

file(GLOB_RECURSE SOURCE 
    ${CMAKE_SOURCE_DIR}/source/*.h 
    ${CMAKE_SOURCE_DIR}/source/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})

include_directories(${CMAKE_SOURCE_DIR}/source)

find_package(Boost COMPONENTS system REQUIRED)
#set(Poco_LIBRARIES libPocoFoundation.so libPocoUtil.so libPocoNet.so libPocoJSON.so)

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

#TEST
#enable_testing()
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})

#set(PROJECT_TEST_NAME ${PROJECT_NAME}-test)

# test .cpp file
#file(GLOB_RECURSE TEST_CPP test/*.cpp)

# source files for test
#file(GLOB_RECURSE SOURCE_TEST
#    ${CMAKE_SOURCE_DIR}/source/*.h
#    ${CMAKE_SOURCE_DIR}/source/*.h
#)

#add_executable(${PROJECT_TEST_NAME} ${TEST_CPP} ${SOURCE})

# Link test executable against gtest & gtest_main
#target_link_libraries(${PROJECT_TEST_NAME} ${Poco_LIBRARIES} ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY})

#add_test(NAME ${PROJECT_TEST_NAME} COMMAND ${PROJECT_TEST_NAME})

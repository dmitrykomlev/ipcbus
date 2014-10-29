cmake_minimum_required(VERSION 2.8.4)


SET(IPC_BUS_PROJECT_NAME ipcbus)
SET(IPC_BUS_TEST_PROJECT_NAME test)
project(${IPC_BUS_PROJECT_NAME})

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11 -Wall" )

#boost
set(Boost_DEBUG 1) 
SET(Boost_USE_STATIC_LIBS ON)
SET(Boost_USE_STATIC_RUNTIME ON)

find_package(Boost 1.52.0 COMPONENTS filesystem system )
if(NOT Boost_FOUND)
    message(SEND_ERROR "Failed to find boost libraries.")
    return()
else()
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
	LINK_DIRECTORIES(${LINK_DIRECTORIES} ${Boost_LIBRARY_DIRS})
endif()


subdirs(${IPC_BUS_PROJECT_NAME} ${IPC_BUS_TEST_PROJECT_NAME})

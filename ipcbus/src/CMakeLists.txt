cmake_minimum_required(VERSION 2.8.4)


include_directories(${CMAKE_SOURCE_DIR}/${IPC_BUS_PROJECT_NAME}/include)

set(SOURCE_IPCBUS ipc.cpp bus.cpp bus_impl.cpp bus_device.cpp)

add_library(${IPC_BUS_PROJECT_NAME} STATIC ${SOURCE_IPCBUS})

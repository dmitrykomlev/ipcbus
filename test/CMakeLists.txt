cmake_minimum_required(VERSION 2.8.4)

include_directories(${CMAKE_SOURCE_DIR}/${IPC_BUS_PROJECT_NAME}/include)

link_directories(${CMAKE_SOURCE_DIR}/IPC_BUS_PROJECT_NAME/src)

set(SOURCE_TEST test.cpp construct_test.cpp )

add_executable(${IPC_BUS_TEST_PROJECT_NAME} ${SOURCE_TEST})

target_link_libraries(${IPC_BUS_TEST_PROJECT_NAME} ${IPC_BUS_PROJECT_NAME}
					  ${Boost_LIBRARIES})

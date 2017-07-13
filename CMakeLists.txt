cmake_minimum_required(VERSION 3.5)
set(PROJECT_NAME pepper)

project(${PROJECT_NAME})

SET(EXE_NAME ${PROJECT_NAME}.fcgi)

set(CMAKE_BINARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/build")

set(CMAKE_CXX_FLAGS "-std=c++14 -W -Wall -Wextra --pedantic -Wno-comment -Wno-unused-variable")

if (CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g ")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 ")
endif (CMAKE_BUILD_TYPE MATCHES "Debug")


set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Module")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY /var/www/html/www.mydomain.com)

find_package(FCGI++ COMPONENTS test REQUIRED)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost 1.60.0 COMPONENTS system filesystem unit_test_framework REQUIRED)

file(GLOB_RECURSE SOURCE src/*.cpp src/*.h src/*.hpp)
set(SOURCE_FILES ${SOURCE})

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})

    add_executable(${EXE_NAME} main.cpp
            #${SOURCE_FILES}
            )
    target_link_libraries(${EXE_NAME} ${Boost_LIBRARIES} ${FCGI++_LIBRARIES})
endif()
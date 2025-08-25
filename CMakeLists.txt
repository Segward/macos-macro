cmake_minimum_required(VERSION 3.16)
project(macos-macro C)

find_library(APP_SERVICES ApplicationServices)
find_library(CARBON_FRAMEWORK Carbon)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(ac src/ac.c)
target_link_libraries(ac ${APP_SERVICES} ${CARBON_FRAMEWORK})

add_executable(lb src/lb.c)
target_link_libraries(lb ${APP_SERVICES} ${CARBON_FRAMEWORK})

add_executable(km src/km.c)
target_link_libraries(km ${APP_SERVICES} ${CARBON_FRAMEWORK})

add_executable(cf src/cf.c)
target_link_libraries(cf ${APP_SERVICES} ${CARBON_FRAMEWORK})

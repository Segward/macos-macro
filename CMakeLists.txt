cmake_minimum_required(VERSION 3.16)
project(macos-macro C)

find_library(APP_SERVICES ApplicationServices)
find_library(CARBON_FRAMEWORK Carbon)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(ac src/ac.c)
target_link_libraries(ac ${APP_SERVICES} ${CARBON_FRAMEWORK})

add_executable(macro src/macro.c)
target_link_libraries(macro ${APP_SERVICES} ${CARBON_FRAMEWORK})

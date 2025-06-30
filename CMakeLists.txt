cmake_minimum_required(VERSION 3.10)
project(MacMacro C)

set(CMAKE_C_STANDARD 11)

find_library(APP_SERVICES ApplicationServices)
find_library(CARBON_FRAMEWORK Carbon)

add_executable(app app.c)
target_link_libraries(app ${APP_SERVICES} ${CARBON_FRAMEWORK})

add_executable(macro macro.c)
target_link_libraries(macro ${APP_SERVICES} ${CARBON_FRAMEWORK})
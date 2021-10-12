cmake_minimum_required(VERSION 3.0)
cmake_policy(SET CMP0042 NEW)
set(CMAKE_CXX_STANDARD 11)

project(mainprogram)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(logger SHARED lib/src/logger.cpp)

add_executable (nodeExecuter main.cpp)

install(TARGETS logger DESTINATION /usr/lib)
install(FILES include/logger.h DESTINATION include)

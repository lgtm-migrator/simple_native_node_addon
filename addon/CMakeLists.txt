cmake_minimum_required(VERSION 3.0)
cmake_policy(SET CMP0042 NEW)
set(CMAKE_CXX_STANDARD 11)

project(addon)

find_package(Boost 1.53.0 COMPONENTS system REQUIRED)

include_directories(${CMAKE_JS_INC} ../include/)

set(SOURCE_FILES "src/addon.cpp")

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${CMAKE_JS_SRC})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")
target_link_directories(${PROJECT_NAME} PUBLIC "/home/developer/simple_native_node_addon/build")
target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB} ${Boost_LIBRARIES} "liblogger.so")

# Include Node-API wrappers
execute_process(COMMAND node -p "require('node-addon-api').include"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE NODE_ADDON_API_DIR
        )
message("dir: ${NODE_ADDON_API_DIR}")
string(REGEX REPLACE "[\r\n\"]" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})

target_include_directories(${PROJECT_NAME} PRIVATE ${NODE_ADDON_API_DIR})

# define NPI_VERSION
add_definitions(-DNAPI_VERSION=3)

cmake_minimum_required(VERSION 3.7)

project(cpp1)


set(CMAKE_INCLUDE_CURRENT_DIR TRUE)
#set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
LIST( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -Wall)

set(EXT_LIBS_PATH ${PROJECT_SOURCE_DIR}/ext-libs)


include(CTest)
enable_testing()
include(Catch)

include_directories(.)

set(MAIN_BIN_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

file(GLOB EXT_LIBS_HEADERS ${EXT_LIBS_PATH}/*.h*)

#add_library(grok_base ${BASE_SRC} ${EXT_LIBS_HEADERS})

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/cpp1/level1)

#add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/grok/asm)
#add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/grok/interp)

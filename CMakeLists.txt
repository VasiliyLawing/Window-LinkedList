cmake_minimum_required(VERSION 3.7)

project(cpp1)

include(cpp1-local.cmake)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_INCLUDE_CURRENT_DIR TRUE)
#set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
LIST( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )

include_directories(. ${ANYSOLO_LOCAL_INC})
link_directories( ${ANYSOLO_LOCAL_LIB})

set(CMAKE_CXX_STANDARD 20)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
set(CMAKE_CXX_FLAGS -Wall)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	set(CMAKE_CXX_FLAGS /EHsc)
else()
	message(FATAL_ERROR "Unsupported compiler")
endif()


set(EXT_LIBS_PATH ${PROJECT_SOURCE_DIR}/ext-libs)

enable_testing()
include(Catch)


set(MAIN_BIN_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(MAIN_LIB_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)


file(GLOB EXT_LIBS_HEADERS ${EXT_LIBS_PATH}/*.h*)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/vpc)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/cpp1/level1)

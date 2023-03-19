cmake_minimum_required(VERSION 3.7)

project(cpp1)

cmake_policy(SET CMP0135 NEW)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

if(Boost_FOUND)
	message(WARNING "BOOST FOUND")
	include_directories(${Boost_INCLUDE_DIRS})
	set(BOOST_LIBS ${Boost_LIBRARIES})
else()
	set(BOOST_LIBS )
	message(WARNING "BOOST NOT FOUND")
endif()

set(CMAKE_INCLUDE_CURRENT_DIR TRUE)
#set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
LIST( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )

include_directories(. ${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
set(CMAKE_CXX_FLAGS -Wall)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	set(CMAKE_CXX_FLAGS /EHsc)
else()
	message(FATAL_ERROR "Unsupported compiler")
endif()


set(EXT_LIBS_PATH ${PROJECT_SOURCE_DIR}/ext-libs)

include(CTest)
enable_testing()
include(Catch)


set(MAIN_BIN_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(MAIN_LIB_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)


file(GLOB EXT_LIBS_HEADERS ${EXT_LIBS_PATH}/*.h*)

add_subdirectory(boost-cmake)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/vpc)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/cpp1/level1)

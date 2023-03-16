project(level1)

set(ANYSOLO_ADD_LIBS "vpc ${SDL2_LIBRARIES} SDL2_image")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

#include_directories()

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/unit1)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/unit2)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/unit3)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/unit77)

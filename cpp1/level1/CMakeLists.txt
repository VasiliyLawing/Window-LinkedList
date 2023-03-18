project(level1)


find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_library(VPC_SDL_LIB SDL2 )
find_library(VPC_SDL_IMAGE_LIB SDL2_image )

set(VPC_ALL_LIBS vpc ${VPC_SDL_LIB} ${VPC_SDL_IMAGE_LIB})

set(ANYSOLO_ADD_LIBS ${VPC_ALL_LIBS})
link_directories(${MAIN_LIB_DIRECTORY})

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/unit1)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/unit2)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/unit3)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/unit77)

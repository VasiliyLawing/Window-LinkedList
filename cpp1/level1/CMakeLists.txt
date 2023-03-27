project(level1)

set(VPC_ALL_LIBS "vpc ${VPC_SDL_LIB} ${VPC_SDL_IMAGE_LIB}")

message("VPC LIB: ${VPC_SDL_IMAGE_LIB}")

set(ANYSOLO_ADD_LIBS ${VPC_ALL_LIBS})
link_directories(${MAIN_LIB_DIRECTORY})

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/unit1)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/unit2)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/unit3)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/unit77)

project(level1)

set(ANYSOLO_VPC_LIBS vpc SDL2 SDL2_image SDL2_ttf)


set(ANYSOLO_ADD_LIBS ${ANYSOLO_VPC_LIBS})
link_directories(${MAIN_LIB_DIRECTORY})

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/unit1)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/unit2)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/unit3)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/unit4)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/unit77)

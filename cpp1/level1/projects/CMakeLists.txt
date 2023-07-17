project(level1_projects)

set(ANYSOLO_VPC_LIBS vpc SDL2 SDL2_image SDL2_ttf)


set(ANYSOLO_ADD_LIBS ${ANYSOLO_VPC_LIBS})
link_directories(${MAIN_LIB_DIRECTORY})

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/tst)

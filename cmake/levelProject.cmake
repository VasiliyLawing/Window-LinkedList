string(REPLACE "/" ";" currentPathList ${CMAKE_CURRENT_SOURCE_DIR})
list(POP_BACK currentPathList ANYSOLO_UNIT)
list(POP_BACK currentPathList ANYSOLO_LEVEL)
set(ANYSOLO_VPC_LIBS vpc SDL2 SDL2_image SDL2_ttf)


set(ANYSOLO_ADD_LIBS ${ANYSOLO_VPC_LIBS})

file(GLOB APP_SOURCES *.c* *.h*)
message(FATAL "Sources: ${APP_SOURCES}")
set(targetName "${ANYSOLO_LEVEL}_projects_${PROJECT_NAME}")
message(FATAL ${targetName})

add_executable( ${targetName} ${APP_SOURCES})

target_link_libraries(${targetName} PUBLIC ${ANYSOLO_ADD_LIBS})
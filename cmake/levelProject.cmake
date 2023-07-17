string(REPLACE "/" ";" currentPathList ${CMAKE_CURRENT_SOURCE_DIR})
list(POP_BACK currentPathList ANYSOLO_UNIT)
list(POP_BACK currentPathList ANYSOLO_LEVEL)


file(GLOB APP_SOURCES *.c* *.h*)
add_executable( ${ANYSOLO_LEVEL}_projects_${PROJECT_NAME} ${APP_SOURCES} )

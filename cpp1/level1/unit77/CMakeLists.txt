project(level1)

set(ANYSOLO_LEVEL 1)
set(ANYSOLO_UNIT 77)
#set(ANYSOLO_UNIT_LIB 1)


set(artifactPrefix "level1_unit77")
set(unitDir ${CMAKE_CURRENT_LIST_DIR})
set(unitNoTests 1)
#set(ANYSOLO_BINARY_TASKS 1)

include(unit)

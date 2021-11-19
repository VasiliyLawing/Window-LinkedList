project(level1)

file(GLOB SRC tasks/*.cc tasks/*.hh)
add_library(cpp1_level1_unit1 ${SRC} ${EXT_LIBS_HEADERS})

file(GLOB TESTS_SRC tests/*.cc tests/*.hh)
add_executable(cpp1_level1_unit1_tests ${TESTS_SRC})
target_link_libraries(cpp1_level1_unit1_tests PUBLIC cpp1_level1_unit1)

catch_discover_tests(cpp1_level1_unit1_tests)

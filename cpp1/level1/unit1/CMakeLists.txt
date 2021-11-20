project(level1)

add_executable(cpp1_level1_unit1_e1 examples/e1.cc)


file(GLOB SRC tasks/*.cc tasks/*.hh)
add_library(cpp1_level1_unit1 ${SRC} ${EXT_LIBS_HEADERS})

add_executable(cpp1_level1_unit1_tests testsMain.cc)
target_link_libraries(cpp1_level1_unit1_tests PUBLIC cpp1_level1_unit1)

catch_discover_tests(cpp1_level1_unit1_tests)

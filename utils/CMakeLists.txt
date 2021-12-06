project(utils)

file(GLOB SRC *.cc *.hh)
add_library(anysolo_course_utils ${SRC} ${EXT_LIBS_HEADERS})


file(GLOB TEST_SRC tests/*.cc tests/*.hh)
add_executable(anysolo_course_utils_tests ${TEST_SRC})
target_link_libraries(anysolo_course_utils_tests PUBLIC anysolo_course_utils Boost::boost pthread)

catch_discover_tests(anysolo_course_utils_tests)

project(level1)


# file( GLOB APP_SOURCES RELATIVE app/*.cxx )
file( GLOB EXAMPLE_SOURCES RELATIVE ${CMAKE_CURRENT_LIST_DIR}/examples examples/*.cc )
foreach( afile ${EXAMPLE_SOURCES} )
    string( REPLACE ".cc" "" binaryName ${afile} )
    add_executable( ${binaryName} examples/${afile} )
endforeach( afile ${EXAMPLE_SOURCES} )


file(GLOB SRC tasks/*.cc tasks/*.hh)
add_library(cpp1_level1_unit2 ${SRC} ${EXT_LIBS_HEADERS})

add_executable(cpp1_level1_unit2_tests testsMain.cc)
target_link_libraries(cpp1_level1_unit2_tests PUBLIC cpp1_level1_unit2)

catch_discover_tests(cpp1_level1_unit2_tests)

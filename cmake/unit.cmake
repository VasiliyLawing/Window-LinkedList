file( GLOB EXAMPLE_SOURCES RELATIVE ${unitDir}/examples examples/*.cc )
foreach( afile ${EXAMPLE_SOURCES} )
    string( REPLACE ".cc" "" binaryName ${afile} )
    add_executable( ${artifactPrefix}_${binaryName} examples/${afile} )
endforeach( afile ${EXAMPLE_SOURCES} )


file(GLOB SRC examples/*cc tasks/*.cc tasks/*.hh)
add_library(${artifactPrefix} ${SRC} ${EXT_LIBS_HEADERS})


if(DEFINED ANYSOLO_BINARY_TASKS)
    file( GLOB TASKS_SOURCES RELATIVE ${unitDir}/tasks tasks/*.cc )

    foreach( afile ${TASKS_SOURCES} )
        string( REPLACE ".cc" "" binaryName ${afile} )
        add_executable( ${artifactPrefix}_${binaryName} tasks/${afile} )
    endforeach( afile ${TASKS_SOURCES} )
endif()


if(NOT DEFINED unitNoTests)
    add_executable(${artifactPrefix}_tests testsMain.cc)
    target_link_libraries(${artifactPrefix}_tests PUBLIC ${artifactPrefix})

    catch_discover_tests(${artifactPrefix}_tests)
endif()

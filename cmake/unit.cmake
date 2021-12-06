file( GLOB EXAMPLE_SOURCES RELATIVE ${unitDir}/examples examples/*.cc )
foreach( afile ${EXAMPLE_SOURCES} )
    string( REPLACE ".cc" "" exampleName ${afile} )
    set(fullExampleName level${ANYSOLO_LEVEL}_unit${ANYSOLO_UNIT}_${exampleName})

    add_executable( ${fullExampleName} examples/${afile} )
    set_target_properties(${fullExampleName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/examples" )
    set_target_properties(${fullExampleName} PROPERTIES RUNTIME_OUTPUT_NAME "${exampleName}" )
endforeach( afile ${EXAMPLE_SOURCES} )


file(GLOB SRC examples/*cc tasks/*.cc tasks/*.hh)
add_library(${artifactPrefix} ${SRC} ${EXT_LIBS_HEADERS})


if(DEFINED ANYSOLO_BINARY_TASKS)
    file( GLOB TASKS_SOURCES RELATIVE ${unitDir}/tasks tasks/*.cc )

    foreach( afile ${TASKS_SOURCES} )
        string( REPLACE ".cc" "" taskName ${afile} )
        set(fullTaskName level${ANYSOLO_LEVEL}_unit${ANYSOLO_UNIT}_${taskName})

        add_executable( ${fullTaskName} tasks/${afile} )
        set_target_properties(${fullTaskName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/tasks" )
        set_target_properties(${fullTaskName} PROPERTIES RUNTIME_OUTPUT_NAME "${taskName}" )
    endforeach( afile ${TASKS_SOURCES} )
endif()


if(NOT DEFINED unitNoTests)
    add_executable(${artifactPrefix}_tests testsMain.cc)
    target_link_libraries(${artifactPrefix}_tests PUBLIC ${artifactPrefix})

    catch_discover_tests(${artifactPrefix}_tests)
endif()

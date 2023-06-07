string(REPLACE "/" ";" currentPathList ${CMAKE_CURRENT_SOURCE_DIR})


list(POP_BACK currentPathList ANYSOLO_UNIT)
list(POP_BACK currentPathList ANYSOLO_LEVEL)

set(artifactPrefix "${ANYSOLO_LEVEL}_${ANYSOLO_UNIT}")


if(DEFINED ANYSOLO_UNIT_LIB)
    file(GLOB LIB_SRC RELATIVE ${unitDir} ${unitDir}/lib/*.hh ${unitDir}/lib/*.cc)
    add_library(${artifactPrefix} ${LIB_SRC} ${EXT_LIBS_HEADERS} ../cpp1/level1/unit77/tasks/t1.cc)
    set_target_properties(${artifactPrefix} PROPERTIES LINKER_LANGUAGE CXX)
endif()

file( GLOB EXAMPLE_SOURCES RELATIVE ${unitDir}/examples examples/*.cc )
foreach( afile ${EXAMPLE_SOURCES} )
    string( REPLACE ".cc" "" exampleName ${afile} )
    set(fullTargetName level${ANYSOLO_LEVEL}_unit${ANYSOLO_UNIT}_${exampleName})

    add_executable( ${fullTargetName} examples/${afile} )

    if(DEFINED ANYSOLO_UNIT_LIB)
        target_link_libraries(${fullTargetName} PUBLIC ${artifactPrefix} ${ANYSOLO_ADD_LIBS})
    else()
        target_link_libraries(${fullTargetName} PUBLIC ${ANYSOLO_ADD_LIBS})
    endif()

    set_target_properties(${fullTargetName} PROPERTIES RUNTIME_OUTPUT_NAME "${exampleName}" )
endforeach( afile ${EXAMPLE_SOURCES} )


file( GLOB TASK_SOURCES RELATIVE ${unitDir}/tasks tasks/*.cc )
message(TASKS: ${TASK_SOURCES})
foreach( afile ${TASK_SOURCES} )
    string( REPLACE ".cc" "" taskName ${afile} )
    set(fullTargetName level${ANYSOLO_LEVEL}_unit${ANYSOLO_UNIT}_${taskName})

    add_executable( ${fullTargetName} tasks/${afile} )

    if(DEFINED ANYSOLO_UNIT_LIB)
        target_link_libraries(${fullTargetName} PUBLIC ${artifactPrefix} ${ANYSOLO_ADD_LIBS})
    else()
        target_link_libraries(${fullTargetName} PUBLIC ${ANYSOLO_ADD_LIBS})
    endif()

    set_target_properties(${fullTargetName} PROPERTIES RUNTIME_OUTPUT_NAME "${taskName}" )
endforeach( afile ${TASK_SOURCES} )


#if(DEFINED ANYSOLO_BINARY_TASKS)
#    file( GLOB TASKS_SOURCES RELATIVE ${unitDir}/tasks tasks/*.cc )
#
#    foreach( afile ${TASKS_SOURCES} )
#        string( REPLACE ".cc" "" taskName ${afile} )
#        set(fullTargetName level${ANYSOLO_LEVEL}_unit${ANYSOLO_UNIT}_${taskName})
#           
#        add_executable( ${fullTargetName} tasks/${afile} )
#        target_link_libraries(${fullTargetName} PUBLIC ${artifactPrefix})
#        set_target_properties(${fullTargetName} PROPERTIES RUNTIME_OUTPUT_NAME "${taskName}" )
#    endforeach( afile ${TASKS_SOURCES} )
#endif()


if(NOT DEFINED unitNoTests)
    file( GLOB TEST_SOURCES RELATIVE ${unitDir}/tests tests/*.cc )
    file( GLOB TEST_LIB_SOURCES RELATIVE ${unitDir} tests/lib/*.cc tests/lib/*.hh)

    foreach( afile ${TEST_SOURCES} )
        string( REPLACE "Tests.cc" ".cc" taskFileName ${afile} )

#        message(WARNING ${PROJECT_SOURCE_DIR}/tasks/${taskFileName})
        if(EXISTS ${PROJECT_SOURCE_DIR}/tasks/${taskFileName})
            string( REPLACE ".cc" "" testName ${afile} )
            set(fullTargetName level${ANYSOLO_LEVEL}_unit${ANYSOLO_UNIT}_${testName})
            add_executable(${fullTargetName} tests/${afile} tasks/${taskFileName} ${TEST_LIB_SOURCES})
            set_target_properties(${fullTargetName} PROPERTIES RUNTIME_OUTPUT_NAME "${testName}" )
            target_link_libraries(${fullTargetName} PUBLIC ${artifactPrefix})

        endif()
    endforeach( afile ${TEST_SOURCES} )
endif()

cmake_minimum_required(VERSION 3.7)

project(vpc)


find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(SDL2_IMAGE REQUIRED)


file(GLOB LIB_SRC RELATIVE ${PROJECT_SOURCE_DIR} *.hh *.cc)
add_library(vpc ${LIB_SRC} ${EXT_LIBS_HEADERS})
set_target_properties(vpc PROPERTIES LINKER_LANGUAGE CXX)


file( GLOB EXAMPLE_SOURCES RELATIVE ${PROJECT_SOURCE_DIR}/examples examples/*.cc )

message(${EXAMPLE_SOURCES})

foreach( afile ${EXAMPLE_SOURCES} )
	string( REPLACE ".cc" "" exampleName ${afile} )
	set(fullTargetName vpc_${exampleName})

	add_executable( ${fullTargetName} examples/${afile} )
	target_link_libraries(${fullTargetName} vpc ${SDL2_LIBRARIES} SDL2_image)

#		target_link_libraries(${fullTargetName} PUBLIC ${artifactPrefix})

	set_target_properties(${fullTargetName} PROPERTIES RUNTIME_OUTPUT_NAME "${exampleName}" )
endforeach( afile ${EXAMPLE_SOURCES} )

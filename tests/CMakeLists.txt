project(Engine_TESTS)
cmake_minimum_required(VERSION 2.8.12)

# Variable definitions
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
set (SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set (CMAKE_CXX_STANDARD 17)

# Engine dependency
set(RESOURCES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/resources" CACHE PATH "Resources Path" FORCE)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/.." "${CMAKE_BINARY_DIR}/EngineBuild")

# Source gathering
file(GLOB_RECURSE SOURCES
		"${SOURCE_DIR}/*.cpp" "${SOURCE_DIR}/*.c"
		"${SOURCE_DIR}/*.hpp" "${SOURCE_DIR}/*.h")

# Make library
add_executable(Engine_TESTS ${SOURCES})

target_link_libraries(Engine_TESTS Engine_Static )

# Include directotories
target_include_directories(Engine_TESTS PUBLIC ${SOURCE_DIR})

# Copy resources to build dir
add_custom_command(TARGET Engine_TESTS POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory ${RESOURCES_DIR} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources)
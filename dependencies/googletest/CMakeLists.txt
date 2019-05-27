# Download and unpack gtest at configure time
message(STATUS " ------> 1")
configure_file(CMakeLists.txt.in gtest-download/CMakeLists.txt)
message(STATUS " ------> 2")
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
                RESULT_VARIABLE result
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/gtest-download )
message(STATUS " ------> 3")
if(result)
  message(FATAL_ERROR "CMake step for gtest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
                RESULT_VARIABLE result
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/gtest-download )
message(STATUS " ------> 4")
if(result)
  message(FATAL_ERROR "Build step for gtest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
message(STATUS " ------> 5")

# Add gtest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/gtest
                 ${CMAKE_CURRENT_BINARY_DIR}/gtest-build
                 EXCLUDE_FROM_ALL)
message(STATUS " ------>6")
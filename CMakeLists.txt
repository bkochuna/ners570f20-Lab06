cmake_minimum_required(VERSION 2.8.12)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(ners570_SpMV CXX)
message("C++ compiler flags: ${CMAKE_CXX_FLAGS}")

set(SpMV_MAJOR_VERSION 0)
set(SpMV_MINOR_VERSION 0)
set(SpMV_PATCH_VERSION 0)

set(SpMV_VERSION ${SpMV_MAJOR_VERSION}.${SpMV_MINOR_VERSION}.${SpMV_PATCH_VERSION})

add_subdirectory(src)

enable_testing()
add_subdirectory(test)

list(APPEND flags "-fPIC" "-Wall")
if(NOT WIN32)
  list(APPEND flags "-Wextra" "-Wpedantic")
endif()

set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS_DEBUG   "-g -traceback")
set(CMAKE_CXX_FLAGS_RELEASE "-03 -ip xHOST")

if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    list(APPEND CMAKE_CXX_FLAGS "-fno-rtti" "-fno-exceptions")
    list(APPEND CMAKE_CXX_FLAGS_DEBUG "Wsuggest-final-types" "Wsuggest-final-methods" "-Wsuggest-override")
    list(APPEND CMAKE_CXX_FLAGS_RELEASE "-03" "-Wno-unused")
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES Clang)  
  list(APPEND CXX_FLAGS "-fno-rtti" "-fno-exceptions" "-Qunused-arguments" "-fcolor-diagnostics")
  list(APPEND CXX_FLAGS_DEBUG "-Wdocumentation")
  list(APPEND CXX_FLAGS_RELEASE "-O3" "-Wno-unused")
endif()

SET(CMAKE_BUILD_TYPE "Debug")

if (NOT CMAKE_BUILD_TYPE)
	message(STATUS "No build type selected, default to Release")
	set(CMAKE_BUILD_TYPE "Release")
endif()

# target_compile_option(ners570_SpMV
#   PRIVATE
#     ${CXX_FLAGS}
#     "$<$<CONFIG:Debug>:${CXX_FLAGS_DEBUG}>"
#     "$<$<CONFIG:Release>:${CXX_FLAGS_RELEASE}>"
#   )

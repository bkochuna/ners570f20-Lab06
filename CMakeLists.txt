cmake_minimum_required(VERSION 2.8.12)

project(ners570_SpMV CXX)

set(SpMV_MAJOR_VERSION 0)
set(SpMV_MINOR_VERSION 0)
set(SpMV_PATCH_VERSION 0)

set(SpMV_VERSION ${SpMV_MAJOR_VERSION}.${SpMV_MINOR_VERSION}.${SpMV_PATCH_VERSION})


add_subdirectory(src)

add_subdirectory(test)


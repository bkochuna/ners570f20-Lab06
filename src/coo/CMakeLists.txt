include_directories(${PROJECT_SOURCE_DIR}/src)

set(SOURCES COOsparsemat.cpp)
add_library(coo ${SOURCES})

include_directories(${PROJECT_SOURCE_DIR}/src)

set(SOURCES ellsparsemat.cpp)
add_library(ell ${SOURCES})

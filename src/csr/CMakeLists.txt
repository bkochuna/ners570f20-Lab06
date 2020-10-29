include_directories(${PROJECT_SOURCE_DIR}/src)

set(SOURCES csrsparsemat.cpp)
add_library(csr ${SOURCES})

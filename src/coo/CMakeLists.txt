include_directories(${PROJECT_SOURCE_DIR}/src)

set(COOsource COOsparsemat.cpp)
add_library(coo ${COOsource})

include_directories(${PROJECT_SOURCE_DIR}/src)

set(SOURCES coosparsemat.cpp)
add_library(coo ${SOURCES})

include_directories(${PROJECT_SOURCE_DIR}/src)

set(SOURCES coosparsemat.cpp)

target_link_libraries(${SOURCES} SpMV)



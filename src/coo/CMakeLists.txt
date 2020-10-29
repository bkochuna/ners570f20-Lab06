include_directories(${PROJECT_SOURCE_DIR}/src)

set(SOURCES coosparsemat)

add_executable(${SOURCES} ${SOOURCES}.cpp)
target_link_libraries(${SOURCES} SpMV)

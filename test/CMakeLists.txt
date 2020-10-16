include_directories(${PROJECT_SOURCE_DIR}/src)

set(TESTNAME testSparseMatrix)

add_executable(${TESTNAME} ${TESTNAME}.cpp)
target_link_libraries(${TESTNAME} SpMV)

add_test(${TESTNAME} ${TESTNAME})

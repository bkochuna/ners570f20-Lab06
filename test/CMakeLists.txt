include_directories(${PROJECT_SOURCE_DIR}/src)

set(TESTNAME testSparseMatrix)
set(TESTNAME_COO testCOOSparseMatrix)

add_executable(${TESTNAME} ${TESTNAME}.cpp)
target_link_libraries(${TESTNAME} SpMV)

add_test(${TESTNAME} ${TESTNAME})

add_executable(${TESTNAME_COO} ${TESTNAME_COO}.cpp)
target_link_libraries(${TESTNAME_COO} SpMV)

add_test(${TESTNAME_COO} ${TESTNAME_COO})



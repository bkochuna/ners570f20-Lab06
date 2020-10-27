include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/src/csr)

set(TESTNAME testSparseMatrix)

add_executable(${TESTNAME} ${TESTNAME}.cpp)
target_link_libraries(${TESTNAME} SpMV )
add_executable(csrTest csrTest.cpp)
target_link_libraries(csrTest SpMV csr)

add_test(${TESTNAME} ${TESTNAME})
add_test(csrTest csrTest)

include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/src/csr)

set(TESTNAME testSparseMatrix)

add_executable(${TESTNAME} ${TESTNAME}.cpp)
target_link_libraries(${TESTNAME} SpMV )
add_executable(csrTest csrTest.cpp)
target_link_libraries(csrTest SpMV csr)
add_executable(cscTest cscTest.cpp)
target_link_libraries(cscTest SpMV csc)

add_test(${TESTNAME} ${TESTNAME})
add_test(csrTest csrTest)
add_test(cscTest cscTest)

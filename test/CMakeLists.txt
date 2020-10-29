include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/src/coo)
include_directories(${PROJECT_SOURCE_DIR}/src/csc)
include_directories(${PROJECT_SOURCE_DIR}/src/csr)
include_directories(${PROJECT_SOURCE_DIR}/src/ell)

set(TESTNAME testSparseMatrix)
add_executable(${TESTNAME} ${TESTNAME}.cpp)
target_link_libraries(${TESTNAME} SpMV )
add_test(${TESTNAME} ${TESTNAME})

add_executable(csrTest csrTest.cpp)
target_link_libraries(csrTest SpMV)
add_test(csrTest csrTest)

add_executable(cscTest cscTest.cpp)
target_link_libraries(cscTest SpMV)
add_test(cscTest cscTest)

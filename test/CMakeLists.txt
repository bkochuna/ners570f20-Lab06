include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/src/csc)

set(TESTNAME testSparseMatrix)

add_executable(${TESTNAME} ${TESTNAME}.cpp)
target_link_libraries(${TESTNAME} SpMV)
add_executable(cscTest cscTest.cpp)
target_link_libraries(cscTest SpMV csc)

add_test(${TESTNAME} ${TESTNAME})
add_test(cscTest cscTest)

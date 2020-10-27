include_directories(${PROJECT_SOURCE_DIR}/src)
<<<<<<< HEAD
include_directories(${PROJECT_SOURCE_DIR}/src/csr)
=======
include_directories(${PROJECT_SOURCE_DIR}/src/csc)
>>>>>>> 5710149469d4fd78c0926c19d673bfcd0e5c4849

set(TESTNAME testSparseMatrix)

add_executable(${TESTNAME} ${TESTNAME}.cpp)
<<<<<<< HEAD
target_link_libraries(${TESTNAME} SpMV )
add_executable(csrTest csrTest.cpp)
target_link_libraries(csrTest SpMV csr)

add_test(${TESTNAME} ${TESTNAME})
add_test(csrTest csrTest)
=======
target_link_libraries(${TESTNAME} SpMV)
add_executable(cscTest cscTest.cpp)
target_link_libraries(cscTest SpMV csc)

add_test(${TESTNAME} ${TESTNAME})
add_test(cscTest cscTest)
>>>>>>> 5710149469d4fd78c0926c19d673bfcd0e5c4849

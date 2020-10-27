set(SOURCES
  sparsemat.cpp
)

<<<<<<< HEAD
add_subdirectory(csr)
=======
add_subdirectory(csc)
>>>>>>> 5710149469d4fd78c0926c19d673bfcd0e5c4849
add_library(SpMV ${SOURCES} )

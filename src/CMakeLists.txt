set(SOURCES
  sparsemat.cpp
)

add_subdirectory(csr)
add_subdirectory(csc)

add_library(SpMV ${SOURCES} )

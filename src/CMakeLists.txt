set(SOURCES
  sparsemat.cpp
)

add_subdirectory(csr)
add_library(SpMV ${SOURCES} )

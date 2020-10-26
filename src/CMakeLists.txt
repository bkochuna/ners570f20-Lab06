set(SOURCES
  sparsemat.cpp
)

add_subdirectory(csc)
add_library(SpMV ${SOURCES} )

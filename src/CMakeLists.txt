set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES}
        PolynomialUI.h
        PolynomialUI.cpp)

add_executable(${BINARY}_run ${SOURCES})
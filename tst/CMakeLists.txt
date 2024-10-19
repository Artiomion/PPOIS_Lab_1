set(BINARY ${CMAKE_PROJECT_NAME}_tst)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES}
        PolynomialFunctionTest.cpp
)

add_test(NAME ${BINARY} COMMAND ${BINARY})
message(STATUS "Test sources: ${TEST_SOURCES}")

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)
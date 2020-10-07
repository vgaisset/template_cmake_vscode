cmake_minimum_required(VERSION 3.1)

set(TESTS_EXECUTABLE ${PROJECT_NAME}_tests)

add_executable(${TESTS_EXECUTABLE} src/MyTest.cpp)
set_target_properties(${TESTS_EXECUTABLE} PROPERTIES
    CXX_STANDARD_REQUIRED ON
    CXX_STANDARD          17
)
add_test(${TESTS_EXECUTABLE} ${TESTS_EXECUTABLE})

target_link_libraries(${TESTS_EXECUTABLE} ${PROJECT_LIBRARY})

target_include_directories(${TESTS_EXECUTABLE} PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/external/>
    $<INSTALL_INTERFACE:external/>
)

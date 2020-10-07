cmake_minimum_required(VERSION 3.1)

option(BUILD_TESTING "Should tests be built?" ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Used for clangd tooling

project(MyProject CXX)

set(PROJECT_LIBRARY ${PROJECT_NAME}_lib)
add_library(${PROJECT_LIBRARY} STATIC 
    src/MyClass.cpp 
    include/MyClass.hpp
)
set_target_properties(${PROJECT_LIBRARY} PROPERTIES
    CXX_STANDARD_REQUIRED ON
    CXX_STANDARD          17
)
target_include_directories(${PROJECT_LIBRARY} PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
    $<INSTALL_INTERFACE:include/>
)

add_executable(${PROJECT_NAME} src/main.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD_REQUIRED ON
    CXX_STANDARD          17
)
target_link_libraries(${PROJECT_NAME} ${PROJECT_LIBRARY})

if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()
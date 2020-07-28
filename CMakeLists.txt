cmake_minimum_required(VERSION 3.7.0)
project(sci-type-lib)

include(CTest)

add_library(sci-type-lib INTERFACE)
target_include_directories(sci-type-lib INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/mylib>)

if(BUILD_TESTING)
    add_executable(sci-quantity-test test/sci-quantity-test.cpp)
    target_link_libraries(sci-quantity-test sci-type-lib)
    
    add_executable(sci-unit-test test/sci-unit-test.cpp)
    target_link_libraries(sci-unit-test sci-type-lib)

    add_executable(sci-scale-test test/sci-scale-test.cpp)
    target_link_libraries(sci-scale-test sci-type-lib)

    add_test(
        NAME sci-quantity-test
        COMMAND sci-quantity-test)

    add_test(
        NAME sci-scale-test
        COMMAND sci-scale-test)
    
    add_test(
        NAME sci-unit-test
        COMMAND sci-unit-test)
endif()
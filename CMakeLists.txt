cmake_minimum_required(VERSION 3.14)
project(PolynomialProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(googletest)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_executable(laba 
    main.cpp 
    polynomial.cpp 
    polynomial.h
)

add_executable(run_tests 
    tests.cpp 
    polynomial.cpp 
    polynomial.h
)

target_link_libraries(run_tests 
    PRIVATE 
    gtest 
    gtest_main
)



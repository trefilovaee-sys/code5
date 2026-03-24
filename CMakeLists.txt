cmake_minimum_required(VERSION 3.10.0)
project(lab5 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab5 
    main.cpp 
    long_arithmetic.cpp 
    division.cpp 
    exceptions.cpp
)
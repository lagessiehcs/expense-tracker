cmake_minimum_required(VERSION 3.13)
project(ExpenseTracker VERSION 0.1.0 LANGUAGES CXX)

# Add main executable
add_executable(ExpenseTracker main.cpp) 

# Include subdirectories
add_subdirectory(Objects)
add_subdirectory(States)
add_subdirectory(Tasks)

target_compile_features(ExpenseTracker PUBLIC cxx_std_17)
set (CMAKE_CXX_FLAGS "-O3")
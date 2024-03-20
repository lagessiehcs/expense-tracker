cmake_minimum_required(VERSION 3.1)
project(ExpenseTracker VERSION 0.1.0 LANGUAGES CXX)
add_executable(ExpenseTracker main.cpp backend.cpp auto_generate.cpp printers.cpp Expense.cpp Group.cpp User.cpp get_input.cpp States/State.cpp States/States.cpp) 
cmake_minimum_required(VERSION 3.25)
project(Cafe)

set(CMAKE_CXX_STANDARD 17)

add_executable(Cafe main.cpp "Order.h" "Pizzas.h" "Drinks.h" "Menu.h" "ConsoleOut.h")

cmake_minimum_required(VERSION 3.16)
project(HelloQt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Generates the compile_commands.json file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# QT stuff
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_subdirectory(src/math)

qt_add_executable(HelloQt
  src/main.cpp
  src/gui/mainwindow.cpp
  src/gui/mainwindow.h
)

# Files under src/ included
target_include_directories(HelloQt PRIVATE src)

# Link QT and calc
target_link_libraries(HelloQt PRIVATE Qt6::Widgets calc)

add_executable(test_calc tests/test_calc.cpp)
target_link_libraries(test_calc PRIVATE calc)

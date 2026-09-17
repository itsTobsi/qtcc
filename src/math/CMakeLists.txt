
add_library(calc
  calculator.cpp
  calculator.h
)

target_include_directories(calc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

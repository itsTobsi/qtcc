#include "calculator.h"
#include <iostream>

int main(int argc, char *argv[]) {
  int numb1 = 10, numb2 = 5;

  std::cout << "2 + 3 = " << calc::add(2, numb2) << "\n";
  std::cout << "10 - 5 = " << calc::subtract(numb1, numb2) << "\n";
  std::cout << "10 * 5 = " << calc::multiply(numb1, numb2) << "\n";
  std::cout << "10 / 2 = " << calc::divide(numb1, 2) << "\n";

  // Try div by 0
  try {
    calc::divide(1, 0);
  } catch (const std::exception &ex) {
    std::cout << "divide(1,0) threw: " << ex.what() << "\n";
  }

  std::cout << "SQRT of 10 = " << calc::squareRoot(numb1) << "\n";

  return 0;
}

#include "calculator.h"
#include <stdexcept>

namespace calc {
double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }

double divide(double a, double b) {
  if (b == 0.0)
    throw std::domain_error("Cannot divide by zero");
  return a / b;
}
} // namespace calc

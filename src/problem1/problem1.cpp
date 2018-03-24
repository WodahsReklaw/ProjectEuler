// problem1.cpp
//
// Daniel Coelho
//
// Multiples of 3 and 5
// Problem 1
// If we list all the natural numbers below 10
// that are multiples of 3 or 5, we get 3, 5, 6 and 9.
// The sum of these multiples is 23.

// Find the sum of all the multiples of 3 or 5 below 1000.
#include <cstdlib>
#include <iostream>

unsigned MultiFiveSix(unsigned limit) {

  unsigned result = 0;
  for (unsigned i = 3; i < limit; i += 3) {
    result += i;
  }
  for (unsigned j = 5; j < limit; j += 5) {
    if (j%3 == 0) {
      continue;
    }
    result += j;
  }
  return result;
}

int main(int argc, char** argv){

  int limit;
  if (argc == 2) {
    limit = std::atoi(argv[1]);
  } else {
    std::cin >> limit;
  }
  std::cout << MultiFiveSix(limit) << std::endl;
}

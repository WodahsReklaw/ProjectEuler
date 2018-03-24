// problem2.cpp
// Daniel Coelho

// Problem 2
// Each new term in the Fibonacci sequence is
// generated by adding the previous two terms.
// By starting with 1 and 2, the first 10 terms will be:
//   1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
//
//  By considering the terms in the Fibonacci sequence
// whose values do not exceed four million, find the sum
// of the even-valued terms.
#include <cstdlib>
#include <iostream>

unsigned EvenFibSum(unsigned limit) {
  unsigned sum = 0;
  unsigned fibM = 1;
  unsigned fibN = 2;
  unsigned tmp;
  while (fibN < limit) {
    if (fibN%2 == 0) {
      sum += fibN;
    }
    tmp = fibN;
    fibN += fibM;
    fibM = tmp;
  }
  return sum;
}

int main(int argc, char** argv){

  int limit;
  if (argc == 2) {
    limit = std::atoi(argv[1]);
  } else {
    std::cin >> limit;
  }
  std::cout << EvenFibSum(limit) << std::endl;
}

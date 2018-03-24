// problem3.cpp
//
// Daniel Coelho
//
// Largest prime factor
// Problem 3
//   The prime factors of 13195 are 5, 7, 13 and 29.
//
//   What is the largest prime factor of the number 600851475143 ?

#include <cmath>
#include <cstdlib>
#include <cstdint>
#include <iostream>

#include <primes.h>

typedef std::uint_least64_t uint64;


uint64 LargestPrimeFactor(uint64 n) {
  uint64 sqrt = std::ceil(std::sqrt(n));
  PrimeGen prime_gen(sqrt-1,
                     [&n](uint64 p) -> uint64 {return ((n%p) == 0) ? p : 0;});
  const auto primes = prime_gen.getPrimes();
  for (const auto& prime : primes) {
    while (n%prime == 0) {
      n /= prime;
    }
    if (n == 1) {
      return prime;
    }
  }
  return n;
}

int main(int argc, char** argv){

  uint64 n;
  if (argc == 2) {
    n = std::atol(argv[1]);
  } else {
    std::cin >> n;
  }
  std::cout << LargestPrimeFactor(n) << std::endl;
}

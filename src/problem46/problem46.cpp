// Problem 46 It was proposed by Christian Goldbach that every odd
// composite number can be written as the sum of a prime and twice a
// square.

// 9 = 7 + 2×12 15 = 7 + 2×22 21 = 3 + 2×32 25 = 7 + 2×32 27 = 19 +
//   2×22 33 = 31 + 2×12

//   It turns out that the conjecture was false.

//   What is the smallest odd composite that cannot be written as the
//   sum of a prime and twice a square?

#include <iostream>
#include <cstdint>
#include <unordered_set>

#include "primes.h"

const long MAX_LIMIT = 10000;

typedef std::uint_least64_t uint64t;

using std::unordered_set;
using std::vector;

void Solution(){
  vector<uint64t> primes = PrimeGen(MAX_LIMIT).getPrimes();
  std::cout << "Generated primes." << std::endl;
  primes.insert(primes.begin(), 2);
  primes.insert(primes.begin(), 1);
  unordered_set<uint64t> some_odds;

  for (const auto& p : primes) {
    some_odds.emplace(p);
    for (uint64t q = 1; q*q < MAX_LIMIT; ++q) {
      some_odds.emplace(p + 2*q*q);
    }
  }
  for (uint64t i = 15; i < MAX_LIMIT; i += 2) {
    if (some_odds.find(i) == some_odds.end()) {
      std::cout << i << std::endl;
      return;
    }
  }
  std::cout << "No counter-examples found." << std::endl;
}

int main() {
  Solution();
  return 0;
}

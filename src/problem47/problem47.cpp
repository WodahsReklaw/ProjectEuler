// Distinct primes factors Problem 47 The first two consecutive
// numbers to have two distinct prime factors are:

// 14 = 2 × 7 15 = 3 × 5

//   The first three consecutive numbers to have three distinct prime
//   factors are:

//   644 = 2² × 7 × 23 645 = 3 × 5 × 43 646 = 2 × 17 × 19.

//   Find the first four consecutive integers to have four distinct
//   prime factors each. What is the first of these numbers?

#include <cstdint>
#include <cmath>
#include <iostream>
#include <iterator>
#include <list>
#include <unordered_set>
#include <vector>

#include "primes.h"

typedef std::uint_least64_t uint64t;
typedef std::unordered_set<uint64t> factor_set;

using std::list;
using std::vector;


const uint START = 640;
const uint LIMIT = 200000;
const unsigned NUM_RUN = 4;

factor_set FactorsForN(uint64t n, const vector<uint64t>& primes) {
  factor_set result;
  uint64t a;
  for (const auto& p : primes){
    if (n == 1 or p > n) {
      return result;
    }
    if (n%p == 0){
      if (result.size() == NUM_RUN){
        result.clear();
        return result;
      }
      a = 1;
      while (n%p == 0) {
        n /= p;
        a *= p;
      }
      result.emplace(a);
    }
  }
  return result;
}

void PrintFactors(factor_set set) {
  for (const auto& element : set) {
    std::cout << element << " ";
  }
  std::cout << std::endl;
}

void Solution() {

  vector<uint64t> primes = PrimeGen(LIMIT).getPrimes();
  list<factor_set> factors_list;
  for (uint64t n = START; n < LIMIT; ++n) {
    auto these_factors = FactorsForN(n, primes);
    if (these_factors.size() != NUM_RUN) {
      //PrintFactors(these_factors);
      factors_list.clear();
      continue;
    }
    //PrintFactors(these_factors);
    for (auto list_it = factors_list.begin();
         list_it != factors_list.end(); ++list_it) {
      bool contains_factor = false;
      for (auto ftr : these_factors) {
        if (list_it->find(ftr) != list_it->end()) {
          contains_factor = true;
          break;
        }
      }
      if (contains_factor) {
        /*std::cout << "Removing factors: ";
        for (auto tmp_it = factors_list.begin(); tmp_it != list_it; ++tmp_it) {
          PrintFactors(*tmp_it);
        }
        std::cout << "----------------------";/*/
        list_it = factors_list.erase(factors_list.begin(), list_it);
        continue;
      }
    }
    //std::cout << "Adding factors: ";
    //PrintFactors(these_factors);
    factors_list.push_back(these_factors);
    if (factors_list.size() == NUM_RUN) {
      std::cout << "---------------------------" << "\n";
      for (unsigned i = 0; i < NUM_RUN; ++i) {
        std::cout << n - i << '\n';
      }
      std::cout << std::endl;
      std::cout << "N: " << n << "\n";
      std::cout << "Factor list size: " << factors_list.size() << "\n";
      for (const auto& ftrs : factors_list) {
        std::cout << "Factors: \t";
        PrintFactors(ftrs);
      }
      return;
    }
  }
  return;
}

int main() {
  Solution();
}

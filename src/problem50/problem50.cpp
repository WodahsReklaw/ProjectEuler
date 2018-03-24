#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <unordered_set>

#include "primes.h"

typedef unsigned long prime_t;
using std::vector;
using std::unordered_set;

const prime_t LIMIT = 1000000;

void Solution() {
  vector<prime_t> primes_vec = PrimeGen(LIMIT).getPrimes();
  unordered_set<prime_t> primes_set(primes_vec.begin(), primes_vec.end());
  int longest_sum = 0;
  int longest = 0;

  for (auto i_it = primes_vec.begin(); i_it != primes_vec.end(); ++i_it) {
    prime_t sum = 0;
    for (auto j_it = i_it; j_it != primes_vec.end(); ++j_it) {
      sum += *j_it;
      if (sum > LIMIT) {
        break;
      } else if (primes_set.find(sum) != primes_set.end()) {
        int distance = std::distance(i_it, j_it) + 1;
        if (distance > longest) {
          longest = distance;
          longest_sum = sum;
        }
      }
    }
  }
  std::cout << "Longest chain: " << longest << "\n"
            << "Sum: " << longest_sum << std::endl;
}

int main() {
  Solution();
}

#include <iostream>
#include <vector>
#include <unordered_set>
#include "primes.h"

using std::vector;
using std::unordered_set;
using primes::prime_t;

const prime_t LIMIT = 1000000000;

void Solution(){
  vector<prime_t> primes_vector = PrimeGen(LIMIT).getPrimes();
  unordered_set<prime_t> primes_set(primes_vector.begin(), primes_vector.end());
  double diag_count = 1;
  double prime_diag = 0;
  unsigned i = 1;
  while (!prime_diag or prime_diag/diag_count > 0.1) {
    i += 2;
    const unsigned square = i*i;
    const unsigned d = i-1;
    for (prime_t j : {square, square - d, square - 2*d, square - 3*d}) {
      if (primes_set.find(j) != primes_set.end()) {
        ++prime_diag;
      }
      ++diag_count;
    }
    std::cout << "Diagonal Ratio: " << prime_diag << '/' << diag_count
              << " = " << prime_diag/diag_count << " i: " <<  i << std::endl;
  }
}

int main(){
  Solution();
  return 0;
}

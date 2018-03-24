// Prime permutations Problem 49 The arithmetic sequence, 1487, 4817,
// 8147, in which each of the terms increases by 3330, is unusual in
// two ways: (i) each of the three terms are prime, and, (ii) each of
// the 4-digit numbers are permutations of one another.

//   There are no arithmetic sequences made up of three 1-, 2-, or
//   3-digit primes, exhibiting this property, but there is one other
//   4-digit increasing sequence.

//   What 12-digit number do you form by concatenating the three terms
//   in this sequence?

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <unordered_set>

#include "primes.h"
#include "permute.h"

using std::unordered_set;
using std::vector;

typedef std::uint_least64_t long_int;

void Solution() {
  auto primes = PrimeGen(9999).getPrimes();

  unordered_set<long_int> set_primes;
  // Find range of primes which are 4 digits long.
  for (auto it = primes.begin(); it != primes.end(); ++it) {
    if (*it > 999 and *it < 9999) {
      set_primes.emplace(*it);
    }
  }

  // This checks for every prime the following:
  //   1. Ensure the prime is greater than 999 and less than 9999 and
  //      that we haven't already checked permutations of that prime.
  //   2. Construct a vector of permutations of the string of the prime.
  //   3. If the permutation of the prime is also prime then save it to
  //      our set of all prime permutations and a list of permutations for
  //      one prime.
  //   4. Sort the prime permutations to make finding arethemtic sequences
  //      easier.
  unordered_set<long_int> perm_set;
  vector<std::string> string_perms;
  std::list<vector<long_int> > list_perm;
  for (auto it = primes.begin(); it != primes.end(); ++it) {
    if (*it > 999 and *it < 9999 and perm_set.find(*it) == perm_set.end()) {
      string_perms = permute::HeapPermute(std::to_string(*it));
      vector<long_int> permute_primes;
      for (const auto& perm : string_perms) {
        long_int p = std::stoi(perm);
        if (set_primes.find(p) != set_primes.end()
            and perm_set.find(p) == perm_set.end()) {
          permute_primes.push_back(p);
          perm_set.emplace(p);
        }
      }
      std::sort(permute_primes.begin(), permute_primes.end());
      list_perm.push_back(permute_primes);
    }
  }

  // Now we find arthemtic sequences.
  // For every list of prime permutations we check every distnace between
  // two primes a, b and then we check the distance + b if that is also
  // in out list of prime permutations.

  for (const auto& vec : list_perm) {
    // We need at least 3 elements.
    if (vec.size() > 3) {
      for (auto i_itr = vec.begin(); i_itr != vec.end(); ++i_itr) {
        for (auto j_itr = i_itr + 1; j_itr != vec.end(); ++j_itr) {
          long_int dist = *j_itr - *i_itr;
          if (std::find(j_itr, vec.end(), dist + *j_itr) != vec.end()) {
            std::cout << "Found: " << *i_itr << " "
                      <<  *j_itr << " " << *j_itr + dist << std::endl;
          }
        }
      }
    }
  }
}

int main(){
  Solution();
  return 0;
}

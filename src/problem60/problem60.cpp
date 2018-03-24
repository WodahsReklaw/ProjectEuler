// Prime pair sets
// Problem 60
// The primes 3, 7, 109, and 673, are quite remarkable. By taking any two primes
// and concatenating them in any order the result will always be prime. For
// example, taking 7 and 109, both 7109 and 1097 are prime. The sum of these
// four primes, 792, represents the lowest sum for a set of four primes with
// this property.

// Find the lowest sum for a set of five primes for which any two primes
// concatenate to produce another prime.

#include <string>
#include <unodered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "primes.h"

using primes::prime_t;
using std::unordered_map;
using std::unordered_set;
using std::vector;
using std::pair;
using std::string;

typedef unordered_map<prime_t, unordered_set<prime_t> > prime_set_dict;

pair<prime_t, prime_t> ConcatPair(const prime_t& a, const prime_t& b) {
  prime_t first = std::stoi(std::to_string(a) + std::to_string(b));
  prime_t second = std::stoi(std::to_string(b) + std::to_string(a));
  return std::make_pair(first, second);
}

inline bool InPrimesSet(const prime_t& a, const unordered_set<prime_t>& set) {
  return (set.find(a) != set.end())
}

bool IsPrimePair(const prime_t& a, const prime_t& b,
                 const unordered_set<prime_t>& prime_set) {
  auto pair = ConcatPair(a, b);
  return InPrimeSet(pair.first, pair.second);
}

pair_set_dict GeneratePrimePairs() {
  vector<prime_t> primes = PrimeGen(10000).getPrimes();
  unordered_set<prime_t> prime_set(primes.begin(), primes.end());
  prime_map
  for (const auto& p_1 : primes) {
    // For each prime before current p, check if p is in previous'
    // prime pair dict.
    for (const auto& p_2 : primes) {
      if (IsPrimePair(p_1, p_2, prime_set)) {

      }
    }
    // Then for each prime after current make pairs of p and j
    // keeping track of concact primes.
  }
  // Return concat primes dictonary.
}

// The rest of the solution hinges on making joins between each prime
// and the sets of concat primes.

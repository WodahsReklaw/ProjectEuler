// Simple prime sieve. If this needs to be optimized further
// it may be better to use someone else's implenentation,
// e.g: primesieve.

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdint>
#include <cmath>
#include <functional>
#include <iostream>
#include <vector>

#include <primes.h>

typedef std::uint_least64_t uint64;

using std::vector;
using std::cin;

using std::cout;
using std::endl;

const uint64 L1D_CACHE_SIZE = 32768;
const char IS_PRIME = 1;
const char NOT_PRIME = 0;

/// @file     segmented_sieve.cpp
/// @author   Kim Walisch, <kim.walisch@gmail.com>
/// @brief    This is a simple implementation of the segmented sieve of
///           Eratosthenes with a few optimizations. It generates the
///           primes below 10^9 in 0.9 seconds (single-threaded) on an
///           Intel Core i7-4770 CPU (3.4 GHz) from 2013.
/// @license  Public domain.
void PrimeGen::sieveUntilN(uint64 n,
                           std::function<uint64(uint64)> filterPrime)  {
  uint64 sqrt = std::sqrt(n);
  uint64 segment_size = std::max(sqrt, L1D_CACHE_SIZE);

  // generate small primes <= sqrt
  std::vector<char> is_prime(sqrt + 1, IS_PRIME);
  for (uint64 i = 2; i * i <= sqrt; i++)
    if (is_prime[i] == IS_PRIME)
      for (uint64 j = i * i; j <= sqrt; j += i)
        is_prime[j] = NOT_PRIME;

  if (auto res = filterPrime(2)) {
    primeVector.push_back(res);
  }

  // vector used for sieving
  std::vector<char> sieve(segment_size);
  std::vector<uint64> primes;
  std::vector<uint64> next;
  int64_t s = 3;
  int64_t this_prime = 3;
  for (int64_t low = 0; low <= n; low += segment_size) {
    std::fill(sieve.begin(), sieve.end(), 1);

    // current segment = interval [low, high]
    int64_t high = std::min(low + segment_size - 1, n);
    //std::cout << "                     \r" <<
    //low << " " << high << std::flush;
    // add new sieving primes <= sqrt(high)
    for (; s * s <= high; s += 2) {
      if (is_prime[s] == IS_PRIME) {
        primes.push_back((uint64) s);
        next.push_back((uint64)(s * s - low));
      }
    }

    // sieve the current segment
    for (std::size_t i = 0; i < primes.size(); i++) {
      uint64 j = next[i];
      for (uint64 k = primes[i] * 2; j < segment_size; j += k) {
        sieve[j] = NOT_PRIME;
      }
      next[i] = j - segment_size;
    }

    for (; this_prime <= high; this_prime += 2) {
      if (sieve[this_prime - low] == IS_PRIME){ // n is a prime
        if(auto res = filterPrime(this_prime)) {
          primeVector.push_back(res);
        }
      }
    }
  }
}

PrimeGen::PrimeGen(){
  sieveUntilN(0, [](uint64 x) -> uint64 { return x; });
}

PrimeGen::PrimeGen(uint64 n) {
  sieveUntilN(n, [](uint64 x) -> uint64 { return x; });
  return;
}

PrimeGen::PrimeGen(uint64 n,
                   std::function<uint64(uint64)> filterPrime) {
  sieveUntilN(n, filterPrime);
  return;
}

const std::vector<uint64>& PrimeGen::getPrimes() {
  return primeVector;
}

bool IsPrime(uint64 p) {
  if (p < 2) {
    return false;
  }
  if (p%2 == 0 or p%3 == 0) {
    return false;
  }
  auto sqrt = std::ceil(std::sqrt(p));
  for (uint64 k = 6; k < sqrt; k += 6) {
    if ((p%(k-1) == 0) or (p%(k+1) == 0)) {
      return false;
    }
  }
  return true;
}

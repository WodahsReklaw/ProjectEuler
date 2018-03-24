#ifndef __PRIMES_H__
#define __PRIMES_H__

#include <cstdint>
#include <vector>
#include <functional>

namespace primes {
  typedef std::uint_least64_t prime_t;
}

class PrimeGen {
private:
  std::vector<std::uint_least64_t> primeVector;
  void sieveUntilN(std::uint_least64_t n,
                   std::function<std::uint_least64_t(std::uint_least64_t)>);
public:
  PrimeGen();
  PrimeGen(std::uint_least64_t x);
  PrimeGen(std::uint_least64_t x,
           std::function<std::uint_least64_t(std::uint_least64_t)>);
  const std::vector<std::uint_least64_t>& getPrimes();
};

bool IsPrime(std::uint_least64_t);

#endif

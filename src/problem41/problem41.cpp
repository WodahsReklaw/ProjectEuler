// problem41.cpp
//
// Daniel Coelho
//
// We shall say that an n-digit number is pandigital if
// it makes use of all the digits 1 to n exactly once.
// For example, 2143 is a 4-digit pandigital and is also prime.

// What is the largest n-digit pandigital prime that exists?
// Note there is a trick: If the sum of the digits of a number
// are divisible by 3, then that number is also divisible by 3.
// One can do this to verify that a 9 and 8 digit pandigital is not
// prime.

#include <functional>
#include <iostream>
#include <unordered_set>
#include <cstdint>
#include <string>
#include <vector>

#include "primes.h"
#include "permute.h"

typedef std::uint_least64_t uint64;
using std::unordered_set;
using std::string;
using std::vector;

const vector<unordered_set<char> > SeqVec{
  {'1'}, {'1', '2'}, {'1', '2', '3'}, {'1', '2', '3', '4'},
  {'1', '2', '3', '4', '5'}, {'1', '2', '3', '4', '5', '6'},
  {'1', '2', '3', '4', '5', '6', '7'},
};

bool IsPandigital(uint64 n) {
  string s = std::to_string(n);

  // First ensure that all the digits are unique.
  unordered_set<char> digits;
  for (const auto& ch : s) {
    if (digits.find(ch) == digits.end() and ch != '0') {
      digits.emplace(ch);
    } else {
      return false;
    }
  }
  std::cout << s << std::endl;
  return SeqVec[s.size()-1] == digits;
}


uint64 PandigitalPrime() {
  PrimeGen prime_gen(7654321);
  vector<uint64> primes = prime_gen.getPrimes();
  std::cout << "Built primes." << std::endl;
  for (auto rit = primes.rbegin(); rit != primes.rend(); ++rit) {
    if (IsPandigital(*rit)) {
      return *rit;
    }
  }
  return 0;
}



int main(int argc, char** argv){
  string s{"7654321"};
  vector<string> pandigitals= permute::HeapPermute(s);
  long max_pan_prime = 0;
  for (const string& p : pandigitals) {
    if (IsPrime(std::stol(p))) {
      max_pan_prime = std::max(std::stol(p), max_pan_prime);
    }
  }
  std::cout << max_pan_prime << std::endl;
  return 0;
}

// Prime digit replacements Problem 51
//
// By replacing the 1st digit of
// the 2-digit number *3, it turns out that six of the nine possible
// values: 13, 23, 43, 53, 73, and 83, are all prime.

//   By replacing the 3rd and 4th digits of 56**3 with the same digit,
//   this 5-digit number is the first example having seven primes
//   among the ten generated numbers, yielding the family: 56003,
//   56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003,
//   being the first member of this family, is the smallest prime with
//   this property.

//   Find the smallest prime which, by replacing part of the number
//   (not necessarily adjacent digits) with the same digit, is part of
//   an eight prime value family.

// Solution Sketch:
// 1. Generate a set of primes and grouped by N digits.
// 2. For each prime with N p:
//    a) For each digit in p:
//       i) substitue the digit with another digit and check if prime,
//          remember if there are any matches.
//       ii) If there are not 8 matches then remove any similar candidates.
//       iii) Probably want to cache by place and value of digits *frozen*.
//    b) The first found prime wins.

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

#include "primes.h"

using primes::prime_t;
using std::list;
using std::size_t;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

const prime_t LIMIT = 1000000;


vector<string> WildCards(prime_t p, unordered_map<string, bool>& p_map) {
  const string s = std::to_string(p);
  vector<string> result;
  for (size_t i = 0; i < s.size(); ++i) {
    string tmp_str = s;
    for (size_t j = i; j < s.size()-1; ++j) {
      if (s[i] == s[j]) {
        tmp_str[j] = '*';
        // For this wildcard'd number check if we already looked for it
        // If so then we already know it is either good or bad.
        if (p_map.find(tmp_str) == p_map.end() or p_map[tmp_str]) {
          //std::cout << "push_back:" << tmp_str << "\n";
          result.push_back(tmp_str);
        } else {
          break;
        }
      }
    }
  }
  return result;
}

string Replace(string s, const char& a, const char& b) {
  for (auto& ch : s) {
    if (ch == a) {
      ch = b;
    }
  }
  return s;
}

const unsigned N_PRIMES = 7;

void Solution() {
  vector<prime_t> primes_vector = PrimeGen(LIMIT).getPrimes();
  unordered_set<prime_t> primes_set(primes_vector.begin(), primes_vector.end());
  unordered_map<string, bool> replace_lookup;
  list<std::tuple<string, list<prime_t> > >answers;
  /*const auto iter_start =  std::find_if(
      primes_vector.begin(), primes_vector.end(),
      [](prime_t p){ return p > 1; });*/

  for (const auto& p : primes_vector) {
    vector<string> wild_cards = WildCards(p, replace_lookup);
    //std::for_each(wild_cards.begin(), wild_cards.end(),
    //[](string s){ std::cout << s << "\n"; });
    //std::cout << std::endl;
    for (const auto& possible_str : wild_cards) {
      unsigned count = 0;
      list<prime_t> answer_primes;
      for (char ch = '0'; ch <= '9'; ++ch ) {
        ++count;
        prime_t candidate = std::stoi(Replace(possible_str, '*', ch));
        if (primes_set.find(candidate) != primes_set.end()) {
          answer_primes.push_back(candidate);
        }
      }
      if (answer_primes.size() > N_PRIMES) {
        answers.push_back(std::make_tuple(possible_str, answer_primes));
      } else {
        replace_lookup[possible_str] = false;
      }
    }
  }
  for (const auto& s : answers) {
    std::cout << std::get<0>(s) << "  ";
    for (const auto& ans : std::get<1>(s)) {
      std::cout << ans << " ";
    }
    std::cout << "\n";
  }
  std::cout << std::endl;
}

int main() {
  Solution();
}

#include <iostream>
#include <functional>
#include <list>
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <utility>

using ::std::list;
using ::std::string;
using ::std::endl;
using ::std::cout;
using ::std::unordered_set;
using ::std::unordered_map;

const unsigned MAX_LIMIT = 9999 + 1;

const list<string> REF_KEYLIST {
    "tri", "square", "pentag", "heptag", "octag"
};

struct CycleWord {
  string word;
  std::set<string> types_used;
  unordered_set<string> subwords_used;
  CycleWord(string wd, std::set<string> types, unordered_set<string> sw)
      : word(wd), types_used{types}, subwords_used{sw} {}
  string key() {
    string joined_types;
    for (const string& s : types_used) {
      joined_types += s;
    }
    return word + joined_types;
  }
};

inline unsigned tri(unsigned n) {
  return n*(n+1)/2;
}

inline unsigned square(unsigned n) {
  return n*n;
}

inline unsigned pentag(unsigned n) {
  return n*(3*n-1)/2;
}

inline unsigned hexag(unsigned n) {
  return n*(2*n-1);
}

inline unsigned heptag(unsigned n) {
  return n*(5*n-3)/2;
}

inline unsigned octag(unsigned n) {
  return n*(3*n-2);
}


list<string> cycles(const string s) {
  string num(s);
  list<string> result;
  for (size_t i = 0; i < num.size(); ++i) {
    char ch = num.back();
    num.pop_back();
    num.insert(0, 1, ch);
    result.push_back(num);
  }
  return result;
}

void printEach(std::set<string> set) {
  for (const auto& s : set) {
    std::cout << s << " ";
  }
}


unordered_set<string> initSet(std::function<unsigned(unsigned)> f) {
  unordered_set<string> result;
  unsigned n = 1;
  unsigned x = f(n);
  while (x < MAX_LIMIT) {
    if (x > 999) {
      result.emplace(std::to_string(x));
    }
    x = f(n);
    ++n;
  }
  return result;
}

int main() {

  // Initalize all our lists to contain all n'tagonal numbers
  // that are at least 4 digits long.
  std::cout << "Initializing word types..." << std::flush;
  unordered_map<string, unordered_set<string> > ntagonal_value_map {
    {"tri", initSet(tri)},
    {"square", initSet(square)},
    {"pentag", initSet(pentag)},
    {"hexag", initSet(hexag)},
    {"heptag", initSet(heptag)},
    {"octag", initSet(octag)}
  };
  std::cout << ".. Done." << std::endl;

  unordered_map<string, unordered_map<string, list<string> > > prefix_map;
  unordered_map<string, unordered_map<string, list<string> > > suffix_map;
  for (auto kv_pair : ntagonal_value_map) {
    // For every value add a prefix and suffix entry into our map.
    std::cout << "Size of " <<  std::get<0>(kv_pair) << " " <<
        std::get<1>(kv_pair).size() << '\n';
    for (auto value : std::get<1>(kv_pair)) {
      // Prefix map contains a mapping of the first two charaters to a
      // list of all n-tagonal numbers with the same prefix.
      prefix_map[std::get<0>(kv_pair)][value.substr(0, 2)].push_back(value);
      // Suffix map contains a mapping of the last two charaters to a
      // list of all n-tagonal numbers with the same suffix.
      suffix_map[std::get<0>(kv_pair)][value.substr(2, 2)].push_back(value);
    }
  }

  // Initalize our potential solution list to octagonals.
  list<CycleWord> can_cycles;
  for (string s : ntagonal_value_map["octag"]) {
    can_cycles.push_back(CycleWord(s, {"octag"}, {s}));
  }

  list<string> keys = {"tri", "square", "pentag", "hexag", "heptag"};
  // We only need to iterate over the types of number classes 5 times.
  for (int i = 0; i < 6; ++i) {
    // Iterate through our possible answer chains
    std::cout << "Attempt " << + i << std::endl;
    unordered_set<string> cycle_keys; // Used to prevent dupes.
    list<CycleWord> next_cycle;

    for (auto it = can_cycles.begin(); it != can_cycles.end(); ++it) {
      const string prefix = it->word.substr(0, 2);
      const string suffix = it->word.substr(it->word.size()-2, 2);
      if (it->types_used.size() == 6 and prefix == suffix) {
        std::cout << it->types_used.size() << " cycle: " <<  it->word << " ";
        unsigned sum = 0;
        for (const string& num_str : it->subwords_used) {
          sum += std::stoi(num_str);
        }
        std::cout << "Sum: " << sum << " ";
        printEach(it->types_used);
        std::cout << std::endl;
        return 0;
      }

      for (const string& key : keys) {
        // Once we used a type of word we cannot use another in the same
        // candidate solution.
        if (it->types_used.find(key) != it->types_used.end()) {
          continue;
        }
        // Match the suffix of the current solution to the prefix
        // for a given n-tagonal number.
        if (prefix_map[key].find(suffix) != prefix_map[key].end()) {
          for (const string& pre : prefix_map[key][suffix]) {
            // We cannot have any repeat words in our solution.
            if (it->subwords_used.find(pre) != it->subwords_used.end()) {
              continue;
            }
            CycleWord cw = CycleWord(
                it->word + pre, it->types_used, it->subwords_used);
            if (cycle_keys.find(cw.key()) != cycle_keys.end()) {
              continue;
            } else {
              cycle_keys.emplace(cw.key());
            }
            cw.types_used.emplace(key);
            cw.subwords_used.emplace(pre);
            next_cycle.push_back(cw);
          }
        }
        // Match the prefix of the current solution to the suffix
        // for a given n-tagonal number.
        if (suffix_map[key].find(prefix) != suffix_map[key].end()) {
          for (const string& suf : suffix_map[key][prefix]) {
            // We cannot have any repeat words in our solution.
            if (it->subwords_used.find(suf) != it->subwords_used.end()) {
              continue;
            }
            CycleWord cw = CycleWord(
                suf + it->word, it->types_used, it->subwords_used);
            if (cycle_keys.find(cw.key()) != cycle_keys.end()) {
              continue;
            } else {
              cycle_keys.emplace(cw.key());
            }
            cw.types_used.emplace(key);
            cw.subwords_used.emplace(suf);
            next_cycle.push_back(cw);
          }
        }
      }
    }
    can_cycles = next_cycle;
  }
  return -1;
}

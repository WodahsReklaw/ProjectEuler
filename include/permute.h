#include <algorithm>
#include <vector>
#include <string>

namespace permute {
  template <typename T>
  std::vector<std::vector<T> > HeapPermute(std::vector<T> s){
    std::vector<size_t> c(s.size(), 0);
    std::vector<T> result{s};
    size_t i = 0;
    while ( i < s.size()) {
      if (c[i] < i) {
        if (i%2 == 0) {
          std::swap(s[0], s[i]);
        } else {
          std::swap(s[c[i]], s[i]);
        }
        result.push_back(s);
        c[i] = c[i]+1;
        i = 0;
      } else {
        c[i] = 0;
        ++i;
      }
    }
    return result;
  }
  std::vector<std::string> HeapPermute(std::string s);
}

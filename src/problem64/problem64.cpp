#include <cassert>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_set>

using ::std::string;
using ::std::unordered_set;

struct FracTerm {
  int wholeNum;
  int numInt;
  int numRoot;
  int denomInt;
  int denomRoot;
  FracTerm(int whole, int ni, int nRoot, int di, int dRoot)
      : wholeNum{whole}, numInt{ni}, numRoot{nRoot},
        denomInt{di}, denomRoot{dRoot} {}
  string toString() {
    return std::to_string(wholeNum) + "(" + std::to_string(numRoot)
        + " + " + std::to_string(numInt) + ")" + "/("
        + std::to_string(denomRoot) + " + " + std::to_string(denomInt) + ")";
  }
};

int gcd(int a, int b) {
  a = std::abs(a);
  b = std::abs(b);
  // Ensure a > b
  if (b > a) {
    int tmp = a;
    a = b;
    b = tmp;
  }
  // 18, 4, 18 % 4 = 2, 9/2
  while (a%b) {
    int tmp = a%b;
    a = b;
    b = tmp;
  }
  return b;
}

FracTerm nextTerm(const FracTerm& n) {
  // First make a new term with the num and denom flipped and whole number set to 0.
  int next_denom = n.numRoot - (n.numInt*n.numInt);
  assert(next_denom > 0 && "Denom cannot be less or equal to 0");
  int t_gcd = gcd(next_denom, n.denomInt);
  assert(n.denomInt/t_gcd == 1 && "Numerator must be 1");
  // Multiply the numerator by the complex conjugate.
  next_denom = next_denom/t_gcd;
  assert(next_denom > 0 && "Denom less than 0");
  int next_num_root = n.numRoot;
  int whole_num = 0;
  int trunc_sqrt = static_cast<int>(std::sqrt(next_num_root));
  int next_num_int = -n.numInt;
  while (trunc_sqrt + next_num_int - next_denom >= 0) {
    next_num_int -= next_denom;
    ++whole_num;
  }
  return FracTerm(whole_num, next_num_int, next_num_root, next_denom, 0);
}


int main() {

  int count = 0;
  FracTerm a(0, -4, 23, 1, 0);
  for (int i = 0; i <= 10000; ++i) {

    int trunc_root = static_cast<int>(std::sqrt(i));
    if (static_cast<double>(trunc_root) == std::sqrt(i)) {
      continue;
    }
    unordered_set<string> result_set;
    FracTerm a(trunc_root, -trunc_root, i, 1, 0);
    while (result_set.find(a.toString()) == result_set.end()) {
      result_set.emplace(a.toString());
      // std::cout << a.toString() << "\n";
      a = nextTerm(a);
    }
    // std::cout << "----------------------------------------------" << std::endl;
    if (result_set.size()%2 == 0) {
      ++count;
    }
  }
  std::cout << count << std::endl;
}

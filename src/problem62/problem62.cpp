#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

using ::std::cin;
using ::std::cout;
using ::std::endl;
using ::std::list;
using ::std::string;
using ::std::unordered_map;
using ::std::vector;

using cube_t = unsigned long;


// Creates a set of all "possible" cubes that we should expect to see.
vector<cube_t> generateCubes(cube_t max_size) {
  vector<cube_t> result;
  cube_t max = std::pow(static_cast<double>(max_size), 1.0/3.0);
  std::cout << "Max cube " << max << std::endl;
  for (cube_t n = 1; n < max; ++n) {
    result.push_back(n*n*n);
  }
  return result;
}


// Creates a map of cube's digits to a list of vectors.
unordered_map<string, list<cube_t> > solutionMap(const vector<cube_t>& cubes) {
  unordered_map<string, list<cube_t> > result;
  for (const cube_t& cube : cubes) {
    string key = std::to_string(cube);
    std::sort(key.begin(), key.end());
    result[key].push_back(cube);
  }
  return result;
}


// Returns the samllest cube of N matches.
cube_t smallestMatchedCube(
    unordered_map<string, list<cube_t> >& cube_map, size_t n_matches) {
  cube_t smallest = -1; // Initalize to max_size of cube_t.
  for (const auto& entry : cube_map) {
    const list<cube_t>& cube_list = std::get<1>(entry);
    if (cube_list.size() == n_matches) {
      for (const cube_t& cube : cube_list) {
        smallest = std::min(smallest, cube);
      }
    }
  }
  return smallest;
}


int main(int argc, char** argv) {
  if (argc != 3) {
    cout << "Please enter two args." << endl;
    return -1;
  }

  cube_t max_sz = std::stoul(string(argv[1]));
  size_t match_num = std::stoi(string(argv[2]));

  cout << "Generating cubes up to " << max_sz  << '\n';
  vector<cube_t> cubes = generateCubes(max_sz);
  cout << "Generated " << cubes.size() << " cubes."  << '\n';
  cout << "Creating solution map."  << '\n';
  unordered_map<string, list<cube_t> > solution_map = solutionMap(cubes);
  cout << "Generated " << solution_map.size() << "keys." << '\n';
  cout << "Smallest cube with " << match_num << " ";
  cout << smallestMatchedCube(solution_map, match_num) << endl;

  return 0;
}

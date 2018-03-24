#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

string XOrString(const string& s_in, const string& key) {
  string result;
  result.reserve(s_in.size());
  for (unsigned i = 0; i < s_in.size(); ++i) {
    const char& ch = key.at(i % key.size());
    result.push_back(s_in.at(i)^ch);
  }
  return result;
}

unsigned CountWords(const string& str, const string& word) {
  unsigned result = 0;
  size_t pos = str.find(word);
  while (pos != string::npos and pos < str.size()) {
    ++result;
    pos = str.find(word, pos+1);
  }
  return result;
}

bool ContainsCommonWords(const string& str) {
  const vector<string> common_words{"the", "be", "to", "of", "and", "for"};
  unsigned counter = 0;
  for (auto word : common_words) {
    counter += CountWords(str, word);
  }
  return (counter > 40);
}

void Solution(const string& input_str) {

  for (char i = 'a'; i <= 'z'; ++i) {
    for (char j = 'a'; j <= 'z'; ++j) {
      for (char k = 'a'; k <= 'z'; ++k) {
        string key{i, j, k};
        const string output_str = XOrString(input_str, key);
        //std::cout << key << "\n";
        if (ContainsCommonWords(output_str)) {
          std::cout << "Key: " << key << "\n";
          std::cout << "msg:\n" << output_str << '\n';
          unsigned sum = 0;
          std::for_each(output_str.begin(), output_str.end(),
                        [&sum](char ch){ sum += ch; });
          std::cout << "Sum: " << sum << std::endl;
          return;
        }
      }
    }
  }
  std::cout << "Failure." << std::endl;
}


int main(int argc, char** argv) {

  if (argc == 1) {
    string input;
    std::cin >> input;
    string word;
    string parsed_input;
    for (const char& ch : input) {
      if (ch != ',') {
        word.push_back(ch);
      } else {
        std::cout << word << std::endl;
        parsed_input.push_back((char)std::stoi(word));
        word.clear();
      }
    }
    parsed_input.push_back((char)std::stoi(word));
    std::cout << "Parsing input: \n" << parsed_input << std::endl;
    Solution(parsed_input);
  } else if (argc == 2) {
    // Get the filename from argv.
  } else {
    // Print error message.
  }
  return 0;
}

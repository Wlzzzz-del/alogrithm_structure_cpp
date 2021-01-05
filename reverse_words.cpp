#include <cctype>
#include <iostream>
#include <string>
#include <vector>
/*
 * given input ->"I have 36 books, 40 pens2.";
 * output-> "I evah 36 skoob, 40 2snep."
 */
struct Bound {
  int begin = 0;
  int end = 0;
};

std::vector<Bound> seperate_string(std::string str) {
  /*
   * seperate string to different substr
   */
  std::vector<Bound> record_array;
  int begin = 0;
  for (int i = 0; i <= str.size(); i++) {
    if (std::isspace(str[i]) || i == str.size()||std::ispunct(str[i])) {
      Bound a;
      a.begin = begin;
      a.end = i;
      record_array.push_back(a);
      begin = i + 1;
      continue;
    }
  }
  return record_array;
}

bool isnum(std::string s) {
  /*
   * input: string
   * if string are all numbers return true;
   */
  for (int i = 0; i < s.size(); i++) {
    if (std::isalpha(s[i])||std::ispunct(s[i])) {
      break;
    }
    return true;
  }
  return false;
}

void reverse(std::vector<Bound> array, std::string str) {
  for (auto x : array) {
    std::string s = str.substr(x.begin, x.end - x.begin);
    if (isnum(s)) {
      for (int i; i < s.size(); i++) {
        std::cout << s[i];
      }
      std::cout << std::endl;
    } else {
      // reverse the string
      std::vector<char> reverse_s;
      for (int i = 0; i < s.size(); i++) {
        reverse_s.push_back(s[s.size() - i - 1]);
      }
      for (auto j : reverse_s) {
        std::cout << j;
      }
      std::cout << std::endl;
    }
  }
}
int main() {
  std::vector<Bound> array;
  std::string str = "I have 36 books, 40 pens2.";
  array = seperate_string(str);
  reverse(array, str);
  return 0;
}

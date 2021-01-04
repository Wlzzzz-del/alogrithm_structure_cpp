#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
 * write a method anagram(s,t) to decide if two strings are anagrams or not.
 * example:
                                given s="abcd", t="dcab",return true.
 */

bool anagram(string st1, string st2) {
  // use hash_table
  int i;
  if (st1.length() == 0 || st2.length() == 0) {
    return false;
  }
  if (st1.length() != st2.length()) {
    return false;
  }
  unordered_map<char, int> hash_table1;
  for (i = 0; i < st1.length(); i++) {
    hash_table1[st1[i]]++;
  }
  for (i = 0; i < st2.length(); i++) {
    if (--hash_table1[st2[i]] < 0) {
      return false;
    }
  }
  return true;
}
bool anagram2(string st1, string st2) {
  // use sort
  if (st1.length() == 0 || st2.length() == 0) {
    return false;
  }
  if (st1.length() != st2.length()) {
    return false;
  }
  sort(st1.begin(), st1.end());
  sort(st2.begin(), st2.end());
  if (st1 == st2) {
    return true;
  } else {
    return false;
  }
}

int main() {
  string st1 = "12345";
  string st2 = "45132";
  if (anagram(st1, st2)) {
    cout << "they are anagram" << endl;
  } else {
    cout << "they are not anagram" << endl;
  }
  if (anagram2(st1, st2)) {
    cout << "they are anagram" << endl;
  } else {
    cout << "they are not anagram" << endl;
  }
}

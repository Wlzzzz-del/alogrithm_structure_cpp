#include <bitset>
#include <iostream>
#include <string.h>
using namespace std;
bool isUnique(string input) {
  // determine if all characters of a string are unique
  bitset<256> hashtable;
  int i = 0;
  for (i = 0; i < input.length(); i++) {
    if (hashtable[input[i]]) {
      return false;
    } else {
      hashtable[input[i]] = 1;
    }
  }
  return true;
}

int main() {
  string s = "chashjldja";
  cout << isUnique(s) << endl;
}

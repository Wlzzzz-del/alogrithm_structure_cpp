#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

using namespace std;

// given two strings, determine if they are permutations of each others
bool Two_string(string st_a, string st_b) {
  unordered_map<char, int> hash_map1;
  unordered_map<char, int> hash_map2;
  int i = 0;
  for (auto adj : st_a) {
    hash_map1[adj]++;
  }
  for (i = 0; i < st_b.length(); i++) {
    hash_map2[st_a[i]]++;
  }
  if (hash_map1.size() != hash_map2.size())
    return false;
  unordered_map<char, int>::iterator it;
  for (it = hash_map1.begin(); it != hash_map1.end(); it++) {
    if (it->second != hash_map2[it->first]) {
      return false;
    }
  }
  return true;

  /*
  for(auto adj: hash_map1)
  {
                                  cout<<adj.first<<"->"<<adj.second<<endl;
  }
  */
}

int main() {
  string a = "abd";
  string b = "dad";
  if (Two_string(a, b))
    cout << "yes" << endl;
  else
    cout << "no" << endl;
  return 0;
}

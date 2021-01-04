#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
/* get the length of the longest consecutive elements sequence in an array. For
 * example, given [31,6,32,1,3,2], the longest consecutive elements sequence is
 * [1,2,3].Return its length:3.
 */

struct Bound {
  int high = 0;
  int low = 0;
};
int longestConsecutive(vector<int> &num) {
  int local = 0;
  int max_length = 0;
  unordered_map<int, Bound> hash_table;
  for (int i = 0; i < num.size(); i++) {
    if (hash_table.count(i)) {
      continue;
    }
    local = num[i];

    int high = local;
    int low = local;

    if (hash_table.count(local - 1)) {
      low = hash_table[local - 1].low;
    }
    if (hash_table.count(local + 1)) {
      high = hash_table[local + 1].high;
    }
    hash_table[low].high = hash_table[local].high = high;
    hash_table[high].low = hash_table[local].low = low;
    if (high - low + 1 > max_length) {
      max_length = high - low + 1;
    }
  }
  return max_length;
}
int main() {
  vector<int> array = {31, 6, 32, 1, 3, 2};
  cout << longestConsecutive(array);
  return 0;
}

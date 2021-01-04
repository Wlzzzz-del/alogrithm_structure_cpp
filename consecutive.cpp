#include <iostream>
#include <unordered_map>
#include <vector>
struct Bound {
  int high = 0;
  int low = 0;
};

int consecutive(std::vector<int> array) {

  int local;
  int max_len;
  std::unordered_map<int, Bound> hash_table;
  for (int i = 0; i < array.size(); i++) {
    local = array[i];
    int low = local;
    int high = local;
    if (hash_table.count(local - 1)) {
      low = hash_table[local - 1].low;
    }
    if (hash_table.count(local + 1)) {
      high = hash_table[local + 1].high;
    }
    hash_table[local].high = high;
    hash_table[local].low = low;
    if (high - low + 1 > max_len) {
      max_len = high - low + 1;
    }
  }
  return max_len;
}

int main() {
  std::vector<int> array = {31, 6, 32, 1, 2, 2};
  std::cout << consecutive(array);
}

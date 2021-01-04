#include <iostream>
#include <string>
#include <unordered_map>
/* given two strings, find the longest common substring. return the length of it
 */
int longestCommonSubstring(std::string &A, std::string &B) {
  int max_len = 0;
  if (A.size() == 0 || B.size() == 0) {
    return 0;
  }
  for (int i = 0; i < A.size(); i++) {
    int len = 0;
    for (int j = 0; j < B.size(); j++) {
      int A_i = i;
      int B_i = j;
      while (A[A_i++] == B[B_i++]) {
        len++;
      }
    }
    if (len > max_len) {
      max_len = len;
    }
  }
  return max_len;
}

int main() {
  std::string A = "ABCDE";
  std::string B = "BCGIH";
  std::cout << longestCommonSubstring(A, B);
  return 0;
}

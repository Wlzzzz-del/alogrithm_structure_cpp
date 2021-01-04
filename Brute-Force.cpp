#include <iostream>
#include <string>
using namespace std;

char *StrStr(const char *str, const char *target) {
  if (!*target)
    return (char *)str;
  char *p1 = (char *)str;
  while (*p1) {
    char *str_begin = p1;
    char *target_begin = (char *)target;
    while (*str_begin && *target_begin &&
           *str_begin == *target_begin) { //添加存在条件判断
      str_begin++;
      target_begin++;
    }
    if (!*target_begin)
      return p1;
    p1 = p1 + 1;
  }
  return NULL;
}

int main() {
  const char *test_a = "123";
  cout << test_a << endl;
  const char *test_b = "3";
  cout << test_b << endl;
  cout << "找到的位置为:" << endl;
  cout << StrStr(test_a, test_b) << endl;
}

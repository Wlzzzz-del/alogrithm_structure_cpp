#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool message_news(string message, string news) {
  // first way : use two hash_table to compare
  // given a newspaper and message as two strings, check if the message can be
  // composed using letters in the newspaper.
  if (news.length() < message.length()) {
    return false;
  }
  unordered_map<char, int> message_map;
  unordered_map<char, int> news_map;
  for (auto adj : message) {
    message_map[adj]++;
  }
  for (int i = 0; i < news.length(); i++) {
    news_map[news[i]]++;
  }
  unordered_map<char, int>::iterator it;
  for (it = message_map.begin(); it != message_map.end(); it++) {
    if (news_map[(it->first)] >= it->second) {
      continue;
    } else {
      return false;
    }
  }
  return true;
}
bool message_news2(string message, string news) {
  // second way: use single hash_table to compare
  if (message.length() > news.length()) {
    return false;
  }
  unordered_map<char, int> hash_table1;
  for (auto adj : news) {
    hash_table1[adj]++;
  }
  for (auto adj : message) {
    if (--hash_table1[adj] < 0)
      return false;
  }
  return true;
}

int main() {
  string a = "123456";
  string b = "123";
  cout << "the first way:" << endl;
  if (message_news(b, a)) {
    cout << "can be composed" << endl;
  } else {
    cout << " can`t be composed " << endl;
  }
  cout << "the second way:" << endl;
  if (message_news2(b, a)) {
    cout << "can be composed" << endl;
  } else {
    cout << " can`t be composed " << endl;
  }
  return 0;
}

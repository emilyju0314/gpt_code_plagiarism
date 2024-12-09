#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  deque<char> S;
  for (int i = 0; i < str.size(); i++) {
    if (S.size() == 0) {
      S.push_back(str[i]);
      continue;
    }
    char prev = S.back();
    if (prev == str[i]) {
      S.pop_back();
    } else {
      S.push_back(str[i]);
    }
  }
  for (deque<char>::iterator it = S.begin(); it != S.end(); it++) {
    cout << *it;
  }
  cout << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  string test;
  long long h_cnt = 0;
  long long num = 0;
  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == 'h') {
      test.assign(str, i, 5);
      if (!test.compare("heavy")) {
        h_cnt++;
        i += 4;
      }
    } else if (str[i] == 'm') {
      test.assign(str, i, 5);
      if (!test.compare("metal")) {
        i += 4;
        num += h_cnt;
      }
    }
  }
  cout << num << endl;
  return 0;
}

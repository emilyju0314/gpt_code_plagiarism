#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int mod = 1e9 + 7;
int main() {
  string s;
  string t;
  cin >> s >> t;
  int flag = 0;
  for (int i = s.size() - 1; i >= 0; --i) {
    if (s[i] < 'z') {
      s[i]++;
      flag = 1;
      break;
    } else {
      s[i] = 'a';
    }
  }
  if (!flag) {
    cout << "No such string" << endl;
  } else {
    if (s < t) {
      cout << s << endl;
    } else {
      cout << "No such string" << endl;
    }
  }
  return 0;
}

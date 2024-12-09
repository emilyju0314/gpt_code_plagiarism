#include <bits/stdc++.h>
using namespace std;
void code() {
  string s;
  cin >> s;
  long long a = 0, b = 0;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      a = i;
      break;
    }
  }
  for (long long i = s.size() - 1; i > 0; i--) {
    if (s[i] == '1') {
      b = i;
      break;
    }
  }
  long long count = 0;
  for (long long i = a; i < b; i++) {
    if (s[i] == '0') count++;
  }
  cout << count << endl;
}
signed main() {
  long long T;
  cin >> T;
  while (T--) code();
}

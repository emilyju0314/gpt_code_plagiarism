#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  t = 1;
  while (t--) {
    long long n, i, j, w, h, count = 0, sum = 0, total, k, T;
    string s;
    cin >> s;
    char c;
    T = s[0];
    for (i = 1; i < s.size(); i++) {
      k = s[i];
      if (k > T) {
        c = s[i];
        T = s[i];
      }
    }
    for (i = 0; i < s.size(); i++) {
      if (s[i] == T) {
        cout << s[i];
      }
    }
  }
}

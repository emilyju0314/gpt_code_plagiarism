#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int k, start = 0;
string s, a[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cin >> k;
  for (int i = 0; i < k; ++i) {
    cin >> a[i];
  }
  cin >> s;
  int cnt = 0;
  while (start < (int)s.size()) {
    ++cnt;
    int new_start = start;
    for (int i = 0; i < k; ++i) {
      int pos = start;
      for (char c : a[i]) {
        if (pos < (int)s.size() && s[pos] == c) {
          ++pos;
        }
      }
      new_start = max(new_start, pos);
    }
    if (new_start == start) {
      cout << -1 << '\n';
      return 0;
    }
    start = new_start;
  }
  cout << cnt << '\n';
  return 0;
}

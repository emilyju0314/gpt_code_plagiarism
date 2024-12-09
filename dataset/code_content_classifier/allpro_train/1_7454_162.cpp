#include <bits/stdc++.h>
using namespace std;
double pi = 3.141592653589793238462643383279;
bool comp(const pair<int, int> &a, const pair<int, int> &b) {
  return b.second > a.second;
}
void solve() {
  string s;
  cin >> s;
  long long ct = 0, n = s.length();
  if (n <= 4)
    cout << 0;
  else {
    for (long long i = 1; i < n; i++) {
      if (s[i] == 'v' && s[i - 1] == 'v') ct++;
    }
    long long st = 0, ss = 0;
    for (long long i = 1; i < n; i++) {
      if (s[i] == 'v' && s[i - 1] == 'v')
        st++;
      else if (s[i] == 'o') {
        long long pt = ct - st;
        ss += pt * st;
      }
    }
    cout << ss << "\n";
  }
}
int main() {
  solve();
  return 0;
}

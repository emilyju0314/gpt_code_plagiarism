#include <bits/stdc++.h>
using namespace std;
long long int countDigit(long long int n) {
  string s = to_string(n);
  return s.size();
}
bool sol(long long int x) {
  string s = to_string(x);
  if (s.size() == 1) {
    return true;
  }
  if (s[0] == s[s.size() - 1]) {
    return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int l, r;
  cin >> l >> r;
  long long int ans = 0;
  if (countDigit(r) <= 2) {
    for (long long int i = l; i <= r; i++) {
      if (sol(i)) {
        ans++;
      }
    }
    cout << ans << endl;
    return 0;
  }
  while (countDigit(l) < 3) {
    if (sol(l)) {
      ans++;
    }
    l++;
  }
  while (l % 10 != 0) {
    if (sol(l)) {
      ans++;
    }
    l++;
  }
  while (r % 10 != 0) {
    if (sol(r)) {
      ans++;
    }
    r--;
  }
  ans += (r - l) / 10;
  cout << ans << endl;
}

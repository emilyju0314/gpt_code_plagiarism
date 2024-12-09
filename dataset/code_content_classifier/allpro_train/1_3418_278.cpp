#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9;
int get_cnt(int n) {
  int res = 0;
  while (n) {
    ++res;
    n /= 10;
  }
  return res;
}
long long solve(int n) {
  if (n <= 9) {
    return n;
  }
  int cnt = get_cnt(n);
  int pw10 = 1;
  for (int i = 0; i < (int)cnt - 1; ++i) pw10 *= 10;
  return solve(pw10 - 1) + (n - pw10 + 1) * 1ll * cnt;
}
int brut(int n) {
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += get_cnt(i);
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}

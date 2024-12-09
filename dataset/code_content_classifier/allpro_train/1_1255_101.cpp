#include <bits/stdc++.h>
using namespace std;
long long n[3], p[3], w[3];
long long m;
bool can(long long mid) {
  bool res = 1;
  long long any;
  long long p1 = m;
  for (int i = 0; i < 3; i++) {
    if (w[i] != 0) {
      any = mid * w[i] - n[i];
      any = max(any, 0ll);
      if (p1 >= p[i] * any) {
        p1 -= p[i] * any;
      } else
        res = 0;
    }
  }
  return res;
}
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'B') w[0]++;
    if (s[i] == 'S') w[1]++;
    if (s[i] == 'C') w[2]++;
  }
  cin >> n[0] >> n[1] >> n[2];
  cin >> p[0] >> p[1] >> p[2];
  cin >> m;
  long long l = 0, r = 1e13, ans = 0;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (can(mid)) {
      l = mid + 1;
      ans = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << ans;
}

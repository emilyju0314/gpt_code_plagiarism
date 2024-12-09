#include <bits/stdc++.h>
using namespace std;
long long int M = 1e9 + 7;
long long int n, k, m;
long long int z, q, u, a1, l, r, ax, cx, ay, by, cy, ql, qr, d, x, y;
long long int w[1000007];
long long int b[4007][4007];
vector<long long int> v[400000];
long long int dp[1009][1009];
long long int dp1[400000];
map<long long int, long long int> c2;
map<long long int, long long int> c1;
long long int to;
long long int solve(long long int i, long long int cnt) {
  if (i > n) {
    if (cnt % 360 == 0) to = 1;
    return 0;
  }
  solve(i + 1, (cnt + w[i]));
  solve(i + 1, cnt - w[i]);
}
long long int tot = 0;
long long int me(long long int a, long long int b, long long int M) {
  if (b == 0)
    return 1;
  else if (b % 2 == 0)
    return me((a * a) % M, b / 2, M);
  else
    return (a % M * me((a * a) % M, (b - 1) / 2, M) % M) % M;
}
long long int mI(long long int a, long long int m) { return me(a, m - 2, m); }
int main() {
  long long int w, h, w1, h1, w2, h2;
  cin >> w >> h;
  cin >> w1 >> h1;
  cin >> w2 >> h2;
  for (int i = h; i >= 0; i--) {
    w += i;
    if (i == h1) {
      w -= w1;
    } else if (i == h2) {
      w -= w2;
    }
    w = max(w, 0LL);
  }
  cout << max(w, 0LL);
}

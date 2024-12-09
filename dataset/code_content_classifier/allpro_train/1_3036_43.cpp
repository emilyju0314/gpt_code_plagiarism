#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int dx4[5] = {0, -1, 0, 1, 0};
const int dy4[5] = {0, 0, 1, 0, -1};
const int dx8[9] = {0, -1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[9] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
const int maxn = 3e5 + 50;
const double PI = acos(-1.0);
const long long mod = 1e9 + 7;
long long po(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  } else {
    return gcd(b % a, a);
  }
}
long long H, M, K;
long long h1, m1, h2, m2;
long long dig(long long x) {
  long long cnt = 0;
  while (x) {
    if (x % 10) cnt++;
    x /= 10;
  }
  return cnt;
}
long long cal2(long long x, long long k) {
  for (int i = 0; i < k - 1; i++) {
    x /= 10;
  }
  return x;
}
long long cal(long long hour, long long minute) {
  long long res = cal2(minute, K) + hour * cal2(M - 1, K);
  long long d = dig(M - 1);
  res += cal2(hour, K - d);
  return res;
}
void solve() {
  cin >> H >> M >> K;
  cin >> h1 >> m1 >> h2 >> m2;
  if (make_pair(h1, m1) <= make_pair(h2, m2)) {
    cout << cal(h2, m2) - cal(h1, m1) << endl;
  } else {
    long long res = cal(H - 1, M - 1) - cal(h1, m1) + cal(h2, m2);
    if (dig(H - 1) + dig(M - 1) >= K) res++;
    cout << res << endl;
  }
}
int main() {
  solve();
  return 0;
}

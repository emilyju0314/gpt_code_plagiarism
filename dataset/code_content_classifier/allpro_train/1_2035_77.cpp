#include <bits/stdc++.h>
using namespace std;
const int inf = 1000 * 1000 * 1000;
int ok(long long x) {
  long long t = x;
  while (x > 0) {
    int z = x % 10;
    x /= 10;
    if (z == 0) continue;
    if (t % z != 0) return 0;
  }
  return 1;
}
long long count(long long a, long long b) {
  long long res = 0;
  for (int i = a; i <= b; i++) {
    res += ok(i);
  }
  return res;
}
long long a, b;
int ar[20];
int tpow[50];
const int mods[4] = {8, 9, 5, 7};
struct st {
  char ar[4];
  st() {
    memset(ar, 0, sizeof(ar));
    ;
  }
  inline void Add(int x) {
    for (int i = 0; i < 4; i++) {
      ar[i] = (ar[i] + x) % mods[i];
    }
  }
  inline bool check(int mask) {
    for (int i = 2; i <= 8; i *= 2) {
      if (!(mask & (1 << (i - 2)))) continue;
      if (ar[0] % i != 0) return 0;
    }
    for (int i = 3; i <= 9; i *= 3) {
      if (!(mask & (1 << (i - 2)))) continue;
      if (ar[1] % i != 0) return 0;
    }
    if (mask & (1 << (7 - 2)))
      if (ar[3] % 7 != 0) return 0;
    if (mask & (1 << (5 - 2)))
      if (ar[2] % 5 != 0) return 0;
    if (mask & (1 << (6 - 2)))
      if (ar[0] % 2 != 0 || ar[1] % 3 != 0) return 0;
    return 1;
  }
  inline int getID() {
    return ar[0] * 9 * 5 * 7 + ar[1] * 5 * 7 + ar[2] * 7 + ar[3];
  }
};
long long dp[1 << 8][19][2520];
long long DP(int mask, int k, st s, char b) {
  if (k == 0) {
    if (s.check(mask)) return 1;
    return 0;
  }
  if (b == 0) {
    if (dp[mask][k][s.getID()] != -1) return dp[mask][k][s.getID()];
  }
  long long res = 0;
  int e = b ? ar[k - 1] : 9;
  for (int i = 0; i <= e; i++) {
    int nmask = mask;
    if (i > 1) nmask |= 1 << (i - 2);
    st t = s;
    t.Add(tpow[k - 1] * i);
    res += DP(nmask, k - 1, t, (b && i == e) ? 1 : 0);
  }
  if (b == 0) {
    dp[mask][k][s.getID()] = res;
  }
  return res;
}
int main() {
  int T;
  cin >> T;
  tpow[0] = 1;
  for (int i = 1; i < 50; i++) {
    tpow[i] = (tpow[i - 1] * 10) % (5 * 7 * 8 * 9);
  }
  while (T--) {
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    ;
    int S = 0;
    long long t = b;
    while (b > 0) {
      ar[S] = b % 10;
      b /= 10;
      S++;
    }
    st s;
    memset(dp, -1, sizeof(dp));
    ;
    long long res = DP(0, S, s, 1);
    if (a > 1) {
      a--;
      S = 0;
      while (a > 0) {
        ar[S] = a % 10;
        a /= 10;
        S++;
      }
      res -= DP(0, S, s, 1);
    } else
      res--;
    cout << res << endl;
  }
  return 0;
}

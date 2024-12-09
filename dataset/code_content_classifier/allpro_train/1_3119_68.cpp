#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 9000000000000000000;
inline bool checkBit(long long n, int i) { return n & (1LL << i); }
inline long long setBit(long long n, int i) { return n | (1LL << i); }
inline long long resetBit(long long n, int i) { return n & (~(1LL << i)); }
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
inline bool isLeapYear(long long year) {
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
inline void normal(long long &a) {
  a %= 1000000007;
  (a < 0) && (a += 1000000007);
}
inline long long modMul(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  return (a * b) % 1000000007;
}
inline long long modAdd(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  return (a + b) % 1000000007;
}
inline long long modSub(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long modPow(long long b, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1;
  }
  return r;
}
inline long long modInverse(long long a) {
  normal(a);
  return modPow(a, 1000000007 - 2);
}
inline long long modDiv(long long a, long long b) {
  return modMul(a, modInverse(b));
}
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, yy1, m, yy2, a[100005], b[100005], mx = -1;
map<int, int> mp1, mp2;
map<int, int>::iterator it;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> yy1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mx = max(a[i], mx);
  }
  cin >> m >> yy2;
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    mx = max(b[i], mx);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) mp1[a[i]]++;
  for (int i = 1; i <= m; i++) {
    if (mp1.count(b[i])) ans = 2;
  }
  mp1.clear();
  for (int i = 1;; i++) {
    int now = (1 << i);
    int lol = now >> 1;
    for (int j = 1, cur; j <= n; j++) {
      cur = a[j] % now;
      mp1[cur]++;
    }
    for (int j = 1, cur; j <= m; j++) {
      cur = b[j] % now;
      mp2[cur]++;
    }
    for (it = mp1.begin(); it != mp1.end(); it++) {
      int tmp = it->first, tpp = it->second;
      int hand = (tmp + lol) % now;
      if (mp2.count(hand))
        ans = max(tpp + mp2[hand], ans);
      else
        ans = max(ans, tpp);
    }
    for (it = mp2.begin(); it != mp2.end(); it++) {
      int tmp = it->first, tpp = it->second;
      int hand = (tmp + lol) % now;
      if (mp1.count(hand))
        ans = max(tpp + mp1[hand], ans);
      else
        ans = max(ans, tpp);
    }
    mp1.clear();
    mp2.clear();
    if ((1 << i) > mx) break;
  }
  cout << ans << '\n';
  return 0;
}

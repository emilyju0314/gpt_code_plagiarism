#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool umax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
long long POW(long long a, long long p, long long M) {
  if (!p) return 1LL;
  long long T = POW(a, p / 2, M);
  T = T * T % M;
  if (p & 1) T = T * (a % M) % M;
  return T;
}
long long SQRT(long long a) {
  long long b = (long long)sqrtl(((double)a) + 0.5);
  while (b * b < a) ++b;
  while (b * b > a) --b;
  return (b * b == a) ? b : -1;
}
const long long MOD = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int cnt[101];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      cnt[a]++;
    }
    int ans = 0;
    int a, b;
    a = b = 101;
    for (int i = 0; i <= 100; i++) {
      if (cnt[i] >= 2)
        continue;
      else if (cnt[i] == 1) {
        if (b == 101) b = i;
      } else {
        if (b == 101) b = i;
        a = i;
        break;
      }
    }
    ans = a + b;
    cout << ans << endl;
  }
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
  return 0;
}

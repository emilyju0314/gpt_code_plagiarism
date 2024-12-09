#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Woverflow"
using namespace std;
const short INF16 = ~(1 << 15);
const int INF32 = ~(1ll << 31);
const int SZ = 1e3 + 11;
const long long mod = 998244353;
const long long INF64 = 1e18;
const long long P = 53;
const long double eps = 1e-10;
const long double PI = acos(-1);
inline long long MOD(long long x) {
  x %= mod, x += mod;
  return x % mod;
}
inline long long MOD(long long x, long long m) {
  x %= m, x += m;
  return x % m;
}
inline long long T(long long x) { return x * (x + 1) >> 1; }
void Solve(int num_test) {
  int n0, n1, n2;
  cin >> n0 >> n1 >> n2;
  string ans = "";
  if (n1 == 0) {
    for (int i = 0; i <= max(n0, n2); i++) ans.push_back(n0 ? '0' : '1');
  } else if (n1 == 1) {
    for (int i = 0; i <= n0; i++) ans.push_back('0');
    for (int i = 0; i <= n2; i++) ans.push_back('1');
  } else {
    if (!n2 && !n0) {
      for (int i = 0; i <= n1; i++) ans.push_back(i & 1 ? '0' : '1');
    } else if (!n2) {
      for (int i = 0; i <= n0; i++) ans.push_back('0');
      for (int i = 0; i < n1; i++) ans.push_back(i & 1 ? '0' : '1');
    } else if (!n0) {
      for (int i = 0; i <= n2; i++) ans.push_back('1');
      for (int i = 0; i < n1; i++) ans.push_back(i & 1 ? '1' : '0');
    } else if (n1 & 1) {
      for (int i = 0; i <= n0; i++) ans.push_back('0');
      for (int i = 0; i < n1; i++) ans.push_back(i & 1 ? '0' : '1');
      for (int i = 0; i < n2; i++) ans.push_back('1');
    } else {
      for (int i = 0; i <= n2; i++) ans.push_back('1');
      for (int i = 0; i <= n0; i++) ans.push_back('0');
      for (int i = 0; i < n1 - 1; i++) ans.push_back(i & 1 ? '0' : '1');
    }
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(10);
  srand(time(NULL));
  int test = 1;
  cin >> test;
  for (int i = 1; i <= test; i++) Solve(i);
}

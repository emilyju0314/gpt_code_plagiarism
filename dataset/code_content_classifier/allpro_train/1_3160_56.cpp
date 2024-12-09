#include <bits/stdc++.h>
using namespace std;
const double PI = acos(0) * 2;
const double EPS = 1e-8;
const long long MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int oo = 1e9;
const double foo = 1e30;
template <class T>
int getbit(T s, int i) {
  return (s >> i) & 1;
}
template <class T>
T onbit(T s, int i) {
  return s | (T(1) << i);
}
template <class T>
T offbit(T s, int i) {
  return s & (~(T(1) << i));
}
template <class T>
int cntbit(T s) {
  return __builtin_popcounll(s);
}
map<int, int> D;
int n, a[300100], ans, dp[300100], v[300100];
vector<pair<int, int> > aans;
void Trace(int i) {
  int x = v[i];
  if (dp[x - 1] == 0)
    x = 1;
  else
    Trace(x - 1);
  cout << x << " " << i << endl;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    if (D.find(a[i]) == D.end()) {
      D[a[i]] = i;
      dp[i] = dp[i - 1];
      v[i] = v[i - 1];
    } else {
      int pos = D[a[i]];
      if (dp[pos - 1] + 1 > dp[i - 1]) {
        dp[i] = dp[pos - 1] + 1;
        v[i] = pos;
      } else {
        dp[i] = dp[i - 1];
        v[i] = v[i - 1];
      }
      D[a[i]] = i;
    }
  }
  if (dp[n] == 0) {
    cout << -1;
  } else {
    cout << dp[n] << endl;
    Trace(n);
  }
}

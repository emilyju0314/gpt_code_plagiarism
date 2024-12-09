#include <bits/stdc++.h>
using namespace std;
const int INF = 2 * int(1e9);
const long long INFll = 1ll * INF * INF;
const int MOD = 1000000007;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int p, k;
  cin >> p >> k;
  if (!k) {
    int ans = 1;
    for (int i = 0; i < p - 1; ++i) ans = 1ll * ans * p % MOD;
    cout << ans;
    return 0;
  }
  vector<int> g(p);
  for (int i = 0; i < p; ++i) g[i] = (1ll * i * k) % p;
  vector<int> u(p);
  int ans = 1;
  for (int i = 1; i < p; ++i)
    if (!u[i]) {
      u[i] = 1;
      for (int j = g[i]; j != i; j = g[j]) u[j] = 1;
      ans = 1ll * ans * p % MOD;
    }
  if (k == 1) ans = 1ll * ans * p % MOD;
  cout << ans;
  if (0) cerr << "\nTIME = " << clock() << "\n";
  return 0;
}

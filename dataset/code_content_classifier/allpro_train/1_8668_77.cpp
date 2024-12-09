#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000001;
const long double EPS = 1e-9;
const int MOD = 1000000007;
const long long LLINF = 1000000000000000001;
const int maxn = 1000042;
int n, k;
int phi[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  if (k == 1)
    cout << 3 << endl;
  else {
    for (int i = 2; i <= n; i++) phi[i] = i;
    for (int i = 2; i <= n; i++)
      if (phi[i] == i) {
        phi[i]--;
        for (int j = i + i; j <= n; j += i) phi[j] = phi[j] / i * (i - 1);
      }
    sort(phi + 2, phi + 1 + n);
    long long ans = 1;
    for (int i = 2; i <= k + 2; i++) ans += phi[i];
    cout << ans << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
const long long N = 10000010, mod = 1e9 + 7, mod2 = 1e9 + 9, mod3 = 998244353,
                sq = 450, base = 727;
long long n, m, x, y, z, w, k, ans, t, cnt[N], p[N];
bool h[N];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    cnt[x]++;
  }
  for (int i = 2; i < N; i++) {
    if (!h[i]) {
      for (int j = i + i; j < N; j += i) {
        h[j] = true;
      }
    }
  }
  for (int i = 2; i < N; i++) {
    p[i] += p[i - 1];
    if (!h[i]) {
      for (int j = i; j < N; j += i) {
        p[i] += cnt[j];
      }
    }
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    x = min(x, (long long)1e7);
    y = min(y, (long long)1e7);
    cout << p[y] - p[x - 1] << endl;
  }
  return 0;
}

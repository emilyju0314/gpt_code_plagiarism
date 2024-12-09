#include <bits/stdc++.h>
using namespace std;
const int kN = 100 * 1000;
const int kLog = 35;
int f[kN];
long long w[kN];
int up[kN][kLog];
long long mn[kN][kLog];
long long sum[kN][kLog];
int main() {
  std::ios_base::sync_with_stdio(false);
  int n;
  long long k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> f[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }
  for (int i = 0; i < n; ++i) {
    up[i][0] = f[i];
    mn[i][0] = sum[i][0] = w[i];
  }
  for (int h = 1; h < kLog; ++h) {
    for (int i = 0; i < n; ++i) {
      mn[i][h] = min(mn[i][h - 1], mn[up[i][h - 1]][h - 1]);
      sum[i][h] = sum[i][h - 1] + sum[up[i][h - 1]][h - 1];
      up[i][h] = up[up[i][h - 1]][h - 1];
    }
  }
  for (int i = 0; i < n; ++i) {
    long long sum_ = 0;
    long long mn_ = 1e9;
    int u = i;
    for (int b = 0; b < kLog; ++b) {
      if (k & (1LL << b)) {
        sum_ += sum[u][b];
        mn_ = min(mn_, mn[u][b]);
        u = up[u][b];
      }
    }
    cout << sum_ << ' ' << mn_ << '\n';
  }
  return 0;
}

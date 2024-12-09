#include <bits/stdc++.h>
using namespace std;
const int N = (int)(2e5) + 10;
const long long oo = 1000;
int n;
long long IT[N * 4], ZIP[N * 4], Sum[N * 4], bound[N * 4];
int a[N];
long long H[N];
long long ans;
int L1[N], L2[N], R1[N], R2[N];
void update(int i, int l, int r, int u, int v, long long val) {
  if (l > r || l > v || r < u || bound[i] >= val || v < u) return;
  if (l >= u && r <= v && val >= IT[i]) {
    IT[i] = val;
    ZIP[i] = val;
    bound[i] = val;
    Sum[i] = val * (r - l + 1);
    return;
  }
  int mid = (l + r) >> 1;
  if (ZIP[i]) {
    ZIP[i << 1] = ZIP[(i << 1) + 1] = IT[i << 1] = IT[(i << 1) + 1] =
        bound[i << 1] = bound[(i << 1) + 1] = ZIP[i];
    ZIP[i] = 0;
    Sum[i << 1] = IT[i << 1] * (mid - l + 1);
    Sum[(i << 1) + 1] = IT[(i << 1) + 1] * (r - mid);
  }
  update(i << 1, l, mid, u, v, val);
  update((i << 1) + 1, mid + 1, r, u, v, val);
  IT[i] = max(IT[i << 1], IT[(i << 1) + 1]);
  bound[i] = min(bound[i << 1], bound[(i << 1) + 1]);
  Sum[i] = Sum[i << 1] + Sum[(i << 1) + 1];
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  int vmax = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    vmax = max(vmax, a[i]);
    for (int j = 1; j * j <= a[i]; j++)
      if (a[i] % j == 0) {
        R2[j] = R1[j];
        R1[j] = i;
        if (!L1[j])
          L1[j] = i;
        else if (!L2[j])
          L2[j] = i;
        if (a[i] != j * j) {
          R2[a[i] / j] = R1[a[i] / j];
          R1[a[i] / j] = i;
          if (!L1[a[i] / j])
            L1[a[i] / j] = i;
          else if (!L2[a[i] / j])
            L2[a[i] / j] = i;
        }
      }
  }
  for (int i = 1; i <= n; i++) update(1, 1, n, i, i, i);
  for (int i = vmax + 1; i >= 1; i--) {
    if (L1[i] != R1[i]) {
      update(1, 1, n, 1, L1[i], R2[i]);
      update(1, 1, n, L1[i] + 1, L2[i], R1[i]);
      update(1, 1, n, L2[i] + 1, n, n + 1);
    }
    H[i] = (long long)n * (n + 1) - Sum[1];
  }
  for (int i = vmax; i >= 1; i--) {
    ans += i * (H[i + 1] - H[i]);
  }
  cout << ans;
}

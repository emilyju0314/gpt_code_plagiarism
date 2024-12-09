#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 6;
const int INF = 1e9 + 4;
struct mang {
  int x, y, z;
};
mang b[N];
bool cmp(mang A1, mang B1) { return A1.z < B1.z; }
map<int, int> cnt;
int n, k, a[N], c[N], sl, f[3][5005], ans, d[N], sl1;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> k >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 2; i <= n; i++) {
    b[i - 1].x = a[i];
    b[i - 1].y = a[i - 1];
    b[i - 1].z = a[i] - a[i - 1];
  }
  sort(b + 1, b + n, cmp);
  for (int i = 1; i <= 2 * k && i <= n - 1; i++) {
    c[++sl] = b[i].x;
    c[++sl] = b[i].y;
  }
  sort(c + 1, c + sl + 1);
  d[1] = c[1];
  sl1 = 1;
  for (int i = 2; i <= sl; i++) {
    if (c[i] != c[i - 1]) d[++sl1] = c[i];
  }
  ans = INF;
  for (int i = 0; i <= 2; i++)
    for (int j = 0; j <= k; j++)
      if (j == 0)
        f[i][j] = 0;
      else
        f[i][j] = INF;
  for (int i = 2; i <= sl1; i++)
    for (int j = 1; j <= k && j * 2 <= i; j++) {
      f[(i % 3)][j] =
          min(f[(i + 1) % 3][j - 1] + (d[i] - d[i - 1]), f[(i + 2) % 3][j]);
      if (j == k) ans = min(ans, f[int(i % 3)][j]);
    }
  cout << ans;
  return 0;
}

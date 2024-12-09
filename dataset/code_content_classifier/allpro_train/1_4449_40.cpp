#include <bits/stdc++.h>
using namespace std;
const int Maxn = 85, Maxm = 200010, Mo = 1000000009, oo = INT_MAX >> 2;
struct Edge {
  int u, v;
};
typedef int IArr[Maxn];
typedef double DArr[Maxn];
int n, k, i, j, m, cnt;
IArr l, r, id;
DArr pl, pr, pm, f[Maxn][Maxn], t[Maxn][Maxn], rec[Maxn];
vector<int> G;
void update(int now, int l, int r) {
  for (int i = l; i <= r; i++) {
    now++;
    for (int j = 0; j <= now; j++)
      for (int k = 0; k <= now - j; k++) {
        f[now][j][k] = 0;
        if (j) f[now][j][k] += f[now - 1][j - 1][k] * pl[i];
        if (k) f[now][j][k] += f[now - 1][j][k - 1] * pm[i];
        f[now][j][k] += f[now - 1][j][k] * pr[i];
      }
  }
}
void work(int now, int l, int r) {
  if (l > r) return;
  if (l == r) {
    for (int x = 0; x < m; x++)
      for (int y = 0; y < m - x; y++)
        for (int k = 0; k <= y; k++)
          rec[id[l]][cnt + x + k + 1] += pm[l] * f[m - 1][x][y] / (y + 1);
    return;
  }
  int mid = (l + r) / 2;
  update(now, l, mid);
  work(now + mid - l + 1, mid + 1, r);
  update(now, mid + 1, r);
  work(now + r - mid, l, mid);
}
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    G.push_back((l[i]));
    G.push_back((r[i]));
  }
  sort(G.begin(), G.end());
  for (int w = 1; w < G.size(); w++)
    if (G[w - 1] != G[w]) {
      m = cnt = 0;
      for (i = 1; i <= n; i++)
        if (l[i] <= G[w - 1] && G[w] <= r[i]) {
          id[++m] = i;
          pm[m] = 1.0 * (G[w] - G[w - 1]) / (r[i] - l[i]);
          pl[m] = 1.0 * (G[w - 1] - l[i]) / (r[i] - l[i]);
          pr[m] = 1 - pm[m] - pl[m];
        } else if (r[i] <= G[w - 1])
          cnt++;
      f[0][0][0] = 1;
      work(0, 1, m);
    }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) cout << rec[i][j] << " ";
    cout << endl;
  }
}

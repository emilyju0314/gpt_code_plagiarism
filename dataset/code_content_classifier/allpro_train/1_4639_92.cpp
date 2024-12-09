#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
template <class T, class U>
inline void Max(T &a, U b) {
  if (a < b) a = b;
}
template <class T, class U>
inline void Min(T &a, U b) {
  if (a > b) a = b;
}
inline void add(int &a, int b) {
  a += b;
  while (a >= 1000000007) a -= 1000000007;
}
int pow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * (long long)a % 1000000007;
    a = (long long)a * a % 1000000007;
    b >>= 1;
  }
  return ans;
}
vector<int> g[100010];
pair<int, int> q[100010];
int K, f[100010], w[100010][5], cnt[100010], id[100010], pos[100010],
    ppos[100010], ans[100010];
inline int find(int a) { return a == f[a] ? a : f[a] = find(f[a]); }
void work(int l0, int r0, int l1, int r1) {
  if (l1 == r1) return;
  int mid = (l0 + r0 + 1) >> 1;
  for (int i = l0; i < r0; i++) f[i] = i;
  for (int i = l0; i < mid; i++) id[i] = mid - 1 - i;
  int now = 0;
  for (int i = mid - 1; i >= l0; i--) {
    for (auto j : g[i]) {
      if (j > i && j < mid) {
        int u = find(i), v = find(j);
        if (u != v) now++, f[u] = v;
      }
    }
    cnt[i] = now;
    memset(w[i], -1, sizeof(w[i]));
    for (int j = mid - 1; j >= l0 && id[j] < K; j--) w[i][id[j]] = find(j);
  }
  now = 0;
  for (int i = mid; i < r0; i++) id[i] = i - mid;
  for (int i = mid; i < r0 + 1; i++) {
    cnt[i] = now;
    memset(w[i], -1, sizeof(w[i]));
    for (int j = mid; j < r0 && id[j] < K; j++) w[i][id[j]] = find(j);
    if (i == r0) break;
    for (auto j : g[i]) {
      if (j >= mid && j < i) {
        int u = find(i), v = find(j);
        if (u != v) now++, f[u] = v;
      }
    }
  }
  int nowl = l1, nowr = r1;
  for (int i = l1; i < r1; i++) {
    int first = pos[i];
    if (q[first].first < mid && q[first].second >= mid) {
      int ret = cnt[q[first].first] + cnt[q[first].second];
      for (int j = mid - 1; j >= q[first].first && id[j] < K; j--) {
        int tmp = w[q[first].first][id[j]];
        f[j] = tmp, f[tmp] = tmp;
      }
      for (int j = mid; j < q[first].second && id[j] < K; j++) {
        int tmp = w[q[first].second][id[j]];
        f[j] = tmp, f[tmp] = tmp;
      }
      for (int j = mid; j < q[first].second && id[j] < K; j++) {
        for (auto k : g[j]) {
          if (k < mid && k >= q[first].first) {
            int u = find(j), v = find(k);
            if (u != v) ret++, f[u] = v;
          }
        }
      }
      ans[first] = q[first].second - q[first].first - ret;
    } else {
      if (q[first].second < mid)
        ppos[nowl++] = pos[i];
      else if (q[first].first >= mid)
        ppos[--nowr] = pos[i];
    }
  }
  for (int i = l1; i < r1; i++) pos[i] = ppos[i];
  work(l0, mid, l1, nowl);
  work(mid, r0, nowr, r1);
}
int main() {
  int T, i, j, k, ca = 0, m = 0, n;
  scanf("%d%d%d", &n, &K, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &j, &k), j--, k--;
    g[j].push_back(k), g[k].push_back(j);
  }
  int qn;
  scanf("%d", &qn);
  for (int i = 0; i < qn; i++) {
    scanf("%d%d", &q[i].first, &q[i].second), q[i].first--;
    pos[i] = i;
  }
  work(0, n, 0, qn);
  for (int i = 0; i < qn; i++) printf("%d\n", ans[i]);
  return 0;
}

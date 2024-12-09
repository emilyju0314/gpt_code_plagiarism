#include <bits/stdc++.h>
using namespace std;
int vt, ve[(2 * 4 * 2010)], re[(2 * 4 * 2010)], ze[(2 * 4 * 2010)],
    nextt[(2 * 4 * 2010)];
int in[2010], head[2010], path[2010], dis[2010], qu[2010], lim[2010];
void init() {
  vt = 1;
  memset(head, 0, sizeof(head));
}
int auxm = 0;
void add(int x, int y, int cap, int wei) {
  ++auxm;
  ve[++vt] = y;
  re[vt] = cap;
  ze[vt] = wei;
  nextt[vt] = head[x];
  head[x] = vt;
  ve[++vt] = x;
  re[vt] = 0;
  ze[vt] = -wei;
  nextt[vt] = head[y];
  head[y] = vt;
}
int mfmc(int s, int t, int n, int &fcost) {
  int flow = fcost = 0;
  while (1) {
    int qt = 0, k = 0;
    qu[qt++] = s;
    for (int i = 0; i < n; i++) dis[i] = lim[i] = 0x3f3f3f3f;
    dis[s] = 0;
    while (k != qt) {
      if (k == 2010) k = 0;
      int x = qu[k++];
      for (int i = head[x]; i; i = nextt[i])
        if (re[i] && dis[x] + ze[i] < dis[ve[i]]) {
          dis[ve[i]] = dis[x] + ze[i];
          path[ve[i]] = i;
          lim[ve[i]] = min(lim[x], re[i]);
          if (!in[ve[i]]) {
            if (qt == 2010) qt = 0;
            qu[qt++] = ve[i];
            in[ve[i]] = 1;
          }
        }
      in[x] = 0;
    }
    if (dis[t] == 0x3f3f3f3f) break;
    int f = lim[t];
    for (int p = t; p != s; p = ve[path[p] ^ 1]) {
      re[path[p]] -= f;
      re[path[p] ^ 1] += f;
    }
    fcost += f * dis[t];
    flow += f;
  }
  return flow;
}
pair<pair<int, int>, pair<int, int> > v[1010];
int ans[1010];
int main() {
  ios::sync_with_stdio(false);
  ;
  int nn, k;
  cin >> nn >> k;
  for (int i = 1; i < (nn + 1); ++i) {
    cin >> v[i].first.first >> v[i].first.second >> v[i].second.second;
    v[i].second.first = i - 1;
    v[i].first.second += v[i].first.first;
  }
  sort(v + 1, v + nn + 1);
  int s = 0;
  int t = 2 * nn + 2;
  int n = 2 * nn + 3;
  init();
  add(s, 1, k, 0);
  for (int i = 1; i < (nn + 1); ++i) {
    add(1, 2 * i, 1, 0);
    add(2 * i, 2 * i + 1, 1, -v[i].second.second);
    add(2 * i + 1, t, 1, 0);
    if (i < nn) add(2 * i, 2 * (i + 1), 1010, 0);
    for (int j = i + 1; j < (nn + 1); ++j)
      if (v[j].first.first >= v[i].first.second) {
        add(2 * i + 1, 2 * j, 1010, 0);
        break;
      }
  }
  int fcost, flow = mfmc(s, t, n, fcost);
  if (nn == 100) {
  }
  for (int i = 1; i <= auxm; i++) {
    int u = ve[2 * i + 1];
    int vv = ve[2 * i];
    int f = re[2 * i + 1];
    if (u + 1 == vv) {
      if (u % 2 == 0 && (u / 2) >= 1 && (u / 2) <= nn && f == 1)
        ans[v[u / 2].second.first] = 1;
    }
  }
  for (int i = 0; i < (nn); ++i) cout << ans[i] << " ";
  cout << endl;
  return 0;
}

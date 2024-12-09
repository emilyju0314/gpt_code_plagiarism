#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, d;
vector<int> v[5010];
bitset<5010> t, ab, cd;
int size[5010], A, B, C, D, tot;
bool vis[5010];
void dfs(int np, int fath, int id) {
  for (int i = 0; i < v[np].size(); i++) {
    if (v[np][i] == fath) continue;
    dfs(v[np][i], np, id);
  }
  if (v[np].size() == 1) {
    size[id]++;
    tot++;
    if (np == a) A = id, vis[id] = 1;
    if (np == b) B = id, vis[id] = 1;
    if (np == c) C = id, vis[id] = 1;
    if (np == d) D = id, vis[id] = 1;
  }
}
int main() {
  scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
  for (int i = 2, ti, tj; i <= n; i++) {
    scanf("%d", &tj);
    ti = i;
    v[ti].push_back(tj);
    v[tj].push_back(ti);
  }
  t.set(0);
  int idcnt = 0;
  for (int i = 0; i < v[1].size(); i++) {
    dfs(v[1][i], 1, ++idcnt);
    if (!vis[idcnt]) t |= (t << size[idcnt]);
  }
  if (tot & 1) {
    puts("NO");
    return 0;
  }
  ab = t;
  for (int i = 1; i < size[A]; i++) ab |= (ab << i);
  for (int i = 1; i < size[B]; i++) ab |= (ab << i);
  cd = t;
  for (int i = 1; i < size[C]; i++) cd |= (cd << i);
  for (int i = 1; i < size[D]; i++) cd |= (cd << i);
  if ((tot / 2 - 1 - size[C] >= 0 && ab[tot / 2 - 1 - size[C]] &&
       tot / 2 - 1 - size[B] >= 0 && cd[tot / 2 - 1 - size[B]]) ||
      (tot / 2 - 1 - size[D] >= 0 && ab[tot / 2 - 1 - size[D]] &&
       tot / 2 - 1 - size[B] >= 0 && cd[tot / 2 - 1 - size[B]]))
    puts("YES");
  else
    puts("NO");
  return 0;
}

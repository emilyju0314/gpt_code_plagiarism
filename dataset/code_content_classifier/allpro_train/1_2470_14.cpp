#include <bits/stdc++.h>
using namespace std;
long long n, st = -1, sz[200000], vali[200000], dist[200000], par[200000],
             valo[200000], valc[200000], sumsz[200000], sumtms[200000],
             df[200000];
vector<pair<long long, long long> > vt[200000];
vector<long long> cyc, dc;
bool vis[200000], isc[200000], fdcyc = false;
long long getdist(long long x, long long y) {
  pair<long long, long long> p = make_pair(y, -1);
  long long pos = lower_bound(vt[x].begin(), vt[x].end(), p) - vt[x].begin();
  return vt[x][pos].second;
}
void dfs(long long x, long long lst) {
  vis[x] = true;
  long long i;
  for (i = 0; i < vt[x].size(); i++) {
    if (!vis[vt[x][i].first]) {
      dfs(vt[x][i].first, x);
    } else if (vt[x][i].first != lst) {
      fdcyc = true;
      st = vt[x][i].first;
      isc[x] = true;
      cyc.push_back(x);
      return;
    }
    if (fdcyc) {
      isc[x] = true;
      cyc.push_back(x);
      if (x == st) {
        fdcyc = false;
      }
      return;
    }
  }
  return;
}
void dfs2(long long x, long long lst, long long d) {
  long long i;
  dist[x] = d;
  sz[x] = 1;
  vali[x] = 0;
  for (i = 0; i < vt[x].size(); i++) {
    if (vt[x][i].first != lst && !isc[vt[x][i].first]) {
      dfs2(vt[x][i].first, x, d + vt[x][i].second);
      sz[x] += sz[vt[x][i].first];
      vali[x] += vali[vt[x][i].first] + sz[vt[x][i].first] * vt[x][i].second;
    }
  }
  return;
}
void dfs3(long long x, long long lst, long long lval, long long beg) {
  long long i;
  par[x] = beg;
  valo[x] = 0;
  if (lst != -1) {
    valo[x] = valo[lst] + (sz[beg] - sz[lst]) * lval;
    valo[x] += vali[lst] - vali[x] - sz[x] * lval + (sz[lst] - sz[x]) * lval;
  }
  for (i = 0; i < vt[x].size(); i++) {
    if (vt[x][i].first != lst && !isc[vt[x][i].first]) {
      dfs3(vt[x][i].first, x, vt[x][i].second, beg);
    }
  }
  return;
}
int main() {
  long long i, x, y, z, mv = 0, l, r, tot;
  scanf("%lld", &n);
  for (i = 0; i < n; i++) {
    scanf("%lld%lld%lld", &x, &y, &z);
    x--;
    y--;
    vt[x].push_back(make_pair(y, z));
    vt[y].push_back(make_pair(x, z));
  }
  for (i = 0; i < n; i++) {
    sort(vt[i].begin(), vt[i].end());
  }
  dfs(0, -1);
  for (i = 0; i < cyc.size(); i++) {
    dfs2(cyc[i], -1, 0);
    dfs3(cyc[i], -1, 0, cyc[i]);
    mv += vali[cyc[i]];
  }
  df[0] = df[1] = sumsz[0] = sumtms[0] = sumtms[1] = 0;
  sumsz[1] = sz[cyc[0]];
  dc.push_back(0);
  for (i = 1; i < cyc.size(); i++) {
    df[i + 1] = df[i] + getdist(cyc[i - 1], cyc[i]);
    dc.push_back(df[i + 1]);
    sumsz[i + 1] = sumsz[i] + sz[cyc[i]];
    sumtms[i + 1] = sumtms[i] + sz[cyc[i]] * df[i + 1];
  }
  tot = df[cyc.size()] + getdist(cyc[0], cyc[cyc.size() - 1]);
  for (i = 0; i < cyc.size(); i++) {
    valc[cyc[i]] = mv - vali[cyc[i]];
    l = lower_bound(dc.begin(), dc.end(), df[i + 1] - tot / 2) - dc.begin();
    r = upper_bound(dc.begin(), dc.end(), df[i + 1] + tot / 2) - dc.begin() - 1;
    valc[cyc[i]] += (sumsz[i] - sumsz[l]) * df[i + 1] - (sumtms[i] - sumtms[l]);
    valc[cyc[i]] += (sumtms[r + 1] - sumtms[i + 1]) -
                    (sumsz[r + 1] - sumsz[i + 1]) * df[i + 1];
    valc[cyc[i]] +=
        (sumsz[l] - sumsz[0]) * (tot - df[i + 1]) + (sumtms[l] - sumtms[0]);
    valc[cyc[i]] += (sumsz[cyc.size()] - sumsz[r + 1]) * (tot + df[i + 1]) -
                    (sumtms[cyc.size()] - sumtms[r + 1]);
  }
  for (i = 0; i < n; i++) {
    valc[i] = valc[par[i]] + (n - sz[par[i]]) * dist[i];
  }
  for (i = 0; i < n; i++) {
    printf("%lld ", vali[i] + valo[i] + valc[i]);
  }
  puts("");
  return 0;
}

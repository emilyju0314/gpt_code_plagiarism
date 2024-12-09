#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const long long MAXN = 3e5 + 2;
long long n, m, k, c[MAXN], w[MAXN], cBcc[MAXN], depth[MAXN], low[MAXN],
    belong[MAXN], cntBcc;
bool sp[MAXN], spBcc[MAXN], vis[MAXN];
vector<pair<long long, long long> > g[MAXN];
stack<long long> sta;
void dfs(long long now, long long pre, long long deep) {
  sta.push(now);
  depth[now] = deep;
  low[now] = deep;
  vis[now] = 1;
  for (auto it : g[now]) {
    long long to = it.first;
    if (to != pre) {
      if (vis[to]) {
        low[now] = min(low[now], depth[to]);
      } else {
        dfs(to, now, deep + 1);
        low[now] = min(low[now], low[to]);
      }
    }
  }
  if (low[now] == deep) {
    cntBcc++;
    while (1) {
      long long index = sta.top();
      sta.pop();
      belong[index] = cntBcc;
      if (index == now) break;
    }
  }
}
long long cntSp[MAXN];
long long cntHave[MAXN];
long long total = 0;
long long dp[MAXN];
long long totC[MAXN], sumC[MAXN];
void dfsInit(long long now, long long pre) {
  cntSp[now] = spBcc[now];
  cntHave[now] = spBcc[now];
  total += spBcc[now];
  sumC[now] = cBcc[now];
  for (auto it : g[now]) {
    if (it.first != pre) {
      dfsInit(it.first, now);
      sumC[now] += sumC[it.first];
      cntSp[now] += cntSp[it.first];
      if (cntSp[it.first]) {
        cntHave[now]++;
      }
    }
  }
}
long long onlySon[MAXN][2];
void dfsDp(long long now, long long pre) {
  onlySon[now][0] = onlySon[now][1] = -1;
  totC[now] = cBcc[now];
  for (auto it : g[now]) {
    if (it.first != pre)
      if (!cntSp[it.first]) {
        totC[now] += sumC[it.first];
      }
  }
  dp[now] = totC[now];
  for (auto it : g[now]) {
    if (it.first != pre)
      if (cntSp[it.first]) {
        if (onlySon[now][0] == -1) {
          onlySon[now][0] = it.first;
        } else {
          onlySon[now][1] = it.first;
        }
        dfsDp(it.first, now);
        if (cntSp[it.first] == total) {
          dp[now] += dp[it.first];
        } else
          dp[now] += max(0ll, dp[it.first] - it.second);
      }
  }
}
long long res[MAXN];
struct DATA {
  long long cntSp, dp, totC, sumC;
};
map<pair<long long, long long>, long long> id;
pair<DATA, DATA> Copy(long long i, long long j) {
  DATA d1, d2;
  d1.cntSp = cntSp[i];
  d1.dp = dp[i];
  d1.sumC = sumC[i];
  d1.totC = totC[i];
  d2.cntSp = cntSp[j];
  d2.dp = dp[j];
  d2.sumC = sumC[j];
  d2.totC = totC[j];
  return make_pair(d1, d2);
}
void Paste(long long i, long long j, DATA d1, DATA d2) {
  cntSp[i] = d1.cntSp;
  dp[i] = d1.dp;
  sumC[i] = d1.sumC;
  totC[i] = d1.totC;
  cntSp[j] = d2.cntSp;
  dp[j] = d2.dp;
  sumC[j] = d2.sumC;
  totC[j] = d2.totC;
}
void change_root(long long now, long long pre) {
  res[now] = dp[now];
  for (auto it2 : g[now]) {
    long long it = it2.first;
    if (it != pre) {
      pair<long long, long long> saveSon =
          make_pair(onlySon[now][0], onlySon[now][1]);
      long long saveHave1 = cntHave[now], saveHave2 = cntHave[it];
      pair<DATA, DATA> save;
      save = Copy(now, it);
      if (!cntSp[it]) {
        totC[now] -= sumC[it];
      }
      if (cntSp[it]) {
        if (cntSp[it] != total)
          dp[now] -= max(0ll, dp[it] - it2.second);
        else
          dp[now] -= dp[it];
      }
      dp[now] -= totC[now];
      dp[it] -= totC[it];
      sumC[now] -= sumC[it];
      sumC[it] += sumC[now];
      cntSp[now] -= cntSp[it];
      cntSp[it] += cntSp[now];
      cntHave[it] += (bool)(cntSp[now]);
      if (!cntSp[now]) {
        totC[it] += sumC[now];
      }
      dp[now] += totC[now];
      dp[it] += totC[it];
      if (cntSp[now]) {
        if (cntSp[now] != total) {
          if (dp[now] - it2.second > 0) {
            dp[it] += dp[now] - it2.second;
          }
        } else {
          dp[it] += dp[now];
        }
      }
      change_root(it, now);
      Paste(now, it, save.first, save.second);
      cntHave[now] = saveHave1, cntHave[it] = saveHave2;
      onlySon[now][0] = saveSon.first;
      onlySon[now][1] = saveSon.second;
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (long long i = 1; i <= k; ++i) {
    long long vi;
    cin >> vi;
    sp[vi] = 1;
  }
  for (long long i = 1; i <= n; ++i) cin >> c[i];
  for (long long i = 1; i <= m; ++i) {
    long long wi;
    cin >> wi;
    w[i] = wi;
  }
  vector<pair<long long, long long> > edges;
  for (long long i = 1; i <= m; ++i) {
    long long u, v;
    cin >> u >> v;
    id[make_pair(u, v)] = id[make_pair(v, u)] = i;
    edges.push_back(make_pair(u, v));
    g[u].push_back(make_pair(v, w[i]));
    g[v].push_back(make_pair(u, w[i]));
  }
  dfs(1, 0, 1);
  for (long long i = 1; i <= n; ++i) cBcc[belong[i]] += c[i];
  for (long long i = 1; i <= n; ++i) spBcc[belong[i]] |= sp[i];
  for (long long i = 1; i <= n; ++i) g[i].clear();
  for (long long i = 0; i < m; ++i) {
    long long u, v;
    u = edges[i].first;
    v = edges[i].second;
    v = belong[v];
    u = belong[u];
    if (u != v) {
      g[u].push_back(make_pair(v, w[i + 1]));
      g[v].push_back(make_pair(u, w[i + 1]));
    }
  }
  dfsInit(1, 0);
  dfsDp(1, 0);
  change_root(1, 0);
  for (long long i = 1; i <= n; ++i) {
    cout << res[belong[i]] << " ";
  }
  cout << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 111111;
const long long INF = 1000000;
struct IntervalTree {
  long long valmax[MAXN * 4];
  long long valmin[MAXN * 4];
  long long add[MAXN * 4];
  int low[MAXN * 4], high[MAXN * 4];
  int maxpos[MAXN * 4];
  int minpos[MAXN * 4];
  IntervalTree() {}
  IntervalTree(int n) { Init(n, 0); }
  IntervalTree(int n, long long base) { Init(n, base); }
  void BuildNode(int s, int l, int h, long long base) {
    low[s] = l;
    high[s] = h;
    valmax[s] = base;
    valmin[s] = base;
    minpos[s] = base;
    maxpos[s] = base;
    add[s] = 0;
    if (l < h) {
      int m = (l + h) / 2;
      BuildNode(s * 2, l, m, base);
      BuildNode(s * 2 + 1, m + 1, h, base);
    }
  }
  void LazyUpdateNode(int s) {
    add[s * 2] += add[s];
    add[s * 2 + 1] += add[s];
    valmax[s * 2] += add[s];
    valmax[s * 2 + 1] += add[s];
    valmin[s * 2] += add[s];
    valmin[s * 2 + 1] += add[s];
    add[s] = 0;
  }
  void AfterUpdate(int s) {
    valmax[s] = max(valmax[s * 2], valmax[s * 2 + 1]);
    valmin[s] = min(valmin[s * 2], valmin[s * 2 + 1]);
  }
  long long GetMaxNode(int s, int l, int h) {
    if (l <= low[s] && high[s] <= h) {
      return valmax[s];
    }
    LazyUpdateNode(s);
    long long ans = 0;
    if (l <= high[s * 2]) ans = max(ans, GetMaxNode(s * 2, l, h));
    if (h > high[s * 2]) ans = max(ans, GetMaxNode(s * 2 + 1, l, h));
    return ans;
  }
  long long GetMinNode(int s, int l, int h) {
    if (l <= low[s] && high[s] <= h) {
      return valmin[s];
    }
    LazyUpdateNode(s);
    long long ans = INF;
    if (l <= high[s * 2]) ans = min(ans, GetMinNode(s * 2, l, h));
    if (h > high[s * 2]) ans = min(ans, GetMinNode(s * 2 + 1, l, h));
    return ans;
  }
  void AddRangeNode(int s, int l, int h, long long v) {
    if (l <= low[s] && high[s] <= h) {
      add[s] += v;
      valmax[s] += v;
      valmin[s] += v;
      return;
    }
    LazyUpdateNode(s);
    if (l <= high[s * 2]) AddRangeNode(s * 2, l, h, v);
    if (h > high[s * 2]) AddRangeNode(s * 2 + 1, l, h, v);
    AfterUpdate(s);
  }
  void UpdateNode(int s, int p, long long v) {
    if (low[s] == high[s]) {
      valmax[s] = v;
      valmin[s] = v;
      return;
    }
    LazyUpdateNode(s);
    if (p <= high[s * 2])
      UpdateNode(s * 2, p, v);
    else
      UpdateNode(s * 2 + 1, p, v);
    AfterUpdate(s);
  }
  int GetPosMaxNode(int s, int l, int h) {
    if (low[s] == high[s]) {
      return low[s];
    } else {
      if (l <= high[s * 2]) {
        if (h > high[s * 2]) {
          return (GetMaxNode(s * 2, l, h) >= GetMaxNode(s * 2 + 1, l, h)
                      ? GetPosMaxNode(s * 2, l, h)
                      : GetPosMaxNode(s * 2 + 1, l, h));
        }
        return GetPosMaxNode(s * 2, l, h);
      }
      return GetPosMaxNode(s * 2 + 1, l, h);
    }
  }
  int GetPosMinNode(int s, int l, int h) {
    if (low[s] == high[s]) {
      return low[s];
    } else {
      if (l <= high[s * 2]) {
        if (h > high[s * 2]) {
          return (GetMinNode(s * 2, l, h) <= GetMinNode(s * 2 + 1, l, h)
                      ? GetPosMinNode(s * 2, l, h)
                      : GetPosMinNode(s * 2 + 1, l, h));
        }
        return GetPosMinNode(s * 2, l, h);
      }
      return GetPosMinNode(s * 2 + 1, l, h);
    }
  }
  void AddRange(int l, int h, long long v) { AddRangeNode(1, l, h, v); }
  long long GetMin(int l, int h) { return GetMinNode(1, l, h); }
  long long GetMax(int l, int h) { return GetMaxNode(1, l, h); }
  int GetPosMin(int l, int h) { return GetPosMinNode(1, l, h); }
  int GetPosMax(int l, int h) { return GetPosMaxNode(1, l, h); }
  void Update(int p, long long v) { UpdateNode(1, p, v); }
  void Init(int n, long long base) {
    memset(add, 0, sizeof(add));
    BuildNode(1, 1, n, base);
  }
};
long long w[MAXN];
vector<int> edges[MAXN];
int n, MaxLength;
long long MaxWeight;
int cnt = 0;
int h[MAXN], lft[MAXN], rgt[MAXN], dp[MAXN], s[MAXN];
vector<pair<int, int> > st;
IntervalTree IT, WIT;
void NumberTree(int u, int h) {
  lft[u] = ++cnt;
  st.push_back(make_pair(h, u));
  for (int i = 0; i < edges[u].size(); ++i) {
    NumberTree(edges[u][i], h + 1);
  }
  rgt[u] = cnt;
}
int main() {
  cin >> n >> MaxLength >> MaxWeight;
  for (int i = 1; i <= n; ++i) {
    cin >> w[i];
  }
  for (int i = 2; i <= n; ++i) {
    int p;
    cin >> p;
    edges[p].push_back(i);
  }
  int root = 1, height = 0;
  NumberTree(root, height);
  sort(st.begin(), st.end());
  IT.Init(n, INF);
  WIT.Init(n, 0);
  for (int i = int(st.size()) - 1; i >= 0; --i) {
    int u = st[i].second, h = st[i].first;
    s[u] = 0;
    for (int j = 0; j < edges[u].size(); ++j) {
      int v = edges[u][j];
      s[u] += dp[v];
    }
    WIT.AddRange(lft[u], rgt[u], w[u]);
    while (WIT.GetMax(lft[u], rgt[u]) > MaxWeight) {
      int p = WIT.GetPosMax(lft[u], rgt[u]);
      IT.Update(p, INF);
      WIT.Update(p, 0);
    }
    while (st.back().first - h >= MaxLength) {
      int v = st.back().second;
      IT.Update(lft[v], INF);
      st.pop_back();
    }
    dp[u] = (w[u] <= MaxWeight ? 1 : INF) + s[u];
    if (lft[u] < rgt[u]) {
      dp[u] = min((long long)dp[u], IT.GetMin(lft[u] + 1, rgt[u]) + 1 + s[u]);
    }
    if (dp[u] >= INF) {
      cout << -1;
      return 0;
    }
    WIT.Update(lft[u], w[u]);
    IT.Update(lft[u], 0);
    IT.AddRange(lft[u], rgt[u], s[u] - dp[u]);
  }
  cout << dp[1] << endl;
  return 0;
}

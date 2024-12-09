#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e3 + 10;
;
long long vis[maxn][maxn];
struct Edge {
  long long v, w, next;
} e[maxn << 1];
struct Ans {
  long long u, v, w;
} ans[maxn << 2];
long long Cnt;
long long head[maxn];
long long cnt;
void add(long long u, long long v, long long w) {
  e[cnt].v = v;
  e[cnt].w = w;
  e[cnt].next = head[u];
  head[u] = cnt++;
}
long long de[maxn];
int findnode(long long u, long long f) {
  if (de[u] == 1) return u;
  for (long long i = head[u]; ~i; i = e[i].next) {
    long long v = e[i].v;
    if (v == f) continue;
    return findnode(v, u);
  }
}
void solve(long long u, long long v, long long w) {
  vector<int> vec[2];
  if (de[u] == 1) {
    vec[0].push_back(u);
  } else {
    for (long long i = head[u]; ~i; i = e[i].next) {
      if (e[i].v == v) continue;
      vec[0].push_back(findnode(e[i].v, u));
      if (vec[0].size() == 2) break;
    }
  }
  if (de[v] == 1) {
    vec[1].push_back(v);
  } else {
    for (long long i = head[v]; ~i; i = e[i].next) {
      if (e[i].v == u) continue;
      vec[1].push_back(findnode(e[i].v, v));
      if (vec[1].size() == 2) break;
    }
  }
  if (vec[0].size() == 1) {
    if (vec[1].size() == 1)
      ans[++Cnt] = (Ans){vec[0][0], vec[1][0], w};
    else {
      ans[++Cnt] = (Ans){vec[0][0], vec[1][0], w / 2};
      ans[++Cnt] = (Ans){vec[0][0], vec[1][1], w / 2};
      ans[++Cnt] = (Ans){vec[1][0], vec[1][1], -w / 2};
    }
  } else {
    if (vec[1].size() == 1) {
      ans[++Cnt] = (Ans){vec[1][0], vec[0][0], w / 2};
      ans[++Cnt] = (Ans){vec[1][0], vec[0][1], w / 2};
      ans[++Cnt] = (Ans){vec[0][0], vec[0][1], -w / 2};
    } else {
      ans[++Cnt] = (Ans){vec[1][0], vec[0][0], w / 2};
      ans[++Cnt] = (Ans){vec[1][1], vec[0][1], w / 2};
      ans[++Cnt] = (Ans){vec[0][0], vec[0][1], -w / 2};
      ans[++Cnt] = (Ans){vec[1][0], vec[1][1], -w / 2};
    }
  }
}
int main() {
  long long n;
  scanf("%lld", &n);
  memset(head, -1, sizeof(head));
  for (long long i = 1; i < n; i++) {
    long long u, v, w;
    scanf("%lld%lld%lld", &u, &v, &w);
    add(u, v, w);
    add(v, u, w);
    de[u]++;
    de[v]++;
  }
  for (long long i = 1; i <= n; i++) {
    if (de[i] == 2) {
      puts("NO");
      return 0;
    }
  }
  for (long long u = 1; u <= n; u++) {
    for (long long i = head[u]; ~i; i = e[i].next) {
      long long v = e[i].v;
      if (vis[u][v]) continue;
      vis[u][v] = vis[v][u] = 1;
      solve(u, v, e[i].w);
    }
  }
  puts("YES");
  printf("%lld\n", Cnt);
  for (long long i = 1; i <= Cnt; i++) {
    printf("%lld %lld %lld\n", ans[i].u, ans[i].v, ans[i].w);
  }
}

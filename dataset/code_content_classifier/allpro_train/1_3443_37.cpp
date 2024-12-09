#include <bits/stdc++.h>
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
using namespace std;

typedef unsigned long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)

#define pb push_back
#define mp make_pair
#define st first
#define nd second

const int MOD = 1000000007;

int N;
vector<int> adj[105];

int D[105];
void compute_distances(vector<int> r) {
  REP(i,N) D[i] = -1;

  queue<int> Q;
  for (int v: r) {
    Q.push(v);
    D[v] = 0;
  }
  while (!Q.empty()) {
    int v = Q.front();
    Q.pop();
    for (int u: adj[v]) if (D[u] == -1) {
      D[u] = D[v] + 1;
      Q.push(u);
    }
  }
}

pair<LL, LL> go(vector<int> r) {
  compute_distances(r);
  vector<vector<int>> by_distance(N+1);
  REP(i,N) by_distance[D[i]].pb(i);
  LL result = by_distance[0].size();
  int depth = 1;
  REP(i,N+1) {
    int m = 0;
    for (int v: by_distance[i]) {
      m = max(m, (int)adj[v].size() - (i > 0 ? 1 : (int)r.size() - 1));
    }
    if (m == 0) break;
    depth = i + 2;
    result *= m;
  }

  return pair<LL,LL>{depth, result};
}

int main() {
  // ios_base::sync_with_stdio(0);

  scanf("%d", &N);
  REP(i,N-1) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  pair<LL, LL> res(~0ULL, ~0ULL);
  REP(i,N) res = min(res, go({i}));
  REP(u,N) for (auto v: adj[u]) res = min(res, go({u, v}));
  printf("%lld %lld\n", res.st, res.nd);
}

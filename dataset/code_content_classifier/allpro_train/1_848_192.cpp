#include <bits/stdc++.h>

using namespace std;

int N;

using pii = pair<int, int>;

int par[123123];

int get(int x) {
  return par[x] == x ? x : (par[x] = get(par[x]));
}

int main() {
  scanf("%d", &N);
  vector<pii> xs, ys;
  for(int i = 0; i < N; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    xs.emplace_back(x, i);
    ys.emplace_back(y, i);    
    par[i] = i;
  }
  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());

  vector<tuple<int, int, int>> edges;
  for(int i = 1; i < N; i++) {
    edges.emplace_back(xs[i].first - xs[i-1].first, xs[i-1].second, xs[i].second);
    edges.emplace_back(ys[i].first - ys[i-1].first, ys[i-1].second, ys[i].second);
  }

  sort(edges.begin(), edges.end());
  long long ans = 0;
  for(auto it : edges) {
    int c, u, v; tie(c, u, v) = it;
    u = get(u); v = get(v);
    if(u != v) {
      ans += c;
      par[u] = v;
    }
  }
  printf("%lld\n", ans);

  return 0;
}
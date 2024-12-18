#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const int MAXN = 3100;
vector<int> par[MAXN];
vector<int> child[MAXN];
int backw;
int maxsave;
int minsave;
int cursave;
void go(int x, int from) {
  int prmin = minsave;
  minsave = min(minsave, cursave);
  maxsave = max(maxsave, cursave - minsave);
  vector<int> &p = par[x];
  for (int i = 0; i < int((p).size()); ++i) {
    if (p[i] == from) {
      continue;
    }
    cursave++;
    backw++;
    go(p[i], x);
    cursave--;
  }
  vector<int> &c = child[x];
  for (int i = 0; i < int((c).size()); ++i) {
    if (c[i] == from) {
      continue;
    }
    cursave--;
    go(c[i], x);
    cursave++;
  }
  minsave = prmin;
}
int N;
int main() {
  scanf("%d", &N);
  for (int i = 1; i < N; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    par[b].push_back(a);
    child[a].push_back(b);
  }
  int ans = inf;
  for (int i = 0; i < N; ++i) {
    backw = maxsave = cursave = minsave = 0;
    go(i, -1);
    ans = min(ans, backw - maxsave);
  }
  printf("%d\n", ans);
  return 0;
}

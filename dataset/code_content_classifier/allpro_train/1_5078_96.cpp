#include <bits/stdc++.h>
using namespace std;
struct edge {
  int to, c;
  edge() {}
  edge(int to, int c) : to(to), c(c) {}
};
vector<edge> v[105];
int dp[105][105][31][2];
bool dpf(int i, int j, int bound, int k) {
  int &ret = dp[i][j][bound][k];
  if (ret != -1) return ret;
  ret = k;
  if (k)
    for (edge next : v[j]) {
      if (next.c >= bound) ret &= dpf(i, next.to, next.c, 0);
    }
  else
    for (edge next : v[i]) {
      if (next.c >= bound) ret |= dpf(next.to, j, next.c, 1);
    }
  return ret;
}
int main() {
  memset(dp, -1, sizeof dp);
  int N, M, a, b;
  char c;
  scanf("%d %d", &N, &M);
  while (M--) {
    scanf("%d %d %c", &a, &b, &c);
    v[a].emplace_back(b, c - 'a');
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      printf("%c", dpf(i, j, -1, 0) ? 'A' : 'B');
    }
    puts("");
  }
}

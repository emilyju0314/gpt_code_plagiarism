#include <bits/stdc++.h>
using namespace std;
int n, k, a[20];
int x[20], y[20], z[20];
bool f[65536][2005];
priority_queue<pair<int, int> > Q;
pair<int, int> tmp[20];
void output(int d) {
  int T = 0;
  for (int i = (int)(d); i >= (int)(0); i--) {
    int S = x[i] + y[i];
    for (; S != z[i]; S /= k, ++T)
      ;
    Q.push(pair<int, int>(T, y[i]));
  }
  puts("YES");
  for (int i = (int)(1); i <= (int)(d); i++) {
    pair<int, int> x = Q.top();
    Q.pop();
    pair<int, int> y = Q.top();
    Q.pop();
    assert(x.first == y.first);
    printf("%d %d\n", x.second, y.second);
    x.second += y.second;
    for (; x.second % k == 0; x.second /= k, --x.first)
      ;
    Q.push(x);
  }
  exit(0);
}
void dfs(int sta, int S, int d) {
  if (sta == (1 << n) - 1) {
    if (S == 1) output(d - 1);
    return;
  }
  if (f[sta][S]) return;
  for (int i = (int)(0); i <= (int)(n - 1); i++)
    if (!(sta & (1 << i))) {
      int nS = 0;
      x[d] = S;
      y[d] = a[i];
      z[d] = S + a[i];
      for (;;) {
        dfs(sta | (1 << i), z[d], d + 1);
        if (z[d] % k) break;
        z[d] /= k;
      }
    }
  f[sta][S] = 1;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = (int)(0); i <= (int)(n - 1); i++) scanf("%d", &a[i]);
  dfs(0, 0, 0);
  puts("NO");
}

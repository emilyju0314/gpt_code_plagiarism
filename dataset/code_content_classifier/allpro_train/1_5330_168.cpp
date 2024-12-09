#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
bool edge[N][N];
int n, m, f[N];
int gf(int x) { return x == f[x] ? x : f[x] = gf(f[x]); }
int main() {
  int x, y;
  scanf("%d%d", &n, &m);
  int cnt = 0, num = n;
  for (int i = 0; i < (n); i++) f[i + 1] = i + 1;
  for (int i = 0; i < (m); i++) {
    scanf("%d%d", &x, &y);
    if (edge[x][y]) continue;
    cnt++;
    edge[x][y] = edge[y][x] = 1;
    int fx = gf(x);
    int fy = gf(y);
    if (fx != fy) {
      f[fx] = fy;
      num--;
    }
  }
  bool yes = cnt == n - 1 && num == 1;
  printf(yes ? "yes" : "no");
  puts("");
  return 0;
}

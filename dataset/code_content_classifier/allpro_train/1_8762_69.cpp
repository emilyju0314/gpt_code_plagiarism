#include <bits/stdc++.h>
using namespace std;
const int maxC = 999999999;
string s, t;
int n, k, res, x, y, cost[505][505], f[505][505], g[505][505];
int cal(int x, int y) {
  int len = y - x + 1, res = 0;
  for (int i = 0; i < len / 2; i++)
    if (s[x + i] != s[y - i]) res++;
  return res;
}
void compute_cost() {
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++) cost[i][j] = cal(i, j);
}
string take(int x, int y) {
  string res = "";
  int len = y - x + 1;
  for (int i = x - 1; i < y; i++) res += s[i];
  for (int i = 0; i < len / 2; i++) res[len - 1 - i] = res[i];
  return res;
}
int main() {
  if (0) {
    freopen("a.inp", "r", stdin);
  };
  getline(cin, s);
  n = s.length();
  scanf("%d", &k);
  compute_cost();
  for (int i = 1; i <= n; i++) f[i][0] = maxC;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= k; j++) {
      f[i][j] = maxC;
      for (int x = 1; x <= i; x++)
        if (f[x - 1][j - 1] + cost[x - 1][i - 1] < f[i][j]) {
          f[i][j] = f[x - 1][j - 1] + cost[x - 1][i - 1];
          g[i][j] = x - 1;
        }
    }
  res = maxC;
  for (int i = 1; i <= k; i++)
    if (f[n][i] < res) {
      res = f[n][i];
      y = i;
    }
  printf("%d\n", res);
  t = "";
  x = n;
  while (y) {
    t = take(g[x][y] + 1, x) + "+" + t;
    x = g[x][y];
    y--;
  }
  t.erase(t.length() - 1, 1);
  cout << t << endl;
}

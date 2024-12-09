#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000 + 10;
int n, ans, mo;
int x[MAXN], y[MAXN], cl[MAXN];
vector<double> edges[MAXN];
double mtx[MAXN][MAXN];
bool mark[MAXN];
void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
}
void cald() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      mtx[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
      mtx[j][i] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
    }
}
void dfs(int u, double mindis) {
  mark[u] = true;
  for (int v = 0; v < n; v++) {
    if (!mark[v] && mtx[u][v] > mindis) {
      cl[v] = cl[u] ^ 1;
      dfs(v, mindis);
    } else if (mark[v] && mtx[u][v] > mindis) {
      if (cl[v] == cl[u]) throw 1;
    }
  }
}
bool DFS_ALL(double mindis) {
  memset(mark, false, MAXN);
  memset(cl, 0, MAXN);
  mo = 0;
  bool jav = true;
  try {
    for (int i = 0; i < n; i++)
      if (!mark[i]) {
        cl[i] = 0;
        mo++;
        dfs(i, mindis);
      }
    return jav;
  } catch (int x) {
    return false;
  }
}
double check(double mindis) { return DFS_ALL(mindis); }
void bs() {
  int start = -1, end = 20000 + 100;
  while (end - start > 1) {
    int mid = (start + end) / 2;
    if (check(mid)) {
      end = mid;
      ans = mid;
    } else {
      start = mid;
    }
  }
  check(ans);
}
void output() {
  cout << ans << endl;
  int moAs = 1;
  for (int i = 0; i < mo; i++) {
    moAs *= 2;
    moAs %= 1000000000 + 7;
  }
  cout << moAs << endl;
}
int main() {
  input();
  cald();
  bs();
  output();
  return 0;
}

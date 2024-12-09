#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
const int dx[5] = {0, 1, -1, 0, 0};
const int dy[5] = {0, 0, 0, -1, 1};
int n, m;
long long k, need;
int a[MAXN][MAXN];
bool can[MAXN][MAXN], vis[MAXN][MAXN];
queue<pair<int, int> > dl;
void input_LL(long long &r) {
  r = 0;
  char t = getchar();
  while (!isdigit(t)) t = getchar();
  long long sign = 1;
  if (t == '-') sign = -1;
  while (!isdigit(t)) t = getchar();
  while (isdigit(t)) r = r * 10 + t - '0', t = getchar();
  r = r * sign;
}
void input_int(int &r) {
  r = 0;
  char t = getchar();
  while (!isdigit(t)) t = getchar();
  int sign = 1;
  if (t == '-') sign = -1;
  while (!isdigit(t)) t = getchar();
  while (isdigit(t)) r = r * 10 + t - '0', t = getchar();
  r = r * sign;
}
bool bfs(int x, int y) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) vis[i][j] = false;
  dl.push(make_pair(x, y));
  long long now = 1;
  vis[x][y] = true;
  if (now == need) return true;
  while (!dl.empty()) {
    int x0 = dl.front().first, y0 = dl.front().second;
    dl.pop();
    for (int i = 1; i <= 4; i++) {
      int x1 = x0 + dx[i], y1 = y0 + dy[i];
      if (x1 <= 0 || x1 >= n + 1 || y1 <= 0 || y1 >= m + 1) continue;
      if (!vis[x1][y1]) {
        if (a[x1][y1] < a[x][y]) continue;
        if (a[x1][y1] == a[x][y]) can[x1][y1] = false;
        vis[x1][y1] = true;
        now++;
        if (now == need) return true;
        dl.push(make_pair(x1, y1));
      }
    }
  }
  return false;
}
int main() {
  input_int(n);
  input_int(m);
  input_LL(k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) input_int(a[i][j]), can[i][j] = true;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (can[i][j] && a[i][j] > 0 && !(k % a[i][j])) {
        need = k / a[i][j];
        if (need > n * m) continue;
        if (bfs(i, j)) {
          puts("YES");
          for (int ii = 1; ii <= n; ii++) {
            for (int jj = 1; jj <= m; jj++)
              if (vis[ii][jj])
                printf("%d%c", a[i][j], jj == m ? '\n' : ' ');
              else
                printf("0%c", jj == m ? '\n' : ' ');
          }
          return 0;
        }
      }
  puts("NO");
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;
const char ch[2] = {'.', '#'};
int n, m, N, M, ref_r[MAXN], ref_c[MAXN], r[MAXN], c[MAXN];
char str[MAXN][MAXN], a[MAXN][MAXN];
bool Del_r[MAXN], Del_c[MAXN];
void init() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; ++i) scanf("%s", str[i] + 1);
  for (int i = 1; i <= M; ++i) str[N + 1][i] = '.';
}
bool empty_r(int i) {
  for (int j = 1; j <= M; ++j)
    if (str[i][j] == '#') return false;
  return true;
}
bool check_r(int a, int b) {
  for (int j = 1; j <= M; ++j)
    if ((str[b][j] == '#' && str[a][j] == '.' && str[a + 1][j] == '#') ||
        (str[b][j] == '#' && str[a][j] == '#' && str[a + 1][j] == '.') ||
        (str[b][j] == '.' && str[a][j] == '#' && str[a + 1][j] == '.') ||
        (str[b][j] == '.' && str[a][j] == '#' && str[a + 1][j] == '#'))
      return false;
  return true;
}
bool ext_r(int i) {
  for (int j = 1; j <= M; ++j)
    if (str[i][j] == '#') return true;
  return false;
}
void Delete_r() {
  int pre = 1, cnt = 0;
  for (int i = 1; i <= N; ++i) cnt += ext_r(i);
  for (; empty_r(pre) && pre <= N; Del_r[pre++] = true)
    ;
  if (pre > N) puts("NO"), exit(0);
  for (; empty_r(N) && N >= 1; Del_r[N--] = true)
    ;
  ref_r[pre] = ++n, r[n] = pre;
  for (int i = pre + 1; i <= N; ++i) {
    if (empty_r(i)) {
      Del_r[i] = true;
      continue;
    }
    if (check_r(i, pre) && !(cnt <= 5 && ext_r(i)) && (N - i + 1) > 7 - n)
      Del_r[i] = true, cnt -= ext_r(i);
    else
      pre = i, ref_r[i] = ++n, r[n] = i;
  }
}
bool empty_c(int j) {
  for (int i = 1; i <= n; ++i)
    if (str[i][j] == '#') return false;
  return true;
}
bool check_c(int a, int b) {
  for (int i = 1; i <= n; ++i)
    if ((str[i][b] == '#' && str[i][a] == '.' && str[i][a + 1] == '#') ||
        (str[i][b] == '#' && str[i][a] == '#' && str[i][a + 1] == '.') ||
        (str[i][b] == '.' && str[i][a] == '#' && str[i][a + 1] == '.') ||
        (str[i][b] == '.' && str[i][a] == '#' && str[i][a + 1] == '#'))
      return false;
  return true;
}
bool ext_c(int j) {
  for (int i = 1; i <= n; ++i)
    if (str[i][j] == '#') return true;
  return false;
}
void Delete_c() {
  int pre = 1, cnt = 0;
  for (int i = 1; i <= M; ++i) cnt += ext_c(i);
  for (; empty_c(pre) && pre <= M; Del_c[pre++] = true)
    ;
  for (; empty_c(M) && M >= 1; Del_c[M--] = true)
    ;
  ref_c[pre] = ++m, c[m] = pre;
  for (int i = pre + 1; i <= M; ++i) {
    if (empty_c(i)) {
      Del_c[i] = true;
      continue;
    }
    if (check_c(i, pre) && !(cnt <= 5 && ext_c(i)) && (M - i + 1) > 7 - m)
      Del_c[i] = true, cnt -= ext_c(i);
    else
      pre = i, ref_c[i] = ++m, c[m] = i;
  }
}
bool check(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy) {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (ch[(i == ax && j >= ay && j <= by) ||
             (i == bx && j >= ay && j <= by) ||
             (i == cx && j >= cy && j <= dy) ||
             (i == dx && j >= cy && j <= dy) ||
             (j == ay && i >= ax && i <= bx) ||
             (j == by && i >= ax && i <= bx) ||
             (j == cy && i >= cx && i <= dx) ||
             (j == dy && i >= cx && i <= dx)] != a[i][j])
        return false;
  return true;
}
void solve() {
  Delete_r();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= M; ++j) a[i][j] = str[r[i]][j];
  if (n > 7) puts("NO"), exit(0);
  memcpy(str, a, sizeof(a));
  for (int i = 1; i <= n; ++i) str[i][M + 1] = '.';
  Delete_c();
  memset(a, 0, sizeof(a));
  int cnt = 0;
  for (int j = 1; j <= m; ++j)
    for (int i = 1; i <= n; ++i) a[i][j] = str[i][c[j]], cnt += a[i][j] == '#';
  if (m > 7 || cnt > 46) puts("NO"), exit(0);
  if (cnt == n * m && n <= 4 && m <= 4) {
    r[2] = r[1] + 1, r[n - 1] = r[n] - 1, c[2] = c[1] + 1, c[m - 1] = c[m] - 1;
  }
  for (int ax = 1; ax <= n; ++ax)
    for (int ay = 1; ay <= m; ++ay)
      if (a[ax][ay] == '#')
        for (int bx = ax; bx <= n; ++bx)
          if (abs(r[ax] - r[bx]) >= 2)
            for (int by = ay; by <= m; ++by)
              if (abs(c[ay] - c[by]) >= 2 && a[bx][by] == '#')
                for (int cx = 1; cx <= n; ++cx)
                  for (int cy = 1; cy <= m; ++cy)
                    if (a[cx][cy] == '#')
                      for (int dx = cx; dx <= n; ++dx)
                        if (abs(r[cx] - r[dx]) >= 2)
                          for (int dy = cy; dy <= m; ++dy)
                            if (abs(c[cy] - c[dy]) >= 2 && a[dx][dy] == '#') {
                              if (check(ax, ay, bx, by, cx, cy, dx, dy))
                                cout << "YES" << endl
                                     << r[ax] << " " << c[ay] << " " << r[bx]
                                     << " " << c[by] << endl
                                     << r[cx] << " " << c[cy] << " " << r[dx]
                                     << " " << c[dy] << endl,
                                    exit(0);
                            }
  puts("NO");
}
int main() {
  init();
  solve();
  fclose(stdin);
  fclose(stdout);
  return 0;
}

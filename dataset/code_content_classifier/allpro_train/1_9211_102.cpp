#include <bits/stdc++.h>
using namespace std;
int sg[100050][4], n, m, Sx, Sy, Dir, st, ln[100050 * 4][4];
char b[3];
bool c[100050 * 4], d[100050 * 4][2];
long long cnt, ans;
inline int Sg(int x, int y) {
  if (x == 1)
    return sg[y][0];
  else if (x == n)
    return sg[y][1];
  else if (y == 1)
    return sg[x][2];
  else
    return sg[x][3];
}
inline void Line(int x, int y, int z, int o) {
  int e = ln[x][0] ? 2 : 0;
  ln[x][e] = Sg(y, z);
  ln[x][e + 1] = o;
}
inline void DR(int x, int y, int z) {
  int e = min(n - x, m - y), k = x + e, l = y + e;
  Line(z, k, l, e);
}
inline void UR(int x, int y, int z) {
  int e = min(x - 1, m - y), k = x - e, l = y + e;
  Line(z, k, l, e);
}
inline void DL(int x, int y, int z) {
  int e = min(n - x, y - 1), k = x + e, l = y - e;
  Line(z, k, l, e);
}
inline void UL(int x, int y, int z) {
  int e = min(x - 1, y - 1), k = x - e, l = y - e;
  Line(z, k, l, e);
}
void Set_up() {
  sg[1][0] = sg[1][2] = 1;
  sg[1][1] = sg[n][2] = 2;
  sg[m][0] = sg[1][3] = 3;
  sg[m][1] = sg[n][3] = st = 4;
  for (int i = 2; i < n; i++) sg[i][2] = ++st, sg[i][3] = ++st;
  for (int i = 2; i < m; i++) sg[i][0] = ++st, sg[i][1] = ++st;
  DR(1, 1, 1);
  DL(1, m, 3);
  UR(n, 1, 2);
  UL(n, m, 4);
  for (int i = 2; i < n; i++)
    DR(i, 1, sg[i][2]), UR(i, 1, sg[i][2]), DL(i, m, sg[i][3]),
        UL(i, m, sg[i][3]);
  for (int i = 2; i < m; i++)
    DR(1, i, sg[i][0]), DL(1, i, sg[i][0]), UR(n, i, sg[i][1]),
        UL(n, i, sg[i][1]);
}
long long DFS(int x, int y) {
  if (!c[x]) c[x] = true, cnt--;
  if (!cnt) return 0;
  for (int i = 0; i < 3 && ln[x][i]; i += 2)
    if (ln[x][i] != y && !d[x][i / 2]) {
      d[x][i / 2] = true;
      return DFS(ln[x][i], x == st ? ln[x][2] : x) + ln[x][i + 1];
    }
  if (!ln[x][2] && !d[x][0]) {
    d[x][0] = true;
    return DFS(ln[x][0], x) + ln[x][1];
  }
  puts("-1");
  exit(0);
}
void Solve() {
  int k = 0;
  st++;
  bool flag = (Sx + Sy) & 1;
  if (Sx == n && Sy == m) b[0] = 'U', b[1] = 'L';
  if (Sx == 1 && Sy == m) b[0] = 'D', b[1] = 'L';
  if (Sx == n && Sy == 1) b[0] = 'U', b[1] = 'R';
  if (Sx == 1 && Sy == 1) b[0] = 'D', b[1] = 'R';
  if (b[0] == 'D' && b[1] == 'R')
    DR(Sx, Sy, st), UL(Sx, Sy, st);
  else if (b[0] == 'D')
    DL(Sx, Sy, st), UR(Sx, Sy, st);
  else if (b[1] == 'R')
    UR(Sx, Sy, st), DL(Sx, Sy, st);
  else
    UL(Sx, Sy, st), DR(Sx, Sy, st);
  for (int i = 1; i <= m; i++)
    cnt += flag == ((1 + i) & 1), cnt += flag == ((n + i) & 1);
  for (int i = 2; i < n; i++)
    cnt += flag == ((1 + i) & 1), cnt += flag == ((m + i) & 1);
  cnt++;
  if (Sx == 1 || Sy == 1 || Sx == n || Sy == m) cnt--, c[Sg(Sx, Sy)] = true;
  ans = DFS(st, ln[st][2]);
  printf("%I64d\n", ans + 1);
  return;
}
int main() {
  cin >> n >> m >> Sx >> Sy >> b;
  Set_up();
  Solve();
  return 0;
}

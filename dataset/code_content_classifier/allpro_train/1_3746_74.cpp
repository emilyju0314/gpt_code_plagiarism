#include <bits/stdc++.h>
using namespace std;
int T[4][5][2] = {{{0, 0}, {0, 1}, {0, 2}, {1, 1}, {2, 1}},
                  {{0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 2}},
                  {{0, 1}, {1, 1}, {2, 0}, {2, 1}, {2, 2}},
                  {{0, 0}, {1, 0}, {1, 1}, {1, 2}, {2, 0}}};
int prec[10][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},   {0, 0, 0, 1, 1, 2, 2, 3, 3, 4},
    {0, 0, 0, 1, 2, 2, 3, 4, 4, 5},   {0, 0, 0, 2, 2, 4, 4, 5, 6, 7},
    {0, 0, 0, 2, 3, 4, 5, 6, 7, 8},   {0, 0, 0, 3, 4, 5, 6, 8, 9, 10},
    {0, 0, 0, 3, 4, 6, 7, 9, 10, 12}, {0, 0, 0, 4, 5, 7, 8, 10, 12, 13}};
char ans[9][9];
char cur[9][9];
int n, m;
int cnt, mx;
bool isok(int r, int c, int i) {
  for (typeof(0) j = (0); j < (5); j++) {
    int xx = r + T[i][j][0], yy = c + T[i][j][1];
    if ((xx < 0) || (xx >= n) || (yy < 0) || (yy >= m))
      return false;
    else if (cur[xx][yy] != '.')
      return false;
  }
  return true;
}
int counter = 0;
int rend[4] = {3, 2, 1, 0};
void solve(int r, int c) {
  if (counter) return;
  if (r == n) {
    if (cnt >= mx) {
      mx = cnt;
      for (typeof(0) i = (0); i < (n); i++)
        for (typeof(0) j = (0); j < (m); j++) ans[i][j] = cur[i][j];
    }
    if (mx == prec[n][m]) {
      counter = 1;
    }
    return;
  }
  if (c == m) {
    solve(r + 1, 0);
    return;
  } else {
    for (typeof(0) id = (0); id < (4); id++) {
      int i = id;
      if (isok(r, c, i)) {
        for (typeof(0) j = (0); j < (5); j++) {
          int xx = r + T[i][j][0], yy = c + T[i][j][1];
          cur[xx][yy] = 'A' + cnt;
        }
        cnt++;
        solve(r, c + 1);
        for (typeof(0) j = (0); j < (5); j++) {
          int xx = r + T[i][j][0], yy = c + T[i][j][1];
          cur[xx][yy] = '.';
        }
        cnt--;
      }
    }
    solve(r, c + 1);
  }
}
int main() {
  cin >> n >> m;
  cnt = 0, mx = 0;
  counter = 0;
  for (typeof(0) i = (0); i < (9); i++)
    for (typeof(0) j = (0); j < (9); j++) cur[i][j] = '.';
  if (n == 9 && m == 9) {
    cout << "13\n"
            "AAA.BCCC.\n"
            ".ABBB.CD.\n"
            ".AE.BFCD.\n"
            "EEEFFFDDD\n"
            "G.E.HFIII\n"
            "GGGJHHHI.\n"
            "GK.JHL.IM\n"
            ".KJJJLMMM\n"
            "KKK.LLL.M\n";
  } else if ((m == 8 && n == 9)) {
    cout << "12\n"
            "AAA.BCCC\n"
            ".ABBBDC.\n"
            "EA.FBDC.\n"
            "EEEFDDDG\n"
            "EHFFFGGG\n"
            ".HHHIIIG\n"
            "JHKKKIL.\n"
            "JJJK.IL.\n"
            "J..K.LLL\n";
  } else if ((n == 8) && (m == 9)) {
    cout << "12\n"
            "AAABBB..C\n"
            ".AD.BECCC\n"
            ".AD.BEEEC\n"
            "FDDDGEHHH\n"
            "FFFIGGGH.\n"
            "FJ.IGK.HL\n"
            ".JIIIKLLL\n"
            "JJJ.KKK.L\n";
  } else {
    solve(0, 0);
    cout << mx << "\n";
    for (typeof(0) i = (0); i < (n); i++) {
      for (typeof(0) j = (0); j < (m); j++) cout << ans[i][j];
      cout << "\n";
    }
  }
  return 0;
}

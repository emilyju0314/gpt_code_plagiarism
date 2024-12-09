#include <bits/stdc++.h>
using namespace std;
const int N = 1011;
int xz[4] = {0, 1, 0, -1}, yz[4] = {1, 0, -1, 0};
vector<pair<int, int> > s[N * N];
int n, m, bel[N][N], tot = 0;
char M[N][N];
void print() {
  for (int i = (1); i <= (tot); i++)
    if (s[i].size()) {
      int tmp[10] = {};
      for (pair<int, int> p : s[i]) {
        for (int h = (0); h <= (3); h++) {
          int x = p.first + xz[h], y = p.second + yz[h];
          if (bel[x][y] && M[x][y] != '.') tmp[M[x][y] - '0'] = 1;
        }
      }
      int col = 0;
      while (tmp[col] == 1 && col <= 9) col++;
      assert(col != 10);
      for (pair<int, int> p : s[i]) M[p.first][p.second] = '0' + col;
    }
  for (int i = (1); i <= (n); i++) {
    for (int j = (1); j <= (m); j++) printf("%c", M[i][j]);
    printf("\n");
  }
}
int main() {
  cin >> n >> m;
  for (int i = (1); i <= (n); i++) {
    scanf("%s", M[i] + 1);
    for (int j = (1); j <= (m); j++)
      if (M[i][j] == '.') {
        bel[i][j] = ++tot;
        s[tot].push_back(pair<int, int>(i, j));
      }
  }
  for (int i = (1); i <= (n); i++) {
    for (int j = (1); j <= (m); j++)
      if (M[i][j] == '.') {
        int t = bel[i][j];
        if (s[t].size() == 1) {
          s[t].pop_back();
          int tmp = 0;
          for (int h = (0); h <= (3); h++) {
            int x = i + xz[h], y = j + yz[h];
            int tt = bel[x][y];
            if (tt == 0) continue;
            if (!tmp || s[tt].size() < s[tmp].size()) tmp = tt;
          }
          if (tmp == 0) {
            printf("-1\n");
            return 0;
          }
          s[tmp].push_back(pair<int, int>(i, j));
          bel[i][j] = tmp;
        }
      }
  }
  print();
  return 0;
}

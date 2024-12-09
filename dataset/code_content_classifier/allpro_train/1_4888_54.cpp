#include <bits/stdc++.h>
using namespace std;
int main() {
  enum color_type { WHITE, BOTH, BLACK };
  int n, m, a, b, c;
  cin >> n >> m >> a >> b >> c;
  vector<vector<int> > ans(n, vector<int>(m, -1));
  auto nex = [&](int &x, int &y) -> void {
    if (y + 1 == m)
      ++x, y = 0;
    else
      ++y;
  };
  auto paint = [&](int x, int y, color_type c) -> void {
    if (c == WHITE) {
      ans[x][y] = 1;
      return;
    }
    if (c == BLACK) {
      ans[x][y] = 0;
      return;
    }
    color_type up = BOTH, dn = BOTH, lf = BOTH, rg = BOTH;
    if (x && ans[x - 1][y] != -1)
      up = ans[x - 1][y] == 0 || ans[x - 1][y] == 3 || ans[x - 1][y] == 4
               ? BLACK
               : WHITE;
    if (y && ans[x][y - 1] != -1)
      lf = ans[x][y - 1] == 0 || ans[x][y - 1] == 2 || ans[x][y - 1] == 3
               ? BLACK
               : WHITE;
    if (x + 1 < n && ans[x + 1][y] != -1)
      dn = ans[x + 1][y] == 0 || ans[x + 1][y] == 2 || ans[x + 1][y] == 5
               ? BLACK
               : WHITE;
    if (y + 1 < m && ans[x][y + 1] != -1)
      rg = ans[x][y + 1] == 0 || ans[x][y + 1] == 4 || ans[x][y + 1] == 5
               ? BLACK
               : WHITE;
    color_type up_dn = BOTH, lf_rg = BOTH;
    if (up != BOTH) up_dn = up;
    if (dn != BOTH) up_dn = dn == BLACK ? WHITE : BLACK;
    if (lf != BOTH) lf_rg = lf;
    if (rg != BOTH) lf_rg = rg == BLACK ? WHITE : BLACK;
    if (up_dn != WHITE && lf_rg != WHITE)
      ans[x][y] = 5;
    else if (up_dn != WHITE && lf_rg == WHITE)
      ans[x][y] = 2;
    else if (up_dn == WHITE && lf_rg != WHITE)
      ans[x][y] = 4;
    else if (up_dn == WHITE && lf_rg == WHITE)
      ans[x][y] = 3;
    else
      cerr << "?" << endl;
  };
  int x = 0, y = 0;
  for (int i = 0; i < (int)(a); ++i) {
    paint(x, y, BLACK);
    nex(x, y);
  }
  int ox = x, oy = y;
  for (int i = 0; i < (int)(m); ++i) nex(x, y);
  for (int i = 0; i < (int)(b); ++i) {
    paint(x, y, WHITE);
    nex(x, y);
  }
  for (int ny = oy; ny < m; ++ny) {
    paint(ox, ny, BOTH);
  }
  for (int ny = oy - 1; ny >= 0; --ny) {
    paint(ox + 1, ny, BOTH);
  }
  for (int i = 0; i < (int)(c - m); ++i) {
    paint(x, y, BOTH);
    nex(x, y);
  }
  const vector<string> a1 = {"##", "..", "\\#", "./", "\\.", "#/"};
  const vector<string> a2 = {"##", "..", ".\\", "/#", "#\\", "/."};
  for (int i = 0; i < (int)(n); ++i) {
    for (int j = 0; j < (int)(m); ++j) printf("%s", a1[ans[i][j]].c_str());
    printf("\n");
    for (int j = 0; j < (int)(m); ++j) printf("%s", a2[ans[i][j]].c_str());
    printf("\n");
  }
  return 0;
}

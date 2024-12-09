#include <bits/stdc++.h>
using namespace std;
char mat[101][101];
pair<char, int> ac[101][101];
int n, m;
void preenche(int x0, int y0, int x1, int y1, char val) {
  for (int i = x0; i <= x1; ++i) {
    for (int j = y0; j <= y1; ++j) {
      mat[i][j] = val;
    }
  }
}
bool check(int currx, int curry, char& letter, int qnt) {
  for (int i = 'A'; i <= 'Z'; ++i) {
    if (i == letter && qnt == (n - currx)) {
      qnt = 0;
      continue;
    }
    bool ok = true;
    if (currx > 0 && mat[currx - 1][curry] == i) {
      ok = false;
    }
    if (!qnt && curry > 0 && mat[currx][curry - 1] == i) {
      ok = false;
    }
    if (curry < m && mat[currx][curry + 1] == i) {
      ok = false;
    }
    if (ok) {
      bool ret = (i != letter);
      letter = i;
      return ret;
    }
  }
  return false;
}
void solve() {
  char letter = 'A';
  for (int i = 0; i < n; ++i) {
    check(i, 0, letter, 0);
    int cont = 1;
    if (mat[i][0] == -1) mat[i][0] = letter;
    for (int j = 1; j < m; ++j) {
      if (mat[i][j] != -1) {
        letter = mat[i][j];
        cont = 0;
        continue;
      }
      char oldletter = letter;
      bool ret = check(i, j, letter, cont);
      if (!ret) {
        cont++;
      } else {
        preenche(i, j - cont, i + cont - 1, j - 1, oldletter);
        cont = 1;
      }
      mat[i][j] = letter;
    }
    preenche(i, m - cont, i + cont - 1, m - 1, letter);
  }
}
int main(void) {
  cin >> n >> m;
  memset(mat, -1, sizeof mat);
  solve();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << mat[i][j];
    }
    cout << "\n";
  }
  return 0;
}

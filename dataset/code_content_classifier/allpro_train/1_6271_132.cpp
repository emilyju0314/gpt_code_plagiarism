#include <bits/stdc++.h>
using namespace std;
char s[8][50];
int ed[8];
int h[66];
char ans[100][100];
char te[100][100];
int sx, sy, tx, ty;
bool cmp() {
  for (int i = 0; i < max(sx, tx); i++)
    for (int j = 0; j < max(sy, ty); j++)
      if (ans[i][j] != te[i][j]) return ans[i][j] > te[i][j];
  return 0;
}
void ok() {
  if (sx == -1 || cmp()) {
    sx = tx;
    sy = ty;
    for (int i = 0; i < sx; i++)
      for (int j = 0; j < sy; j++) ans[i][j] = te[i][j];
  }
}
void pri() {
  for (int i = 0; i < tx; i++, putchar(10))
    for (int j = 0; j < ty; j++) putchar(te[i][j]);
}
int main() {
  for (int i = 0; i < 6; i++) gets(s[i]), ed[i] = strlen(s[i]);
  for (int i = 0; i < 6; i++) h[i] = i;
  sx = -1;
  do {
    int a = ed[h[0]], b = ed[h[1]], c = ed[h[5]], d = ed[h[4]];
    if (ed[h[3]] == a + c - 1 && ed[h[2]] == b + d - 1) {
      bool f = 1;
      ty = a + c - 1;
      tx = b + d - 1;
      for (int i = 0; i < tx; i++)
        for (int j = 0; j < ty; j++) te[i][j] = '.';
      for (int i = 0; i < tx; i++) te[i][ty] = 0;
      for (int i = 0; i <= ty; i++) te[tx][i] = 0;
      for (int i = 0; i < ed[h[0]]; i++)
        if (te[0][i] == '.' || te[0][i] == s[h[0]][i])
          te[0][i] = s[h[0]][i];
        else
          f = 0;
      for (int i = 0; i < ed[h[1]]; i++)
        if (te[i][0] == '.' || te[i][0] == s[h[1]][i])
          te[i][0] = s[h[1]][i];
        else
          f = 0;
      for (int i = 0; i < ed[h[2]]; i++)
        if (te[i][a - 1] == '.' || te[i][a - 1] == s[h[2]][i])
          te[i][a - 1] = s[h[2]][i];
        else
          f = 0;
      for (int i = 0; i < ed[h[3]]; i++)
        if (te[b - 1][i] == '.' || te[b - 1][i] == s[h[3]][i])
          te[b - 1][i] = s[h[3]][i];
        else
          f = 0;
      for (int i = 0; i < ed[h[4]]; i++)
        if (te[i + b - 1][a + c - 2] == '.' ||
            te[i + b - 1][a + c - 2] == s[h[4]][i])
          te[i + b - 1][a + c - 2] = s[h[4]][i];
        else
          f = 0;
      for (int i = 0; i < ed[h[5]]; i++)
        if (te[b + d - 2][i + a - 1] == '.' ||
            te[b + d - 2][i + a - 1] == s[h[5]][i])
          te[b + d - 2][i + a - 1] = s[h[5]][i];
        else
          f = 0;
      if (f) ok();
    }
  } while (next_permutation(h, h + 6));
  if (sx == -1)
    puts("Impossible");
  else {
    for (int i = 0; i < sx; i++, putchar(10))
      for (int j = 0; j < sy; j++) putchar(ans[i][j]);
  }
  return 0;
}

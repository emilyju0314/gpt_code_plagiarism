#include <bits/stdc++.h>
int n, m, num;
char tab[100][100];
int xx[10000][4];
int yy[10000][4];
int ch[100][100];
int id[100][100];
int getdir(int cd, int dd) {
  if (cd == 1)
    return (dd + 1) % 4;
  else
    return dd;
}
int main() {
  scanf("%d %d", &n, &num);
  for (int i = 0; i < n; i++) {
    scanf("%s", tab[i]);
    m = strlen(tab[i]);
    for (int j = 0; j < m; j++) {
      tab[i][j] -= '0';
    }
  }
  int count = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (tab[i][j] == 0) {
        id[i][j] = 0;
        continue;
      }
      if (i - 1 >= 0 && tab[i - 1][j] == tab[i][j]) {
        id[i][j] = id[i - 1][j];
      } else if (j - 1 >= 0 && tab[i][j - 1] == tab[i][j]) {
        id[i][j] = id[i][j - 1];
      } else {
        id[i][j] = count++;
        xx[id[i][j]][0] = i;
        yy[id[i][j]][0] = j;
        xx[id[i][j]][1] = i;
        yy[id[i][j]][3] = j;
      }
      if ((i + 1 >= n || tab[i][j] != tab[i + 1][j]) &&
          (j + 1 >= m || tab[i][j] != tab[i][j + 1])) {
        yy[id[i][j]][1] = j;
        xx[id[i][j]][3] = i;
        xx[id[i][j]][2] = i;
        yy[id[i][j]][2] = j;
      }
    }
  }
  int tx, ty, cd = 0, dd = 1;
  int pos = id[tx][ty];
  for (int p = 0; p < num; p++) {
    int dir = getdir(cd, dd);
    tx = xx[pos][dir];
    ty = yy[pos][dir];
    int dx, dy;
    if (dd == 0) {
      dx = -1;
      dy = 0;
    }
    if (dd == 1) {
      dx = 0;
      dy = 1;
    }
    if (dd == 2) {
      dx = 1;
      dy = 0;
    }
    if (dd == 3) {
      dx = 0;
      dy = -1;
    }
    if (tx + dx < 0 || tx + dx >= n || ty + dy < 0 || ty + dy >= m ||
        id[tx + dx][ty + dy] == 0) {
      if (cd == 0) {
        cd = 1;
      } else {
        cd = 0;
        dd += 1;
        dd %= 4;
      }
    } else {
      pos = id[tx + dx][ty + dy];
      tx += dx;
      ty += dy;
    }
  }
  printf("%d\n", tab[tx][ty]);
}

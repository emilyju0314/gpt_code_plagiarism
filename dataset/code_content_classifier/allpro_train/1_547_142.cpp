#include <bits/stdc++.h>
int rgt[50002][52];
int rgtid[50002][52];
int nexts[50002][27];
int recent[27];
int n;
int INF = 1000000007;
int best[52];
int bestid[52];
char rds[50002];
int blen = 0;
char sols[52];
int main() {
  scanf("%s", rds);
  while (rds[n] != '\0') n++;
  for (int i = 0; i < 51; i++) best[i] = -INF + 1;
  for (int i = 0; i < 27; i++) recent[i] = -INF;
  for (int i = 0; i < n; i++) {
    recent[(int)(rds[i] - 'a')] = i;
    for (int j = 0; j < 27; j++) nexts[i][j] = recent[j];
  }
  for (int j = 1; j < 51; j++) {
    for (int i = 0; i < n; i++) rgt[i][j] = -INF;
    int rightmost = -INF;
    int opts;
    for (int i = 0; i < n; i++) {
      if (j == 1) {
        if (rgt[i][1] <= nexts[n - 1][(int)(rds[i] - 'a')]) {
          rgt[i][1] = nexts[n - 1][(int)(rds[i] - 'a')];
          rgtid[i][1] = -INF;
        }
      } else {
        if (rightmost >= 0 && i < rightmost) {
          if (i <= nexts[rightmost - 1][(int)(rds[i] - 'a')]) {
            rgt[i][j] = nexts[rightmost - 1][(int)(rds[i] - 'a')];
            rgtid[i][j] = opts;
          }
        }
        if (rightmost < rgt[i][j - 1]) {
          rightmost = rgt[i][j - 1];
          opts = i;
        }
      }
    }
  }
  int opts = 0;
  int optsst = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < 51; j++) {
      if (rgt[i][j] >= 0) {
        if (i < rgt[i][j]) {
          if (opts < j + j) {
            opts = j + j;
            optsst = i;
          }
        } else {
          if (opts < j + j - 1) {
            opts = j + j - 1;
            optsst = i;
          }
        }
      }
    }
  }
  int nw = 0;
  int k = (opts + 1) / 2;
  while (1) {
    if (optsst < 0) break;
    sols[nw] = rds[optsst];
    optsst = rgtid[optsst][k];
    k--;
    nw++;
  }
  for (int i = nw - 1; i >= 0; i--) printf("%c", sols[i]);
  if (opts % 2 == 0) printf("%c", sols[0]);
  for (int i = 1; i < nw; i++) printf("%c", sols[i]);
  printf("\n");
  return 0;
}

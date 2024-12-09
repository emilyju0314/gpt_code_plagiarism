#include <bits/stdc++.h>
int s[3000], a[3000][3000], last[3000][30], e[3000], d[3000][3000];
int main() {
  int n, i, k, j;
  char ch;
  ch = fgetc(stdin);
  n = 0;
  while (ch != '\n') {
    s[++n] = ch - 'a';
    for (i = 0; i < 26; i++) {
      last[n][i] = last[n - 1][i];
    }
    last[n][s[n]] = n;
    ch = fgetc(stdin);
  }
  ch = fgetc(stdin);
  k = 0;
  while (ch != '\n') {
    e[++k] = ch - 'a';
    ch = fgetc(stdin);
  }
  for (i = 1; i <= n; i++) {
    a[i][1] = last[i][e[1]];
    for (j = 2; j <= k; j++) {
      a[i][j] = a[last[i][e[j]] - 1][j - 1];
    }
  }
  for (i = 0; i <= n; i++) {
    d[i][0] = d[0][i] = -100000000;
  }
  d[0][0] = 0;
  for (i = 1; i <= n; i++) {
    if ((a[i][k] > 0) && (a[i][k] == i - k + 1)) {
      d[i][0] = d[i - k][0] + 1;
    } else {
      d[i][0] = d[i - 1][0];
    }
    for (j = 1; j <= n; j++) {
      d[i][j] = d[i - 1][j];
      if (d[i][j] < d[i - 1][j - 1]) {
        d[i][j] = d[i - 1][j - 1];
      }
      if ((a[i][k] > 0) && (j >= i - a[i][k] + 1 - k) &&
          (d[i][j] < 1 + d[a[i][k] - 1][j - (i - a[i][k] + 1 - k)])) {
        d[i][j] = 1 + d[a[i][k] - 1][j - (i - a[i][k] + 1 - k)];
      }
    }
  }
  for (i = 0; i <= n; i++) {
    fprintf(stdout, "%d ", d[n][i]);
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}

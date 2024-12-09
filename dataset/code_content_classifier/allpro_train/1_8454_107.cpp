#include <bits/stdc++.h>
using namespace std;
int n, m, a[45], o[45], n2, q[2][45][2], wq[2], out;
bool f1(int x, int y) { return a[x] < a[y]; }
bool check() {
  q[0][0][1] = 0;
  wq[0] = 1;
  q[1][0][1] = 0;
  wq[1] = 1;
  for (int i = m - 1; i >= 0; i--) {
    q[0][wq[0]][0] = i;
    q[0][wq[0]][1] = q[0][wq[0] - 1][1] + a[i];
    if (q[0][wq[0]][1] >= n2) {
      a[i] = q[0][wq[0]][1] - n2;
      q[0][wq[0]][1] = n2;
      if (a[i] == 0) i--;
      if (i < 0) return false;
      if (n & 1) {
        if (i == q[0][1][0]) i--;
        if (i < 0) return false;
        out = i;
        a[i]--;
      }
      if (a[i] == 0) i--;
      if (i < 0) return false;
      for (i; i >= 0; i--) {
        q[1][wq[1]][0] = i;
        q[1][wq[1]][1] = q[1][wq[1] - 1][1] + a[i];
        if ((wq[1] == 1) && (q[1][wq[1]][0] == q[0][wq[0]][0]) &&
            (q[1][wq[1]][1] >= q[0][wq[0] - 1][1]))
          q[1][wq[1]][1] = max(0, q[0][wq[0] - 1][1] - 1);
        if (q[1][wq[1]][1] >= n2) {
          if (n & 1) {
            if (out == q[1][wq[1]][0]) {
              i--;
              if (i < 0) return false;
              out = i;
            }
          }
          return true;
        }
        wq[1]++;
      }
    }
    wq[0]++;
  }
  return false;
}
int main() {
  scanf("%d%d", &n, &m);
  n2 = n >> 1;
  for (int i = 0; i < m; i++) {
    scanf("%d", &a[i]);
    o[i] = i;
  }
  sort(o, o + m, f1);
  sort(a, a + m);
  if (check()) {
    for (int i = 0, j = 1, k = 1; i < n2; i++) {
      if (q[0][j][1] <= i) j++;
      if (i != 0) printf(" ");
      printf("%d", o[q[0][j][0]] + 1);
      if (q[1][k][1] <= i) k++;
      printf(" ");
      printf("%d", o[q[1][k][0]] + 1);
    }
    if (n & 1) printf(" %d", o[out] + 1);
    printf("\n");
  } else {
    printf("-1\n");
  }
  return 0;
}

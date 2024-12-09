#include <bits/stdc++.h>
using namespace std;
int ncr(int n, int p) {
  if (n == p || p == 0) {
    return 1;
  } else {
    return ncr(n - 1, p) + ncr(n - 1, p - 1);
  }
}
int main() {
  int n, m, i, j, t, cnt;
  long long int s = 0;
  int ara[1000];
  int a[1000];
  char str[1000][1001];
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%s", str[i]);
    cnt = 0;
    for (j = 0; j < m; j++) {
      if (str[i][j] == '*') {
        cnt++;
      }
    }
    ara[i] = cnt;
  }
  for (i = 0; i < m; i++) {
    cnt = 0;
    for (j = 0; j < n; j++) {
      if (str[j][i] == '*') {
        cnt++;
      }
    }
    a[i] = cnt;
  }
  for (i = 0; i < m; i++) {
    if (a[i] > 1) {
      for (j = 0; j < n; j++) {
        if (str[j][i] == '*') {
          if (ara[j] - 1 > 0) {
            s = s + (a[i] - 1) * (ara[j] - 1);
          }
        }
      }
    }
  }
  cout << s;
  return 0;
}

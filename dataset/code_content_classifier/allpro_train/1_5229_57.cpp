#include <bits/stdc++.h>
int bin_search(int n, int m, int a, int *b, int *p);
int minimize(int r, int n, int a, int *b, int *p);
int main() {
  int n, m, a;
  int b[100005], p[100005];
  int r, s;
  scanf("%d %d %d", &n, &m, &a);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &p[i]);
  }
  std::sort(b, b + n);
  std::sort(p, p + m);
  r = bin_search(n, m, a, b, p);
  s = minimize(r, n, a, b, p);
  printf("%d %d", r, s);
  return 0;
}
int bin_search(int n, int m, int a, int *b, int *p) {
  int li = 0, ls = n < m ? n : m;
  int sol = -1;
  while (li <= ls) {
    int mij = (li + ls) / 2;
    int sum = a;
    for (int i = mij - 1, j = n - 1; i >= 0 && sum >= 0; --i, --j) {
      if (b[j] < p[i]) {
        sum -= p[i] - b[j];
      }
    }
    if (sum >= 0) {
      sol = mij;
      li = mij + 1;
    } else {
      ls = mij - 1;
    }
  }
  return sol;
}
int minimize(int r, int n, int a, int *b, int *p) {
  int sum = 0;
  for (int i = r - 1, j = n - 1; i >= 0; --i, --j) {
    if (b[j] < p[i]) {
      sum += b[j];
      a -= p[i] - b[j];
    } else {
      sum += p[i];
    }
  }
  sum -= a;
  return sum > 0 ? sum : 0;
}

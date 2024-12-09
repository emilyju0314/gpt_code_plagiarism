#include <bits/stdc++.h>
inline int read() {
  int x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + c - 48, c = getchar();
  return x;
}
const int N = 1e3 + 7;
int n, a[N], id[N], invid[N], ans[N][N];
void print() {
  for (int i = 1; i <= n + 1; ++i) {
    for (int j = 1; j <= n; ++j) printf("%d", ans[i][invid[j]]);
    puts("");
  }
}
bool cmp(int x, int y) { return a[x] > a[y]; }
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) a[i] = read(), id[i] = i;
  std::sort(id + 1, id + 1 + n, cmp);
  for (int i = 1; i <= n; ++i) invid[id[i]] = i;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= a[id[i]]; ++j) {
      ans[j + i - 1 > n + 1 ? j + i - 1 - n - 1 : j + i - 1][i] = 1;
    }
  }
  printf("%d\n", n + 1);
  print();
  return 0;
}

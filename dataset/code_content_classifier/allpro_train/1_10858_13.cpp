#include <bits/stdc++.h>
using namespace std;
int Read() {
  char c;
  while (c = getchar(), (c != '-') && (c < '0' || c > '9'))
    ;
  bool neg = (c == '-');
  int ret = (neg ? 0 : c - 48);
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + c - 48;
  return neg ? -ret : ret;
}
int K, M, a[10005];
void DFS(int d, int s, int l, int pre) {
  if (!M) return;
  if (d > 3) {
    if (d == 4 && abs(s - K) <= 9999 && a[abs(s - K)] != pre)
      printf("%04d%04d\n", pre, abs(K - s)), a[abs(s - K)] = pre, --M;
    return;
  }
  DFS(d + 1, l % 10 + s, l / 10, pre), DFS(d + 1, l % 10 * s, l / 10, pre),
      DFS(d + 1, s - (l % 10), l / 10, pre);
  DFS(d + 2, l % 100 + s, l / 100, pre), DFS(d + 2, l % 100 * s, l / 100, pre),
      DFS(d + 2, s - (l % 100), l / 100, pre);
}
int main() {
  scanf("%d%d", &K, &M), memset(a, -1, sizeof(a));
  for (int i = 0; i <= 9999; i++)
    DFS(1, i % 10, i / 10, i), DFS(2, i % 100, i / 100, i);
  return 0.0;
}

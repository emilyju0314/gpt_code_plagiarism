#include <bits/stdc++.h>
using namespace std;
const int maxn = 110, maxp = 5050;
inline long long rd() {
  long long x = 0;
  char c = getchar();
  int neg = 1;
  while (c < '0' || c > '9') {
    if (c == '-') neg = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * neg;
}
int N, M, pos[maxn][maxp], cnt[maxn], pct;
int main() {
  int i, j, k;
  N = rd(), M = rd();
  for (i = 1; i <= N; i++) pos[i][cnt[i] = 1] = ++pct;
  for (i = 1; i <= M; i++) {
    int a = rd(), b = rd();
    pos[a][++cnt[a]] = pos[b][++cnt[b]] = ++pct;
  }
  for (i = 1; i <= N; i++) {
    printf("%d\n", cnt[i]);
    for (j = 1; j <= cnt[i]; j++) printf("%d %d\n", i, pos[i][j]);
  }
  return 0;
}

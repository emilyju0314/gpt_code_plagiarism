#include <bits/stdc++.h>
const int MAXN = 1000;
int d[MAXN];
int main(int argc, char const *argv[]) {
  int m, k;
  scanf("%d%d", &m, &k);
  int r = 0;
  int t = 0;
  int s, ms = 0;
  for (int i = 0; i < m; ++i) {
    scanf("%d", d + i);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &s);
    ms = s > ms ? s : ms;
    t += s;
    while (t < d[i]) {
      r += k;
      t += ms;
    }
    r += d[i];
    t -= d[i];
  }
  printf("%d\n", r);
  return 0;
}

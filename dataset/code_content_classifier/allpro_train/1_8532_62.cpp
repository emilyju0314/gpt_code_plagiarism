#include <bits/stdc++.h>
using namespace std;
const int maxn = 312345;
int pos[maxn], dir[maxn], rk[maxn];
int ans[maxn];
long long t;
int n, m;
bool cmp(const int &a, const int &b) { return pos[a] < pos[b]; }
int main() {
  scanf("%d%d%I64d", &n, &m, &t);
  t %= (long long)n * m;
  for (int i = 1; i <= n; i++) {
    char ch[5];
    scanf("%d %s", &pos[i], ch);
    pos[i]--;
    dir[i] = ('L' == ch[0]) ? -1 : 1;
    rk[i] = i;
  }
  sort(rk + 1, rk + 1 + n, cmp);
  int s = 0;
  for (int i = 1; i <= n; i++) {
    if (1 == dir[i])
      s = (s - (pos[i] + t) / m) % n;
    else
      s = (s + (t - pos[i] - 1 + m) / m) % n;
    pos[i] = ((pos[i] + dir[i] * t) % m + m) % m;
  }
  s = (s + n) % n;
  sort(pos + 1, pos + 1 + n);
  rotate(rk + 1, rk + 1 + s, rk + 1 + n);
  for (int i = 1; i <= n; i++) ans[rk[i]] = pos[i] + 1;
  for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
  return 0;
}

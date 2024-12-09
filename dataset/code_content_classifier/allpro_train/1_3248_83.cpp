#include <bits/stdc++.h>
using namespace std;
struct node {
  long long flag, x;
};
long long min1[2000010], sum[2000010], a[2000010], p[2000010], b[2000010],
    ch[2000010][2], endpos[2000010], len[2000010], tot = 1, lp = 1, fa[2000010];
char s[2000010];
void build(long long num, long long r, long long l) {
  if (r == l) {
    min1[num] = sum[r];
    p[num] = 1;
    return;
  }
  long long mid = (r + l) / 2;
  build(num * 2, r, mid);
  build(num * 2 + 1, mid + 1, l);
  min1[num] = min(min1[num * 2], min1[num * 2 + 1]);
  p[num] = (min1[num * 2] == min1[num] ? p[num * 2] : 0) +
           (min1[num * 2 + 1] == min1[num] ? p[num * 2 + 1] : 0);
}
void insert(long long x) {
  long long np = ++tot, j;
  len[np] = len[lp] + 1;
  endpos[np] = x;
  long long p = lp;
  while (!ch[p][a[x]] && p) {
    ch[p][a[x]] = np;
    p = fa[p];
  }
  if (!p)
    fa[np] = 1;
  else {
    long long h = ch[p][a[x]];
    if (len[h] == len[p] + 1)
      fa[np] = h;
    else {
      long long Np = ++tot;
      fa[Np] = fa[h];
      fa[h] = Np;
      len[Np] = len[p] + 1;
      fa[np] = Np;
      endpos[Np] = endpos[h];
      for (j = 0; j <= 1; j++) ch[Np][j] = ch[h][j];
      while (ch[p][a[x]] == h && p) {
        ch[p][a[x]] = Np;
        p = fa[p];
      }
    }
  }
  lp = np;
}
node find(long long num, long long r, long long l, long long x, long long y,
          long long z) {
  node ans;
  ans.x = ans.flag = 0;
  if (r == l) {
    if (min1[num] == z) ans.x = 1;
    if (min1[num] < z) ans.flag = 1;
    return ans;
  }
  if (x <= r && l <= y) {
    long long mid = (r + l) / 2;
    if (min1[num * 2 + 1] < z)
      ans = find(num * 2 + 1, mid + 1, l, x, y, z);
    else {
      if (min1[num * 2 + 1] == z) ans.x += p[num * 2 + 1];
      if (min1[num * 2] < z)
        ans.x += find(num * 2, r, mid, x, y, z).x;
      else if (min1[num * 2] == z)
        ans.x += p[num * 2];
    }
    if (min1[num] < z) ans.flag = 1;
    return ans;
  }
  long long mid = (r + l) / 2;
  if (mid < y) ans = find(num * 2 + 1, mid + 1, l, x, y, z);
  if (!ans.flag && x <= mid) {
    node h = find(num * 2, r, mid, x, y, z);
    ans.x += h.x;
    ans.flag = h.flag;
  }
  return ans;
}
bool check(long long num, long long r, long long l, long long x, long long y,
           long long z) {
  if (x <= r && l <= y) return min1[num] >= z;
  long long mid = (r + l) / 2;
  bool ans = 1;
  if (x <= mid) ans &= check(num * 2, r, mid, x, y, z);
  if (mid < y) ans &= check(num * 2 + 1, mid + 1, l, x, y, z);
  return ans;
}
signed main() {
  long long n, i, ans = 0;
  scanf("%lld", &n);
  scanf("%s", s);
  for (i = n; i >= 1; i--) {
    a[i] = (s[i - 1] == '(' ? 1 : 0);
    sum[i] = (s[i - 1] == '(' ? -1 : 1) + sum[i + 1];
  }
  build(1, 1, n);
  for (i = 1; i <= n; i++) insert(i);
  for (i = 2; i <= tot; i++) {
    long long c = check(1, 1, n, endpos[i] - len[fa[i]] + 1, endpos[i],
                        sum[endpos[i] + 1]);
    if (c)
      ans += find(1, 1, n, endpos[i] - len[i] + 1, endpos[i] - len[fa[i]],
                  sum[endpos[i] + 1])
                 .x;
  }
  printf("%lld\n", ans);
}

#include <bits/stdc++.h>
using namespace std;
const int maxlen = 3100000;
const int maxn = 50010;
struct Segment {
  int l;
  char *s;
} strs[maxn << 2];
;
int tot;
char s[maxlen];
int k;
int n, l[maxn], r[maxn];
char ans[maxlen];
int split(int pos) {
  for (int i = 0; i < tot; i++)
    if (pos == 0) {
      tot++;
      for (int k = tot - 1; k > i; k--) strs[k] = strs[k - 1];
      return i;
    } else if (strs[i].l <= pos)
      pos -= strs[i].l;
    else {
      tot += 2;
      for (int k = tot - 1; k > i + 1; k--) strs[k] = strs[k - 2];
      strs[i + 2].l = strs[i].l - pos;
      strs[i + 2].s = strs[i].s + pos;
      strs[i].l = pos;
      return i + 1;
    }
  return tot++;
}
void getans(int h, int t) {
  int l = 0;
  for (int i = 0; t >= 0 && i < tot; i++)
    if (strs[i].l <= h) {
      h -= strs[i].l;
      t -= strs[i].l;
    } else {
      for (int k = max(0, h); k < strs[i].l && k <= t; k++)
        ans[l++] = strs[i].s[k];
      int D = min(strs[i].l, t);
      h -= D;
      t -= D;
    }
}
void construct(int d, int length) {
  if (d < 0) {
    Segment key;
    key.l = length;
    key.s = s + 1;
    strs[tot++] = key;
    return;
  }
  if (r[d] >= length) {
    construct(d - 1, length);
    return;
  }
  int C = r[d] - l[d] + 1;
  if (r[d] + C >= length) {
    construct(d - 1, r[d]);
    Segment key;
    key.l = length - r[d];
    key.s = new char[key.l];
    int C_2 = C / 2;
    int D = (key.l >= C_2) ? C : (key.l * 2);
    getans(l[d], l[d] + D - 1);
    for (int i = 0; i < key.l; i++)
      if (i < C_2)
        key.s[i] = ans[i + i + 1];
      else
        key.s[i] = ans[(i - C_2) << 1];
    strs[tot++] = key;
  } else {
    construct(d - 1, length - C);
    int pos = split(r[d] + 1);
    Segment key;
    key.l = C;
    key.s = new char[C];
    int C_2 = C / 2;
    getans(l[d], r[d]);
    for (int i = 0; i < C; i++)
      if (i < C_2)
        key.s[i] = ans[i + i + 1];
      else
        key.s[i] = ans[(i - C_2) << 1];
    strs[pos] = key;
  }
}
int main() {
  scanf("%s%d", s + 1, &k);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &l[i], &r[i]);
  tot = 1;
  strs[0].l = 1;
  strs[0].s = new char[1];
  strs[0].s[0] = ' ';
  construct(n - 1, k);
  getans(0, k);
  ans[k + 1] = 0;
  printf("%s\n", ans + 1);
  return 0;
}

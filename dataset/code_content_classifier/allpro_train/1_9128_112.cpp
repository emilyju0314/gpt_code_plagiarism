#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int cnt[N * 2], n, st = N;
char s[N];
bool chk(int p) {
  int now = st;
  memset(cnt, 0, sizeof(cnt));
  cnt[now] = 1;
  for (register int i = (1); i <= (n); ++i) {
    if (s[i] == 'L' && now - 1 != p) now--;
    if (s[i] == 'R' && now + 1 != p) now++;
    cnt[now]++;
  }
  if (cnt[now] == 1 && now != p) return 1;
  return 0;
}
signed main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  if (chk(0)) {
    printf("1\n");
    return 0;
  }
  int now = st, L = 0, R = 0, _ans = 0;
  for (register int i = (1); i <= (n); ++i) {
    if (s[i] == 'L') now--;
    if (s[i] == 'R') now++;
    L = min(L, now);
    R = max(R, now);
  }
  int l = L, r = st - 1, ans = st, mid;
  while (l <= r) {
    mid = l + r >> 1;
    if (chk(mid))
      r = mid - 1, ans = mid;
    else
      l = mid + 1;
  }
  _ans += st - ans;
  l = st + 1, r = R, ans = st;
  while (l <= r) {
    mid = l + r >> 1;
    if (chk(mid))
      l = mid + 1, ans = mid;
    else
      r = mid - 1;
  }
  _ans += ans - st;
  printf("%d\n", _ans);
  return 0;
}

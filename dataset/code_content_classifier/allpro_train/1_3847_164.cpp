#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 1e3;
int s[MAXN];
int nn, mm;
int n, cnt;
int a[MAXN];
int tmp[MAXN];
int ans[MAXN];
inline int lowbit(int x) { return x & (-x); }
void modify(int x, int k) {
  for (int i = x; i <= n; i += lowbit(i)) s[i] += k;
}
int ask(int x) {
  int sum = 0;
  for (int i = x; i; i -= lowbit(i)) sum += s[i];
  return sum;
}
void init() {
  memset(s, 0, sizeof(s));
  cnt = 0;
}
void Input() {
  for (int i = 1; i <= mm; ++i) scanf("%d", a + i);
  n = nn;
}
void work() {
  int t;
  for (int i = 1; i <= nn; i++) {
    scanf("%d", &t);
    if (t == -1) {
      int num = 0;
      for (int j = 1; j <= mm; ++j) {
        int l = 0, r = cnt;
        if (ask(r) < a[j]) break;
        while (l < r) {
          int mid = (l + r) >> 1;
          if (ask(mid) >= a[j]) {
            r = mid;
          } else {
            l = mid + 1;
          }
        }
        tmp[++num] = r;
      }
      for (int i = 1; i <= num; ++i) modify(tmp[i], -1);
    } else {
      ans[++cnt] = t;
      modify(cnt, 1);
    }
  }
  int flag = 1;
  for (int i = 1; i <= cnt; ++i) {
    if (ask(i) - ask(i - 1) == 1) {
      flag = 0;
      printf("%d", ans[i]);
    }
  }
  if (flag) printf("Poor stack!");
  printf("\n");
}
int main() {
  while (~scanf("%d%d", &nn, &mm)) {
    init();
    Input();
    work();
  }
  return 0;
}

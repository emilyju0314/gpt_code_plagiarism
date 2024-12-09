#include <bits/stdc++.h>
using namespace std;
int n, m, lst;
char str[305];
int modify(int l, int r) { return 0; }
pair<int, int> query(int l, int r) {
  printf("? %d %d\n", l, r);
  fflush(stdout);
  int x = modify(l, r);
  scanf("%d", &x);
  if (!((lst ^ r ^ x) & 1)) {
    lst = x;
    return pair<int, int>(x, 0);
  } else {
    lst = x;
    return pair<int, int>(x, 1);
  }
}
char ans[305];
void solve_even() {
  int last2 = 0;
  for (int i = 1; i <= n; i++) {
    bool v1 = 0, v2 = 0;
    int x;
    while (v1 != 1 || v2 != 0) {
      pair<int, int> t = query(i, i);
      if (!t.second)
        v1 ^= 1;
      else
        v2 ^= 1;
      x = t.first;
    }
    x = ((m - x + i) >> 1);
    ans[i] = x - last2 + '0';
    last2 = x;
    while (v1 != 0 || v2 != 0) {
      pair<int, int> t = query(i, i);
      if (!t.second)
        v1 ^= 1;
      else
        v2 ^= 1;
    }
  }
  printf("! %s\n", ans + 1);
}
void solve_odd() {
  if (n == 1) {
    printf("! %d\n", m);
    return;
  }
  int last2 = 0, s = m;
  for (int i = 2; i <= n; i++) {
    bool v1 = 0, v2 = 0;
    int x;
    while (v1 != 1 || v2 != 0) {
      pair<int, int> t = query(i - 1, i);
      if (!t.second)
        v1 ^= 1;
      else
        v2 ^= 1;
      x = t.first;
    }
    x = ((m - x + i) >> 1);
    if (i > 2) ans[i] = x - last2 + '0', s -= x - last2;
    last2 = x;
    while (v1 != 0 || v2 != 0) {
      pair<int, int> t = query(i - 1, i);
      if (!t.second)
        v1 ^= 1;
      else
        v2 ^= 1;
    }
  }
  bool v1 = 0, v2 = 0;
  int x;
  while (v1 != 0 || v2 != 1) {
    pair<int, int> t = query(2, n);
    if (!t.second)
      v1 ^= 1;
    else
      v2 ^= 1;
    x = t.first;
  }
  x = ((m - x + n - 1) >> 1);
  ans[1] = m - x + '0', s -= m - x;
  ans[2] = s + '0';
  printf("! %s\n", ans + 1);
}
int main() {
  scanf("%d%d", &n, &m);
  lst = m;
  if (n & 1)
    solve_odd();
  else
    solve_even();
  return 0;
}

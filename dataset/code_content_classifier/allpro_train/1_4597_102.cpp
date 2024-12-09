#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    int s, f, t;
    scanf("%d%d%d", &s, &f, &t);
    if (s == f)
      printf("%d\n", t);
    else {
      int tm = t % (m - 1), tt = t / (m - 1);
      int cur = 0;
      if (tt % 2 == 0)
        cur = tm + 1;
      else
        cur = m - tm;
      if (cur <= s && tt % 2 == 0 || cur >= s && tt % 2 == 1)
        cur = abs(s - cur);
      else {
        if (tt % 2 == 0)
          cur = m - s + m - cur;
        else
          cur = s - 1 + cur - 1;
      }
      t += cur;
      tm = t % (m - 1), tt = t / (m - 1);
      if (tt % 2 == 0 && f > s || tt % 2 == 1 && f < s) {
        printf("%d\n", abs(f - s) + t);
      } else {
        if (tt % 2 == 0)
          printf("%d\n", m - f + m - s + t);
        else
          printf("%d\n", f - 1 + s - 1 + t);
      }
    }
  }
  return 0;
}

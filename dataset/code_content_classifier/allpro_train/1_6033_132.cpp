#include <bits/stdc++.h>
using namespace std;
int a1, a2, b1, b2, c1, c2, d1, d2;
int a3, a4, b3, b4, c3, c4, d3, d4;
int u, d, l, r;
bool flag;
int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
void work(int a1, int a2, int b1, int b2) {
  if (a1 >= d && a1 <= u && a2 >= l && a2 <= r) {
    flag = 1;
    return;
  }
  int c1 = min(a1, b1), c2 = max(a1, b1), d1 = min(a2, b2), d2 = max(a2, b2);
  int k = (a1 - b1) / (a2 - b2), b = a2 - a1 * k;
  if (l >= d1 && l <= d2) {
    int x = (l - b) / k;
    if (x >= d && x <= u) flag = 1;
  }
  if (r >= d1 && r <= d2) {
    int x = (r - b) / k;
    if (x >= d && x <= u) flag = 1;
  }
  if (d >= c1 && d <= c2) {
    int y = k * d + b;
    if (y >= l && y <= r) flag = 1;
  }
  if (u >= c1 && u <= c2) {
    int y = k * u + b;
    if (y >= l && y <= r) flag = 1;
  }
}
void change(int &a1, int &a2) {
  int x = a1 + a2, y = a2 - a1;
  a1 = x, a2 = y;
}
int main() {
  scanf("%d%d%d%d%d%d%d%d", &a1, &a2, &b1, &b2, &c1, &c2, &d1, &d2);
  d = min(min(a1, b1), c1), u = max(max(a1, b1), c1);
  l = min(min(a2, b2), c2), r = max(max(a2, b2), c2);
  scanf("%d%d%d%d%d%d%d%d", &a3, &a4, &b3, &b4, &c3, &c4, &d3, &d4);
  flag = 0, work(a3, a4, b3, b4);
  if (!flag) work(b3, b4, c3, c4);
  if (!flag) work(c3, c4, d3, d4);
  if (!flag) work(d3, d4, a3, a4);
  if (!flag) {
    change(a1, a2), change(b1, b2), change(c1, c2), change(d1, d2);
    change(a3, a4), change(b3, b4), change(c3, c4), change(d3, d4);
    d = min(min(a3, b3), c3), u = max(max(a3, b3), c3);
    l = min(min(a4, b4), c4), r = max(max(a4, b4), c4);
    work(a1, a2, b1, b2);
    if (!flag) work(b1, b2, c1, c2);
    if (!flag) work(c1, c2, d1, d2);
    if (!flag) work(d1, d2, a1, a2);
  }
  if (flag)
    printf("YES");
  else
    printf("NO");
}

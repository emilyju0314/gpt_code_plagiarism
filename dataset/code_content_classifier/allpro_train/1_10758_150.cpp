#include <bits/stdc++.h>
using namespace std;
struct point {
  int index, num;
  friend bool operator<(point a, point b) {
    if (a.num < b.num) return true;
    return false;
  }
};
priority_queue<point> que;
int a[150000], b[150000][3];
bool pop(point &p) {
  if (que.empty()) return false;
  p = que.top();
  que.pop();
  return true;
}
void push(point &p) {
  if (p.num == 0) return;
  que.push(p);
}
int max(int x, int y) {
  if (x > y) return x;
  return y;
}
int min(int x, int y) {
  if (x < y) return x;
  return y;
}
void dog(int &x, int &y, int &z) {
  int t1, t2, t3;
  t1 = x;
  t2 = y;
  t3 = z;
  x = max(max(t1, t2), t3);
  z = min(min(t1, t2), t3);
  if (t1 != x && t1 != z) y = t1;
  if (t2 != x && t2 != z) y = t2;
  if (t3 != x && t3 != z) y = t3;
}
int main() {
  point pt, p1, p2, p3;
  int n, i, tot, t1;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  while (!que.empty()) que.pop();
  t1 = 1;
  for (i = 2; i <= n; i++)
    if (a[i] != a[i - 1]) {
      pt.index = a[i - 1];
      pt.num = t1;
      t1 = 1;
      que.push(pt);
    } else
      t1++;
  pt.index = a[n];
  pt.num = t1;
  que.push(pt);
  tot = 0;
  while (1) {
    if (!pop(p1)) break;
    if (!pop(p2)) break;
    if (!pop(p3)) break;
    {
      tot++;
      b[tot][0] = p1.index;
      b[tot][1] = p2.index;
      b[tot][2] = p3.index;
      dog(b[tot][0], b[tot][1], b[tot][2]);
    }
    p1.num = p1.num - 1;
    p2.num = p2.num - 1;
    p3.num--;
    push(p1);
    push(p2);
    push(p3);
  }
  printf("%d\n", tot);
  for (i = 1; i <= tot; i++) printf("%d %d %d\n", b[i][0], b[i][1], b[i][2]);
  return 0;
}

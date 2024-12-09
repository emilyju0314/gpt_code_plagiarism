#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
struct node {
  long long x, y;
} a[N], b[N];
int n, m, top, st[N], col[N];
node operator-(node x, node y) { return (node){x.x - y.x, x.y - y.y}; }
long long cross(node x, node y) { return x.x * y.y - x.y * y.x; }
long long dis(node x) { return x.x * x.x + x.y * x.y; }
bool cmp(node x, node y) {
  long long t = cross(x - a[1], y - a[1]);
  if (t) return t > 0;
  return dis(x) < dis(y);
}
bool check() {
  st[top = 1] = 1;
  for (int i = 2; i <= m; i++) {
    while (top > 1 &&
           cross(b[i] - b[st[top - 1]], b[st[top]] - b[st[top - 1]]) >= 0)
      top--;
    st[++top] = i;
  }
  for (int i = 1; i <= top; i++)
    if ((b[st[i]].x & 1) || (b[st[i]].y & 1)) return 1;
  return 0;
}
int main() {
  scanf("%d", &n);
  n++;
  for (int i = 2; i <= n; i++) scanf("%d%d", &a[i].x, &a[i].y);
  for (int i = 2; i <= n; i++)
    if (a[i].x < a[1].x || a[i].x == a[1].x && a[i].y < a[1].y)
      swap(a[1], a[i]);
  sort(a + 2, a + n + 1, cmp);
  st[top = 1] = 1;
  for (int i = 2; i <= n; i++) {
    while (top > 1 &&
           cross(a[i] - a[st[top - 1]], a[st[top]] - a[st[top - 1]]) >= 0)
      top--;
    st[++top] = i;
  }
  for (int i = 1; i <= top; i++)
    if ((a[st[i]].x & 1) || (a[st[i]].y & 1)) {
      puts("Ani");
      return 0;
    }
  for (int i = 1; i <= (top >> 1); i++)
    col[st[i * 2 - 1]] = 1, col[st[i * 2]] = 2;
  if (top & 1) col[st[top]] = 3;
  col[1] = 0;
  m = 0;
  for (int i = 1; i <= n; i++)
    if (col[i] != 1) b[++m] = a[i];
  if (check()) {
    puts("Ani");
    return 0;
  }
  m = 0;
  for (int i = 1; i <= n; i++)
    if (col[i] != 2) b[++m] = a[i];
  if (check()) {
    puts("Ani");
    return 0;
  }
  m = 0;
  for (int i = 1; i <= n; i++)
    if (col[i] != 3) b[++m] = a[i];
  if (check()) {
    puts("Ani");
    return 0;
  }
  puts("Borna");
}

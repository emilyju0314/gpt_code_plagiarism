#include <bits/stdc++.h>
using namespace std;
int a[400000];
int pos[400000];
int d[1 << 19];
int lowbit(int x) { return (x & (x ^ (x - 1))); }
void add1(int x) {
  int i;
  for (i = x; i < 1 << 19; i += lowbit(i)) d[i]++;
}
void rem1(int x) {
  int i;
  for (i = x; i < 1 << 19; i += lowbit(i)) d[i]--;
}
int get1(int x) {
  int i, ret;
  ret = 0;
  for (i = x; i > 0; i -= lowbit(i)) ret += d[i];
  return ret;
}
int main() {
  int i, n, q, x, y, z, tmp;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    pos[a[i]] = i;
  }
  memset(d, 0, sizeof(d));
  for (i = 1; i < n; i++)
    if (pos[i] > pos[i + 1]) {
      add1(i);
    }
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d%d%d", &x, &y, &z);
    if (x == 1) {
      tmp = get1(z - 1) - get1(y - 1);
      printf("%d\n", tmp + 1);
    } else {
      y--;
      z--;
      if ((a[y] > 1) && (pos[a[y] - 1] > pos[a[y]])) rem1(a[y] - 1);
      if ((a[y] + 1 <= n) && (pos[a[y]] > pos[a[y] + 1])) rem1(a[y]);
      if ((a[z] > 1) && (pos[a[z] - 1] > pos[a[z]]) && (a[z] - 1 != a[y]))
        rem1(a[z] - 1);
      if ((a[z] + 1 <= n) && (pos[a[z]] > pos[a[z] + 1]) && (a[z] != a[y] - 1))
        rem1(a[z]);
      tmp = a[y];
      a[y] = a[z];
      a[z] = tmp;
      pos[a[y]] = y;
      pos[a[z]] = z;
      if ((a[y] > 1) && (pos[a[y] - 1] > pos[a[y]])) add1(a[y] - 1);
      if ((a[y] + 1 <= n) && (pos[a[y]] > pos[a[y] + 1])) add1(a[y]);
      if ((a[z] > 1) && (pos[a[z] - 1] > pos[a[z]]) && (a[z] - 1 != a[y]))
        add1(a[z] - 1);
      if ((a[z] + 1 <= n) && (pos[a[z]] > pos[a[z] + 1]) && (a[z] != a[y] - 1))
        add1(a[z]);
    }
  }
}

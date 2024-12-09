#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
int a[N];
int fa(int x) {
  for (int i = 0;; i++)
    if ((1 << i) >= x) return (1 << i) - x;
}
int dis(int x, int y) {
  int sum = 0;
  while (x != y) x > y ? x = fa(x) : y = fa(y), sum++;
  return sum;
}
int get(int x) {
  int mx = 0, id = 0;
  for (int i = 1; i <= n; i++) {
    int t = dis(a[x], a[i]);
    if (t > mx) mx = t, id = i;
  }
  return id;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int t1 = get(1), t2 = get(t1);
  printf("%d %d %d", t1, t2, dis(a[t1], a[t2]));
  return 0;
}

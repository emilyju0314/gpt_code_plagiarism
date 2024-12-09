#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
double pos[N];
double getPos(int l, int r, int p) {
  int ans = ((r / p) - ((l - 1) / p));
  return double(ans) / (r - l + 1);
}
double getExp(int x, int n, int p) {
  int l = (x == 1 ? n : x - 1);
  int r = (x == n ? 1 : x + 1);
  return pos[x] * (2.0 - pos[l] / 2 - pos[r] / 2);
}
int main() {
  int l, r, n, p;
  double ans = 0.0;
  scanf("%d%d", &n, &p);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &l, &r);
    pos[i] = getPos(l, r, p);
  }
  for (int i = 1; i <= n; i++) {
    ans += getExp(i, n, p);
  }
  printf("%.9f\n", ans * 1000.0 * 2);
  return 0;
}

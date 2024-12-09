#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
int n;
int m;
int x, y;
int main() {
  scanf("%d%d", &x, &y);
  int ans = 0, d = 1, xx = 0, yy = 0;
  while (true) {
    if (yy == y && xx <= x && xx + d >= x) break;
    ans++;
    xx += d;
    if (xx == x && yy <= y && yy + d >= y) break;
    ans++;
    yy += d;
    d++;
    if (yy == y && xx - d <= x && xx >= x) break;
    ans++;
    xx -= d;
    if (xx == x && yy - d <= y && yy >= y) break;
    ans++;
    yy -= d;
    d++;
  }
  printf("%d\n", ans);
  return 0;
}

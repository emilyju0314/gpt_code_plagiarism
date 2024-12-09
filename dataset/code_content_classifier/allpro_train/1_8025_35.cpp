#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int INF = 1000000007;
int bit[15], pos;
bool check(int x) {
  int l = 1, r = 100005, mid;
  while (l < r) {
    mid = (l + r) >> 1;
    if (l == mid) break;
    if ((long long)mid * mid <= x)
      l = mid;
    else
      r = mid;
  }
  return l * l == x;
}
int main() {
  int n, ans = INF;
  cin >> n;
  while (n) bit[++pos] = n % 10, n /= 10;
  for (int i = 1; i < (1 << pos); ++i) {
    int tmp = 0, mark = -1, num = 0;
    for (int j = 0; j < pos; ++j) {
      if ((i >> j) & 1) {
        tmp = tmp * 10 + bit[pos - j];
        if (mark == -1) mark = bit[pos - j];
        ++num;
      }
    }
    if (mark == 0) continue;
    if (check(tmp)) ans = min(ans, pos - num);
  }
  if (ans == INF)
    puts("-1");
  else
    printf("%d\n", ans);
  return 0;
}

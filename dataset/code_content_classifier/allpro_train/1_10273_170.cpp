#include <bits/stdc++.h>
using namespace std;
pair<int, int> ara[200005];
pair<int, int> bara[200005];
int main() {
  int n, c, d;
  scanf("%d %d %d", &n, &c, &d);
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    int b, p;
    char type;
    scanf("%d %d %c", &b, &p, &type);
    if (type == 'C')
      ara[x++] = {p, b};
    else
      bara[y++] = {p, b};
  }
  sort(ara, ara + x);
  sort(bara, bara + y);
  int maxi[n];
  maxi[0] = ara[0].second;
  int ans = 0;
  for (int i = 1; i < x; i++) {
    if (i) maxi[i] = max(maxi[i - 1], ara[i].second);
    int p = ara[i].first, b = ara[i].second;
    if (p > c) break;
    p = c - p;
    if (p == 0) continue;
    auto ptr = upper_bound(ara, ara + i, make_pair(p, INT_MAX)) - ara;
    if (ptr == 0) continue;
    ptr--;
    auto b2 = maxi[ptr];
    ans = max(ans, b + b2);
  }
  maxi[0] = bara[0].second;
  for (int i = 1; i < y; i++) {
    if (i) maxi[i] = max(maxi[i - 1], bara[i].second);
    int p = bara[i].first, b = bara[i].second;
    if (p > d) break;
    p = d - p;
    if (p == 0) continue;
    auto ptr = upper_bound(bara, bara + i, make_pair(p, INT_MAX)) - bara;
    if (ptr == 0) continue;
    ptr--;
    auto b2 = maxi[ptr];
    ans = max(ans, b + b2);
  }
  if (x == 0 || y == 0) {
    printf("%d\n", ans);
    return 0;
  }
  int maxiC = INT_MIN, maxiD = INT_MIN;
  for (int i = 0; i < x; i++)
    if (ara[i].first <= c) maxiC = max(maxiC, ara[i].second);
  for (int i = 0; i < y; i++)
    if (bara[i].first <= d) maxiD = max(maxiD, bara[i].second);
  printf("%lld\n", max(1ll * ans, 0ll + 1ll * maxiC + 1ll * maxiD));
  return 0;
}

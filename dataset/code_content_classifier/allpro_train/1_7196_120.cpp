#include <bits/stdc++.h>
int n;
std::pair<int, int> b[200000];
void pupi(int ans) {
  std::cout << ans;
  exit(0);
}
int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> b[i].first, b[i].second = i + 1;
  std::sort(b, b + n);
  if (n <= 3) pupi(1);
  bool ok = true;
  int d = b[2].first - b[1].first;
  for (int i = 3; i < n && ok; ++i)
    if (b[i].first - b[i - 1].first != d) ok = false;
  if (ok) pupi(b[0].second);
  ok = true;
  d = b[2].first - b[0].first;
  for (int i = 3; i < n && ok; ++i)
    if (b[i].first - b[i - 1].first != d) ok = false;
  if (ok) pupi(b[1].second);
  d = b[1].first - b[0].first;
  ok = true;
  int ans = 1;
  for (int i = 2; i < n; ++i) {
    if (b[i].first - b[i - 1].first != d) {
      if (!ok) pupi(-1);
      if (i == n - 1) pupi(b[i].second);
      if (b[i + 1].first - b[i - 1].first == d) {
        ok = false;
        ans = b[i].second;
        ++i;
        continue;
      }
      pupi(-1);
    }
  }
  pupi(ans);
}

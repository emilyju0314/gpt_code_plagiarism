#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr double kPI = 3.14159265358979323846264338327950288;
int n;
vector<int> a;
void Load() {}
void Solve() {
  scanf("%d", &n);
  a.resize(n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  int np = 0, nn = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > 0)
      np++;
    else if (a[i] < 0)
      nn++;
  }
  if (np >= (n + 1) / 2) {
    puts("1");
    return;
  }
  if (nn >= (n + 1) / 2) {
    puts("-1");
    return;
  }
  puts("0");
  return;
}
int main() {
  Load();
  Solve();
}

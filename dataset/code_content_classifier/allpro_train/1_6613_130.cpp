#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, ans = 0;
  cin >> n;
  map<long long int, long long int> a;
  for (long long int i = 1; i * (i + 1) <= n * n; ++i) {
    for (long long int j = i + 1; i * i + j * j <= n * n; ++j) {
      long long int k = sqrt(i * i + j * j);
      if (k * k == i * i + j * j) a[k]++;
    }
  }
  for (auto &i : a) ans += i.second;
  cout << ans;
  return 0;
}

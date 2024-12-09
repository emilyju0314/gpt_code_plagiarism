#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int arr[n], arr2[n];
  for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &arr2[i]);
  map<long double, int> mp;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] == 0) {
      if (arr2[i] == 0) cnt++;
      continue;
    }
    long double need = 0.00 - (arr2[i] * 1.00);
    long double want = need / (arr[i] * 1.00);
    mp[want]++;
  }
  int ans = 0;
  for (auto &i : mp) ans = max(ans, i.second);
  return cout << ans + cnt << "\n", 0;
}

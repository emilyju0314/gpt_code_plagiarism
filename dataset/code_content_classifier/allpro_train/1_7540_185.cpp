#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<pair<int, int>> v;
  int i, n, j;
  cin >> n;
  i = 1;
  while ((i - 1) * 2 < n - 1) i++;
  cout << i << endl;
  if (n % 2 == 0) {
    for (j = 1; j <= n / 2; j++) v.push_back({1, j});
    for (j = 0; j < n / 2; j++) v.push_back({i, i - j});
  } else {
    for (j = 1; j <= n / 2; j++) v.push_back({1, j});
    for (j = 0; j < n / 2 + 1; j++) v.push_back({i, i - j});
  }
  sort(v.begin(), v.end());
  for (i = 0; i < n; i++) cout << v[i].first << " " << v[i].second << endl;
}

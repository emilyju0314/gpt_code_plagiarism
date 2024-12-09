#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;
vector<int> a[100005];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int k, x;
    cin >> k;
    while (k--) {
      cin >> x;
      a[i].push_back(x);
    }
    sort(a[i].begin(), a[i].end());
  }
  a[0] = a[n];
  a[n + 1] = a[1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < a[i].size(); j++) {
      if (upper_bound(a[i - 1].begin(), a[i - 1].end(), a[i][j]) -
              lower_bound(a[i - 1].begin(), a[i - 1].end(), a[i][j - 1]) !=
          upper_bound(a[i + 1].begin(), a[i + 1].end(), a[i][j]) -
              lower_bound(a[i + 1].begin(), a[i + 1].end(), a[i][j - 1]))
        ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}

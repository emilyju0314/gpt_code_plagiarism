#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int mm = INT_MAX;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    mm = min(mm, v[i]);
  }
  for (int i = 0; i < n; ++i) {
    v[i] -= mm;
  }
  int first = -1;
  int last = -1;
  int mx = 0;
  for (int i = 0; i < n; ++i) {
    if (!v[i] && last != -1) {
      mx = max(mx, abs(i - last) - 1);
    }
    if (!v[i]) {
      if (first == -1) first = i;
      last = i;
    }
  }
  mx = max(mx, abs(first + abs(last - (n - 1))));
  long long ans = ((mm + 0LL) * n) + mx;
  cout << ans;
  return 0;
}

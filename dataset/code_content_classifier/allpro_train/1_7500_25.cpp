#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, k;
  cin >> n >> k >> d;
  vector<vector<int>> v(d);
  for (size_t i = 0; i < n; i++) {
    int a;
    cin >> a;
    v[a % d].push_back(a);
  }
  int ans = -1;
  for (size_t i = 0; i < v.size(); i++) {
    if (v[i].size() >= k) {
      ans = i;
      break;
    }
  }
  if (ans == -1)
    cout << "No";
  else {
    cout << "Yes\n";
    for (size_t i = 0; i < k; i++) {
      cout << v[ans][i] << " ";
    }
  }
  return 0;
}

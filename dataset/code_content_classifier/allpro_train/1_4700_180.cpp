#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, a, b;
  cin >> n >> a >> b;
  if (a >= n - 1 && a != 0) {
    cout << -1;
    return 0;
  }
  if (b == n) {
    cout << -1;
    return 0;
  }
  vector<long long> ans;
  ans.push_back(2);
  long long sum = 2;
  long long i = 1;
  if (b == 0 && a != 0) {
    ans.push_back(2);
    sum = 4;
    i = 2;
  }
  for (; i < n; i++) {
    if (b) {
      ans.push_back(sum + 1);
      sum += sum + 1;
      b--;
    } else if (a) {
      ans.push_back(ans[i - 1] + 1);
      a--;
    } else {
      ans.push_back(ans[i - 1]);
    }
  }
  for (auto it : ans) {
    cout << it << " ";
  }
  return 0;
}

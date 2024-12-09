#include <bits/stdc++.h>
using namespace std;
int main() {
  priority_queue<int, vector<int>, greater<int> > times;
  int n, k;
  cin >> n >> k;
  vector<int> start(n);
  int nums[n];
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
    if (i < k) {
      times.push(nums[i]);
      start[i] = 0;
    }
  }
  vector<int> moments = {0};
  int curr;
  for (int i = k; i < n; ++i) {
    curr = times.top();
    start[i] = curr;
    moments.push_back(curr);
    times.pop();
    times.push(curr + nums[i]);
  }
  while (times.size() > 0) {
    moments.push_back(times.top());
    times.pop();
  }
  int ans = 0, mom, pos = 1;
  for (int i = 0; i < n; ++i) {
    pos = 0;
    for (int act = 1; act <= nums[i]; act++) {
      mom = start[i] + act;
      while (pos < n - 1 && moments[pos + 1] < mom) pos++;
      if (act == round((double)pos * 100.0 / n)) {
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

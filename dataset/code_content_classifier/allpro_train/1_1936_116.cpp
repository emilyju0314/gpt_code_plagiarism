#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  scanf("%d %d", &n, &t);
  vector<int> v(n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  deque<int> q, tmp;
  for (int i = 0; i < n; i++) q.push_back(v[i]);
  int sum = 0, ans = 0, cnt = 0;
  while (q.size()) {
    if (sum + q.front() <= t) {
      sum += q.front();
      tmp.push_back(q.front());
      q.pop_front();
      ans = max(ans, (int)tmp.size());
    } else {
      if (tmp.size()) {
        sum -= tmp.front();
        tmp.pop_front();
      } else {
        q.pop_front();
      }
    }
    ++cnt;
  }
  cout << ans << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  deque<int> dq;
  int n;
  cin >> n;
  vector<int> v(n);
  int q;
  cin >> q;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    dq.push_back(v[i]);
  }
  vector<pair<int, int> > ans;
  for (int i = 1; i < n; i++) {
    int a = dq.front();
    dq.pop_front();
    int b = dq.front();
    dq.pop_front();
    ans.push_back({a, b});
    if (a > b) {
      dq.push_front(a);
      dq.push_back(b);
    } else {
      dq.push_front(b);
      dq.push_back(a);
    }
  }
  int index = 0;
  while (!dq.empty()) {
    int a = dq.front();
    dq.pop_front();
    v[index++] = a;
  }
  long long int m;
  int a, b;
  long long int siz = (long long int)ans.size();
  while (q--) {
    cin >> m;
    if (m - 1 < (long long int)ans.size()) {
      cout << ans[m - 1].first << " " << ans[m - 1].second << "\n";
    } else {
      m -= (long long int)ans.size();
      m %= siz;
      if (m == 0) {
        m = n - 1;
      }
      cout << v[0] << " " << v[m] << "\n";
    }
  }
  return 0;
}

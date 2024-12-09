#include <bits/stdc++.h>
using namespace std;
map<int, int> contain;
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  queue<int> q;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (contain.count(x) == 0)
      while ((int)q.size() > k - 1) {
        contain.erase(q.front());
        q.pop();
      }
    if (contain.count(x) == 0 and q.size() <= k - 1) {
      contain[x] = 1;
      q.push(x);
    }
  }
  vector<int> ans;
  while (!q.empty()) {
    ans.push_back(q.front());
    q.pop();
  }
  reverse(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for (auto x : ans) cout << x << ' ';
  puts("");
}

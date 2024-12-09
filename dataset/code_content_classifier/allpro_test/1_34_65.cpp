#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt = 1;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int max_val = (1 << 13);
    int od[max_val];
    vector<int> vals[max_val];
    for (int i = 0; i < max_val; i++) od[i] = max_val;
    for (int i = 0; i < max_val; i++) vals[i].push_back(0);
    vector<int> pos(max_val, 0);
    pos[0] = 1;
    for (int i = 0; i < n; i++) {
      int cur = a[i];
      for (int x : vals[cur]) {
        int res = x ^ cur;
        pos[res] = 1;
        while (od[res] > cur) {
          od[res]--;
          if (od[res] != cur) vals[od[res]].push_back(res);
        }
      }
      vals[cur].clear();
    }
    int cnt = 0;
    for (int i = 0; i < max_val; i++) cnt += pos[i];
    cout << cnt << "\n";
    for (int i = 0; i < max_val; i++) {
      if (pos[i]) {
        cout << i << " ";
      }
    }
  }
}

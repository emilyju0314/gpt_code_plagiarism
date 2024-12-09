#include <bits/stdc++.h>
using namespace std;
void enable_io() {}
template <typename T>
void debug(vector<T> v) {
  for (auto it : v) {
    cout << it << " ";
  }
  cout << endl;
}
int n, k;
vector<int> adj[1001];
void solve() {
  for (int i = 0; i < 1001; i++) {
    adj[i].clear();
  }
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  string ans;
  if (adj[k].size() <= 1) {
    ans = "Ayush";
  } else {
    int rem = n - 3;
    if (rem & 1) {
      ans = "Ayush";
    } else {
      ans = "Ashish";
    }
  }
  cout << ans << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  enable_io();
  int T = 1;
  cin >> T;
  for (int tid = 1; tid <= T; tid++) {
    solve();
  }
  return 0;
}

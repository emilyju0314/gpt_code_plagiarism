#include <bits/stdc++.h>
using namespace std;
int chk(int n, int k, vector<int> f) {
  vector<int> a, vis(n, 0);
  for (int i = 0; i < n; i++) {
    int cnt = 1, j = (i + k) % n;
    if (vis[i]) {
      continue;
    }
    vis[i] = true;
    while (j != i) {
      vis[j] = true;
      j = (j + k) % n;
      cnt++;
    }
    a.push_back(cnt);
  }
  sort(a.begin(), a.end(), greater<int>());
  priority_queue<int> pq;
  for (int i = 0; i < 26; i++) {
    pq.push(f[i]);
  }
  for (int i = 0; i < a.size(); i++) {
    if (pq.empty()) {
      return 0;
    }
    int v = pq.top();
    pq.pop();
    if (v < a[i]) {
      return 0;
    }
    v -= a[i];
    pq.push(v);
  }
  return 1;
}
void solve() {
  int n, k;
  cin >> n >> k;
  string str;
  cin >> str;
  vector<int> f(26, 0);
  for (auto ch : str) {
    f[ch - 'a']++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (chk(i, k % i, f)) {
      ans = i;
    }
  cout << ans << endl;
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test, tc = 0;
  cin >> test;
  while (test--) {
    solve();
  }
}

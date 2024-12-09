#include <bits/stdc++.h>
using namespace std;
const long long N = 1005;
long long n;
long long store[20][N];
void query(long long idx, vector<long long> &v) {
  if (!v.size()) return;
  cout << v.size() << endl;
  for (auto &it : v) cout << it << " ";
  cout << endl;
  for (long long i = 1; i <= n; i++) cin >> store[idx][i];
}
void work() {
  for (long long b = 0; b < 10; b++) {
    vector<long long> idx;
    for (long long i = 1; i <= n; i++)
      if (i >> b & 1) idx.push_back(i);
    query(b, idx);
  }
  for (long long b = 0; b < 10; b++) {
    vector<long long> idx;
    for (long long i = 1; i <= n; i++)
      if (!(i >> b & 1)) idx.push_back(i);
    query(b + 10, idx);
  }
}
void output() {
  vector<long long> ans;
  for (long long i = 1; i <= n; i++) {
    long long val = 2e9;
    for (long long b = 0; b < 10; b++) {
      if (i >> b & 1)
        val = min(val, store[b + 10][i]);
      else
        val = min(val, store[b][i]);
    }
    ans.push_back(val);
  }
  cout << -1 << endl;
  for (auto &it : ans) cout << it << " ";
  cout << endl;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (long long i = 0; i < 20; i++)
    for (long long j = 0; j < N; j++) store[i][j] = 2e9;
  work();
  output();
  return 0;
}

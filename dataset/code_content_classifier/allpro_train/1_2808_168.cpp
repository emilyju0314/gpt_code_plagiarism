#include <bits/stdc++.h>
using namespace std;
int mx = 0;
int arr[500009];
int d[500009], n;
vector<int> adj[500009];
void fun(int nd, int par) {
  int t = lower_bound(d + 1, d + n + 1, arr[nd]) - d;
  mx = max(mx, t);
  int p = d[t];
  d[t] = arr[nd];
  for (int i = 0; i < adj[nd].size(); i++) {
    int to = adj[nd][i];
    if (to != par) fun(to, nd);
  }
  d[t] = p;
}
int main() {
  int k, l;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> k >> l;
    adj[k].push_back(l);
    adj[l].push_back(k);
  }
  for (int i = 1; i <= n; i++) {
    fill(d, d + 500009, 1000000007);
    fun(i, -1);
  }
  cout << mx << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, a[maxn], root;
vector<vector<int> > v;
vector<int> potato;
map<int, int> good;
void dfs(int x, int mn, int mx) {
  if (a[x] > mn && a[x] < mx) good[a[x]] = 1;
  if (v[x][0] != -2) dfs(v[x][0], mn, min(mx, a[x]));
  if (v[x][1] != -2) dfs(v[x][1], max(mn, a[x]), mx);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  v.resize(n + 19);
  set<int> st;
  for (int i = 0; i < n; i++) st.insert(i);
  for (int i = 0, val, l, r; i < n; i++) {
    cin >> val >> l >> r;
    a[i] = val;
    l--;
    r--;
    v[i].push_back(l);
    v[i].push_back(r);
    st.erase(l);
    st.erase(r);
  }
  root = *st.begin();
  dfs(root, -1000000009, 1000000009);
  int ans = 0;
  for (int i = 0; i < n; i++)
    if (!good[a[i]]) ans++;
  cout << ans;
}

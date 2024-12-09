#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, i, x, y, a, k;
  cin >> n;
  vector<int> vec[n + 1];
  for (i = 1; i < n; ++i) {
    cin >> x >> y;
    vec[x].emplace_back(y);
    vec[y].emplace_back(x);
  }
  int max = 0;
  k = 0;
  for (i = 1; i < n + 1; i++) {
    if ((vec[i].size()) > max) {
      max = vec[i].size();
      k = i;
    }
  }
  y = vec[k].size() + 1;
  vector<int> col(n + 1);
  set<int> st;
  vector<bool> vis(n + 1, true);
  queue<int> que;
  que.push(k);
  vector<int> par(n + 1);
  col[k] = 1;
  par[k] = 0;
  col[0] = 0;
  while (!que.empty()) {
    a = 1;
    x = que.front();
    vis[x] = false;
    st.insert(col[x]);
    que.pop();
    st.insert(col[par[x]]);
    for (auto i : vec[x]) {
      if (vis[i]) {
        while (st.find(a) != st.end()) {
          a++;
        }
        col[i] = a;
        st.insert(a);
        que.push(i);
        par[i] = x;
      }
    }
    st.clear();
  }
  cout << y << "\n";
  for (i = 1; i < n + 1; i++) cout << col[i] << " ";
}

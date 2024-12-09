#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
map<pair<int, int>, bool> have;
map<pair<int, int>, bool> vis;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int xo, yo, x1, y1;
  cin >> xo >> yo >> x1 >> y1;
  pair<int, int> st, en;
  st.first = xo;
  en.first = x1;
  st.second = yo;
  en.second = y1;
  have[st] = true;
  have[en] = true;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int r, a, b;
    cin >> r >> a >> b;
    for (int c = a; c <= b; ++c) {
      pair<int, int> n;
      n.first = r;
      n.second = c;
      if (!have[n]) {
        have[n] = true;
      }
    }
  }
  queue<pair<pair<int, int>, long long> > q;
  q.push({st, (long long)0});
  while (!q.empty()) {
    pair<int, int> u = q.front().first;
    long long lev = q.front().second;
    q.pop();
    if (u.first == en.first && u.second == en.second) {
      cout << lev;
      return 0;
    }
    pair<int, int> v;
    v.first = u.first + 1;
    v.second = u.second;
    if (have[v] && !vis[v]) {
      vis[v] = true;
      q.push({v, lev + 1});
    }
    v.first = u.first;
    v.second = u.second + 1;
    if (have[v] && !vis[v]) {
      vis[v] = true;
      q.push({v, lev + 1});
    }
    v.first = u.first + 1;
    v.second = u.second + 1;
    if (have[v] && !vis[v]) {
      vis[v] = true;
      q.push({v, lev + 1});
    }
    v.first = u.first;
    v.second = u.second - 1;
    if (have[v] && !vis[v]) {
      vis[v] = true;
      q.push({v, lev + 1});
    }
    v.first = u.first - 1;
    v.second = u.second;
    if (have[v] && !vis[v]) {
      vis[v] = true;
      q.push({v, lev + 1});
    }
    v.first = u.first - 1;
    v.second = u.second - 1;
    if (have[v] && !vis[v]) {
      vis[v] = true;
      q.push({v, lev + 1});
    }
    v.first = u.first + 1;
    v.second = u.second - 1;
    if (have[v] && !vis[v]) {
      vis[v] = true;
      q.push({v, lev + 1});
    }
    v.first = u.first - 1;
    v.second = u.second + 1;
    if (have[v] && !vis[v]) {
      vis[v] = true;
      q.push({v, lev + 1});
    }
  }
  cout << -1;
  return 0;
}

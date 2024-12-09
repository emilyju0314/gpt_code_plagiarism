#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.setf(ios_base::fixed);
  cout.precision(30);
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n), d(n);
  vector<int> cx;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    cx.push_back(a[i]);
    cx.push_back(c[i]);
  }
  sort(cx.begin(), cx.end());
  cx.erase(unique(cx.begin(), cx.end()), cx.end());
  int m = cx.size();
  vector<multiset<pair<int, int> > > fen(m);
  for (int i = 0; i < n; ++i) {
    int fen_pos = distance(cx.begin(), lower_bound(cx.begin(), cx.end(), a[i]));
    while (fen_pos < m) {
      fen[fen_pos].insert({b[i], i});
      fen_pos = (fen_pos | (fen_pos + 1));
    }
  }
  vector<int> dist(n, n + 1), from(n, -1);
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0 && b[i] == 0) {
      q.push(i);
      dist[i] = 0;
      from[i] = -2;
    }
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    int pos = distance(cx.begin(), lower_bound(cx.begin(), cx.end(), c[u]));
    while (pos >= 0) {
      while (fen[pos].size() > 0 && d[u] >= fen[pos].begin()->first) {
        int to = fen[pos].begin()->second;
        fen[pos].erase(fen[pos].begin());
        if (dist[to] > dist[u] + 1) {
          q.push(to);
          dist[to] = dist[u] + 1;
          from[to] = u;
        }
      }
      pos = (pos & (pos + 1)) - 1;
    }
  }
  if (from[n - 1] == -1) {
    cout << -1;
  } else {
    vector<int> result = {n};
    int cur_vec = n - 1;
    while (from[cur_vec] >= 0) {
      cur_vec = from[cur_vec];
      result.push_back(cur_vec + 1);
    }
    reverse(result.begin(), result.end());
    cout << result.size() << endl;
    for (int vec : result) {
      cout << vec << " ";
    }
    cout << endl;
  }
  return 0;
}

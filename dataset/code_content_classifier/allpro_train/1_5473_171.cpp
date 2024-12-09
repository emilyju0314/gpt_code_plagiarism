#include <bits/stdc++.h>
using namespace std;
template <class T>
void dbs(string str, T t) {
  cerr << str << " : " << t << "\n";
}
template <class T, class... S>
void dbs(string str, T t, S... s) {
  int idx = str.find(',');
  cerr << str.substr(0, idx) << " : " << t << ",";
  dbs(str.substr(idx + 1), s...);
}
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
void debug(T a, T b) {
  cerr << "[";
  for (T i = a; i != b; ++i) {
    if (i != a) cerr << ", ";
    cerr << *i;
  }
  cerr << "]\n";
}
const int N = 200100;
int root[N];
int getRoot(int n) {
  if (root[n] != n) {
    root[n] = getRoot(root[n]);
  }
  return root[n];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<set<int>> vals(n);
  for (int i = 0; i < n; ++i) {
    root[i] = i;
    int idx;
    cin >> idx;
    --idx;
    vals[idx].insert(i);
  }
  int compCount = n;
  auto merge = [&](int u, int v) -> void {
    u = getRoot(u);
    v = getRoot(v);
    if (u != v) {
      root[v] = u;
      --compCount;
    }
  };
  for (const auto &v : vals) {
    auto it = v.begin();
    while (it != v.end()) {
      int cur = *it;
      ++it;
      if (it != v.end()) {
        int nxt = *it;
        if (cur + 1 == nxt) {
          merge(cur, nxt);
        }
      }
    }
  }
  cout << compCount - 1 << "\n";
  vector<int> pos(n);
  iota(pos.begin(), pos.end(), 0);
  for (int i = 0; i < m - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (vals[pos[u]].size() < vals[pos[v]].size()) {
      swap(pos[u], pos[v]);
    }
    u = pos[u], v = pos[v];
    for (int e : vals[v]) {
      if (e + 1 < n) {
        if (vals[u].count(e + 1)) {
          merge(e, e + 1);
        }
      }
      if (e > 0) {
        if (vals[u].count(e - 1)) {
          merge(e, e - 1);
        }
      }
    }
    for (int e : vals[v]) {
      vals[u].insert(e);
    }
    cout << compCount - 1 << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
template <typename T>
void dout(string name, int idx, T arg) {
  cerr << name << " = " << to_string(arg);
}
template <typename T1, typename... T2>
void dout(string names, int idx, T1 arg, T2... args) {
  cerr << names.substr(0, names.find(',')) << " = " << to_string(arg) << ", ";
  dout(names.substr(names.find(',') + 2), idx + 1, args...);
}
const int inf = (int)2e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(2 * n);
  vector<int> from(4 * m), to(4 * m), L(4 * m), R(4 * m);
  int edge_size = 0;
  vector<int> d(4 * m, inf);
  for (int i = 0; i < m; i++) {
    int a, b, l, r;
    cin >> a >> b >> l >> r;
    --a;
    --b;
    --r;
    int l0 = l + (l & 1), r0 = r - (r & 1);
    g[a].push_back(edge_size);
    if (a == 0 && l0 <= 0 && l0 <= r0) {
      d[edge_size] = 0;
    }
    from[edge_size] = a, to[edge_size] = b + n, L[edge_size] = l0,
    R[edge_size] = r0;
    ++edge_size;
    g[b].push_back(edge_size);
    if (b == 0 && l0 <= 0 && l0 <= r0) {
      d[edge_size] = 0;
    }
    from[edge_size] = b, to[edge_size] = a + n, L[edge_size] = l0,
    R[edge_size] = r0;
    ++edge_size;
    int l1 = l + !(l & 1), r1 = r - !(r & 1);
    g[a + n].push_back(edge_size);
    if (a + n == n && l1 <= 0 && l1 <= r1) {
      d[edge_size] = 0;
    }
    from[edge_size] = a + n, to[edge_size] = b, L[edge_size] = l1,
    R[edge_size] = r1;
    ++edge_size;
    g[b + n].push_back(edge_size);
    if (b + n == n && l1 <= 0 && l1 <= r1) {
      d[edge_size] = 0;
    }
    from[edge_size] = b + n, to[edge_size] = a, L[edge_size] = l1,
    R[edge_size] = r1;
    ++edge_size;
  }
  for (int v = 0; v < 2 * n; v++) {
    sort(g[v].begin(), g[v].end(), [&](int i, int j) { return L[i] < L[j]; });
  }
  assert(edge_size == 4 * m);
  set<pair<int, int>> s;
  for (int i = 0; i < 4 * m; i++) {
    s.insert(make_pair(d[i], i));
  }
  int ans = n > 1 ? inf : 0;
  vector<int> ptr(2 * n);
  while (!s.empty()) {
    int e = s.begin()->second;
    s.erase(s.begin());
    if (d[e] == inf) {
      break;
    }
    int v = from[e], u = to[e], my_l = L[e], my_r = R[e];
    42;
    if (u == n - 1 || u == 2 * n - 1) {
      ans = min(ans, d[e] + 1);
    }
    if (d[e] > my_r || d[e] < my_l) {
      continue;
    }
    while (ptr[u] < (int)g[u].size()) {
      int next_e = g[u][ptr[u]];
      int his_l = L[next_e], his_r = R[next_e];
      if (my_r + 1 < his_l) {
        break;
      }
      ++ptr[u];
      if (d[e] + 1 > his_r) {
        continue;
      }
      int new_d = max(d[e] + 1, his_l);
      if (new_d < d[next_e]) {
        s.erase(make_pair(d[next_e], next_e));
        d[next_e] = new_d;
        s.insert(make_pair(d[next_e], next_e));
      }
    }
  }
  if (ans == inf) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
  }
  return 0;
}

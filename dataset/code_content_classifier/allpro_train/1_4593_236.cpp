#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(char ch) {
  string s;
  s += ch;
  return s;
}
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
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
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const long long inf = 2e18;
const long long mod = 1e9 + 7;
void no() {
  cout << "NO\n";
  exit(0);
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> deg(n + 1);
  vector<set<int>> edges(n + 1);
  for (int i = (int)0; i < (int)m; i++) {
    int a, b;
    cin >> a >> b;
    deg[a]++;
    deg[b]++;
    edges[a].insert(b);
    edges[b].insert(a);
  }
  int root = -1;
  for (int i = (int)1; i < (int)n + 1; i++) {
    if (deg[i] != n - 1) {
      root = i;
      break;
    }
  }
  if (root == -1 || n == 1) {
    no();
  } else {
    cout << "YES\n";
    int next = -1;
    for (int i = (int)1; i < (int)n + 1; i++) {
      if (edges[root].count(i) == 0 && i != root) {
        next = i;
        break;
      }
    }
    assert(next != -1);
    vector<int> a(n + 1), b(n + 1);
    b[root] = n, b[next] = n;
    a[root] = n, a[next] = n - 1;
    int togive = 1;
    for (int i = (int)1; i < (int)n + 1; i++) {
      if (a[i] == 0) {
        a[i] = togive;
        b[i] = togive++;
      }
    }
    for (int i = (int)1; i < (int)n + 1; i++) cout << a[i] << " ";
    cout << "\n";
    for (int i = (int)1; i < (int)n + 1; i++) cout << b[i] << " ";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  for (int tc = 1; tc <= t; tc++) {
    solve();
  }
}

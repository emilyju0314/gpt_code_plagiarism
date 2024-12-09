#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool uax(T &x, T y) {
  return (y > x) ? x = y, true : false;
}
template <typename T>
inline bool uin(T &x, T y) {
  return (y < x) ? x = y, true : false;
}
void err(istream_iterator<string>) {}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> buf) {
  return os << "(" << buf.first << ": " << buf.second << ")";
}
template <typename T>
ostream &operator<<(ostream &os, vector<vector<T>> &A) {
  for (auto &B : A) os << '\n' << B;
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &A) {
  bool f = false;
  os << "{";
  for (const auto e : A) {
    if (f) os << ", ";
    os << e;
    f = true;
  }
  return os << "}";
}
template <typename T>
ostream &operator<<(ostream &os, set<T> &A) {
  bool f = false;
  os << "{";
  for (const auto e : A) {
    if (f) os << ", ";
    os << e;
    f = true;
  }
  return os << "}";
}
template <typename T>
ostream &operator<<(ostream &os, multiset<T> &A) {
  bool f = false;
  os << "{";
  for (const auto e : A) {
    if (f) os << ", ";
    os << e;
    f = true;
  }
  return os << "}";
}
template <typename K, typename V>
ostream &operator<<(ostream &os, map<K, V> &A) {
  bool f = false;
  os << "{";
  for (auto &e : A) {
    if (f) os << ", ";
    os << e;
    f = true;
  }
  return os << "}";
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " =: " << a << endl;
  err(++it, args...);
}
template <typename T>
void kek(T ans) {
  cout << ans << endl;
  exit(0);
}
int const MOD = 1000000007;
long long const INF = 1e18;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int k;
  cin >> k;
  int lg = 0;
  while ((1 << lg) <= k) ++lg;
  const int nax = 1000;
  vector<string> ans(nax, string(nax, 'N'));
  auto add = [&](int u, int v) { ans[u][v] = ans[v][u] = 'Y'; };
  int vptr = lg + 2;
  for (int i = 2; i < lg + 2; ++i) {
    add(i, vptr);
    add(i - 1, vptr++);
    add(i, vptr);
    add(i - 1, vptr++);
  }
  const int len = lg << 1;
  for (int i = 0; i < lg; ++i)
    if (k >> i & 1) {
      int u = i + 1;
      for (int j = i << 1; j < len; ++j) {
        add(u, vptr);
        u = vptr++;
      }
      add(0, u);
    }
  ans.resize(vptr);
  cout << vptr << '\n';
  for (auto &s : ans) cout << s.substr(0, vptr) << '\n';
  return 0;
}

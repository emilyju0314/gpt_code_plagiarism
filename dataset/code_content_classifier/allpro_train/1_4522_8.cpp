#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &x : v) is >> x;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i = 0; i < v.size(); ++i) {
    os << v[i] << (i + 1 == v.size() ? "" : " ");
  }
  return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << '(' << p.first << ',' << p.second << ')';
  return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &m) {
  os << '{';
  for (auto itr = m.begin(); itr != m.end(); ++itr) {
    os << '(' << itr->first << ',' << itr->second << ')';
    if (++itr != m.end()) os << ',';
    --itr;
  }
  os << '}';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &s) {
  os << '{';
  for (auto itr = s.begin(); itr != s.end(); ++itr) {
    os << *itr;
    if (++itr != s.end()) os << ',';
    --itr;
  }
  os << '}';
  return os;
}
void debug_out() { cerr << '\n'; }
template <class Head, class... Tail>
void debug_out(Head &&head, Tail &&...tail) {
  cerr << head;
  if (sizeof...(Tail) > 0) cerr << ", ";
  debug_out(move(tail)...);
}
template <typename T>
T gcd(T x, T y) {
  return y != 0 ? gcd(y, x % y) : x;
}
template <typename T>
T lcm(T x, T y) {
  return x / gcd(x, y) * y;
}
template <class T1, class T2>
inline bool chmin(T1 &a, T2 b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T1, class T2>
inline bool chmax(T1 &a, T2 b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
void solve() {
  int l, r;
  cin >> l >> r;
  cout << (l % (r + 1) >= (r + 2) / 2 ? "YES" : "NO") << '\n';
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (; t--;) {
    solve();
  }
}

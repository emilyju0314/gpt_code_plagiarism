#include <bits/stdc++.h>
using namespace std;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
istream& operator>>(istream& is, vector<T>& vec) {
  for (auto& v : vec) is >> v;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[ ";
  for (int i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i != v.size() - 1) os << ", ";
  }
  os << " ]\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "[ ";
  for (auto it : v) {
    os << it;
    if (it != *v.rbegin()) os << ", ";
  }
  os << " ]\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v) {
  os << "{ ";
  for (auto it : v) os << it.first << " : " << it.second << ", ";
  os << " }\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
  os << "(";
  os << v.first << ", " << v.second << ")";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, priority_queue<T> p) {
  os << "[ ";
  while (!p.empty()) {
    os << p.top() << " ,";
    p.pop();
  }
  os << " ]\n";
  return os;
}
inline long long pmod(long long i, long long n) { return (i % n + n) % n; }
const long long INF = 1e18;
const long long mod = 1e9 + 7;
void solve() {
  long long l, r;
  cin >> l >> r;
  long long x, y;
  if (r & 1) {
    if ((r - 1) / 2 >= l) {
      cout << (r - 1) / 2 << ' ' << r - 1;
    } else
      cout << "-1 -1";
    return;
  }
  if (r / 2 >= l) {
    cout << r / 2 << ' ' << r;
  } else
    cout << "-1 -1";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int t1 = 1; t1 <= t; ++t1) {
    solve();
    cout << '\n';
  }
}

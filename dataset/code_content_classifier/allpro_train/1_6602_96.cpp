#include <bits/stdc++.h>
using namespace std;
template <typename A>
string to_string(A* ptr) {
  stringstream ss;
  ss << "0x" << std::setw(16) << std::setfill('0') << std::hex
     << (uint64_t)(uintptr_t)ptr;
  return ss.str();
}
string to_string(char c) { return ((string) "'" + c) + "'"; }
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
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
const long long INF = 1e12;
const int MX = 5e5 + 99;
long long d[MX];
int LNDS(vector<long long> a) {
  int n = (int)a.size();
  d[0] = -INF;
  for (int i = 1; i <= n; ++i) d[i] = INF;
  for (int i = 0; i < n; i++) {
    int j = int(upper_bound(d, d + n, a[i]) - d);
    if (d[j - 1] <= a[i]) d[j] = min(d[j], a[i]);
  }
  int result = 0;
  for (int i = 1; i <= n; i++)
    if (d[i] != INF) result = i;
  return result;
}
int solve_range(vector<long long> V) {
  42;
  int sz = (int)V.size();
  for (int i = 0; i < sz; i++) V[i] -= i;
  42;
  int cnt_bad = 0;
  vector<long long> A;
  for (int i = 1; i < sz - 1; i++) {
    if (V[0] <= V[i] && V[i] <= V[sz - 1]) {
      A.push_back(V[i]);
    } else
      cnt_bad++;
  }
  int result = cnt_bad + (int)A.size() - LNDS(A);
  return result;
}
int n, k;
long long a[MX];
int b[MX];
int solve() {
  a[0] = -INF;
  b[0] = 0;
  a[n + 1] = INF;
  b[k + 1] = n + 1;
  int result = 0;
  for (int i = 0; i + 1 <= k + 1; i++) {
    int l = b[i], r = b[i + 1];
    long long LB = a[l], RB = a[r];
    if (LB + (r - l) > RB) return -1;
    vector<long long> V(a + l, a + (r + 1));
    result += solve_range(V);
  }
  return result;
}
int main() {
  int TT;
  TT = 1;
  for (int ttt = 0; ttt < TT; ttt++) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) cin >> b[i];
    auto res = solve();
    cout << res << '\n';
  }
  return 0;
}

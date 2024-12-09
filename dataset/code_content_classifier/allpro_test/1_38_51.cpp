#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
void inout() {}
void solve() {
  long long int n, m;
  cin >> n >> m;
  vector<string> v;
  for (long long int i = 0; i < n; i++) {
    string s;
    cin >> s;
    v.push_back(s);
  }
  vector<long long int> ans(m + 1);
  for (long long int i = 1; i < n; i++) {
    for (long long int j = 1; j < m; j++) {
      if (v[i][j - 1] == 'X' && v[i - 1][j] == 'X') ans[j] = 1;
    }
  }
  for (long long int i = 1; i < m; i++) ans[i] += ans[i - 1];
  int t = 1;
  cin >> t;
  while (t--) {
    long long int l, r;
    cin >> l >> r;
    --l;
    --r;
    if (ans[r] - ans[l] == 0)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  inout();
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

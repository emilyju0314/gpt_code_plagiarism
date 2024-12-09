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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, i;
  cin >> n;
  vector<long long> v(n), vv(n);
  for (i = 0; i < n; i++) {
    cin >> v[i];
    vv[i] = v[i];
    if (i) {
      v[i] -= vv[i - 1];
    }
  }
  long long sum = 0;
  for (i = 1; i < n; i++) {
    sum = max(sum, sum + v[i]);
  }
  cout << ((v[0] + sum + 1) >> 1) << "\n";
  long long q;
  cin >> q;
  while (q--) {
    long long l, r, x;
    cin >> l >> r >> x;
    l--;
    r--;
    if (l > 0) {
      sum = min(sum, sum - v[l]);
    }
    v[l] += x;
    if (l > 0) {
      sum = max(sum, sum + v[l]);
    }
    if (r + 1 < n) {
      sum = min(sum, sum - v[r + 1]);
      v[r + 1] -= x;
      sum = max(sum, sum + v[r + 1]);
    }
    cout << ((v[0] + sum + 1) >> 1) << "\n";
  }
  return 0;
}

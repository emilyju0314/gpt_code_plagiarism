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
vector<pair<long long int, string> > glob;
long long int countGreater(long long int arr[], long long int n,
                           long long int k) {
  long long int l = 0;
  long long int r = n - 1;
  long long int leftGreater = n;
  while (l <= r) {
    long long int m = l + (r - l) / 2;
    if (arr[m] > k) {
      leftGreater = m;
      r = m - 1;
    } else
      l = m + 1;
  }
  return (n - leftGreater);
}
void solve() {
  long long int n, count = 0;
  cin >> n;
  long long int a[n], b[n], c[n];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (long long int i = 0; i < n; i++) {
    c[i] = a[i] - b[i];
  }
  int k = sizeof(c) / sizeof(c[0]);
  sort(c, c + n);
  long long int prev = -1;
  for (int i = n; i >= 0; i--) {
    count += countGreater(c + 1 + i, n - 1 - i, -c[i]);
  }
  cout << count << endl;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

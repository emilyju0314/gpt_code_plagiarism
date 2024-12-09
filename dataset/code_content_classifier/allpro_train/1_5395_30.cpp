#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
long long moduloExp(long long x, long long y) {
  long long res = 1;
  x %= 1000000007;
  while (y) {
    if (y & 1) res = (res * x) % 1000000007;
    y /= 2;
    x = (x * x) % 1000000007;
  }
  return res;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> ans;
  int mid = (m + 1) / 2;
  int l = mid - 1;
  int r = mid + 1;
  ans.push_back(mid);
  while (l >= 1 && r <= m) {
    if (m & 1) {
      ans.push_back(l);
      ans.push_back(r);
    } else {
      ans.push_back(r);
      ans.push_back(l);
    }
    l--;
    r++;
  }
  if (!(m & 1)) {
    ans.push_back(r);
  };
  long long full = n / m;
  long long extra = n % m;
  for (int i = 0; i < full; i++) {
    for (int k : ans) cout << k << endl;
  }
  for (int i = 0; i < extra; i++) {
    cout << ans[i] << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) solve();
  return 0;
}

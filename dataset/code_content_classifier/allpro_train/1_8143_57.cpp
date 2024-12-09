#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
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
template <class T>
T gcd(T a, T b) {
  while (a != 0) {
    T temp = a;
    a = b % a;
    b = temp;
  }
  return b;
}
template <class T>
T egcd(T a, T b, T &x, T &y) {
  T gcd, xt, yt;
  if (a == 0) {
    gcd = b;
    x = 0, y = 1;
  } else {
    gcd = egcd(b % a, a, xt, yt);
    x = yt - (b / a) * xt;
    y = xt;
  }
  return gcd;
}
template <class T>
T expo(T base, T exp, T mod) {
  T res = 1;
  base = base % mod;
  while (exp > 0) {
    if (exp & 1) res = (res * base) % mod;
    exp = exp >> 1;
    base = (base * base) % mod;
  }
  return res;
}
template <class T>
T modinv(T a, T mod) {
  T x, y;
  egcd<T>(a, mod, x, y);
  while (x < 0) x += mod;
  while (x >= mod) x -= mod;
  return x;
}
template <class T>
T modinvfermat(T a, T mod) {
  return expo<T>(a, mod - 2, mod);
}
template <class T>
bool rev(T a, T b) {
  return a > b;
}
template <class T>
long long maxpower(T a, T b) {
  long long ans = 0;
  while (a > 0 && a % b == 0) {
    ans++;
    a /= b;
  }
  return ans;
}
template <class T>
T mceil(T a, T b) {
  if (a % b == 0)
    return a / b;
  else
    return a / b + 1;
}
template <class T>
T lcm(T a, T b) {
  return (a * b) / gcd<T>(a, b);
}
const long long infl = 1e18 + 5;
const int inf = 1e9 + 5;
void test_case() {
  int n, k;
  cin >> n >> k;
  int ans = mceil(n, 2 * k + 1);
  vector<int> a(ans, -1);
  for (int i = (int)(0); i < (int)(ans); i++) {
    a[i] = k + i * (2 * k + 1);
  }
  if (a[ans - 1] >= n) {
    int t = a[ans - 1] - (n - 1);
    for (int i = (int)(0); i < (int)(ans); i++) {
      a[i] -= t;
    }
  }
  cout << ans << endl;
  for (int i = (int)(0); i < (int)(ans); i++) {
    cout << a[i] + 1 << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int _;
  _ = 1;
  auto start = high_resolution_clock::now();
  cout << setprecision(10);
  while (_--) {
    test_case();
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);
  return 0;
}

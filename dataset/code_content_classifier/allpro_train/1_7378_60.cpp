#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
using namespace std;
bool dbg = 0;
clock_t start_time = clock();
void bad(string mes = "NO") {
  cout << mes;
  exit(0);
}
void bad(int mes) {
  cout << mes;
  exit(0);
}
template <typename T>
string bin(T x, int st = 2) {
  string ans = "";
  while (x > 0) {
    ans += char('0' + x % st);
    x /= st;
  }
  reverse(ans.begin(), ans.end());
  return ans.empty() ? "0" : ans;
}
mt19937_64 mt_rand(228);
template <typename T1, typename T2>
inline bool upmax(T1& a, T2 b) {
  return (a < b ? (a = b, true) : false);
}
template <typename T1, typename T2>
inline bool upmin(T1& a, T2 b) {
  return (b < a ? (a = b, true) : false);
}
template <typename T>
T input() {
  T ans = 0, m = 1;
  char c = ' ';
  while (!((c >= '0' && c <= '9') || c == '-')) {
    c = getchar();
  }
  if (c == '-') m = -1, c = getchar();
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + (c - '0'), c = getchar();
  }
  return ans * m;
}
template <typename T>
T gcd(T a, T b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
template <typename T>
void read(T& a) {
  a = input<T>();
}
template <typename T>
void read(T& a, T& b) {
  read(a), read(b);
}
template <typename T>
void read(T& a, T& b, T& c) {
  read(a, b), read(c);
}
template <typename T>
void read(T& a, T& b, T& c, T& d) {
  read(a, b), read(c, d);
}
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)1500 + 3, base = 1e9 + 7;
const long long llinf = 2e18 + 5;
const int mod = 1e9 + 7;
int binpow(int a, int n) {
  int res = 1;
  while (n) {
    if (n & 1) res = 1ll * res * a % base;
    a = 1ll * a * a % base;
    n >>= 1;
  }
  return res;
}
vector<int> b = {2, 2, 0, 0};
int n = b.size();
vector<int> first(n);
int get(int pos) {
  if (pos >= n) {
    pos -= n;
  }
  if (pos < 0) {
    pos += n;
  }
  return first[pos];
}
bool ok() {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += (b[i] - 1) * (n - i);
  }
  return sum % n == 0;
  int re = 0;
  for (int i = 0; i < n; i++) {
    re += get(i);
  }
  if (re != 0) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    if (get(i) - get(i + 1) == 1 - b[i]) {
    } else {
      return false;
    }
  }
  return true;
}
void go(int pos) {
  if (pos == n) {
    if (ok()) {
      cout << "ok";
      exit(0);
    }
    return;
  }
  for (int val = -10; val < 10; val++) {
    first[pos] = val;
    go(pos + 1);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  map<int, long long> sm;
  long long ac = 0;
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    sm[a] += b;
    ac += b;
  }
  if (ac > n) {
    cout << -1;
    return 0;
  }
  if (ac < n) {
    cout << 1;
    return 0;
  }
  long long res = -1ll * n * (n + 1) / 2;
  for (auto [a, b] : sm) {
    res += 1ll * b * (n - a);
  }
  cout << (res % n == 0 ? 1 : -1);
  return 0;
  go(0);
  return 0;
}

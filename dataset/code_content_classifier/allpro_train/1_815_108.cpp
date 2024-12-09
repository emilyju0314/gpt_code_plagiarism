#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <typename X>
inline X abs(const X &a) {
  return a < 0 ? -a : a;
}
template <typename X>
inline X sqr(const X &a) {
  return a * a;
}
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(long long &x) { scanf("%i64d", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
string toString(int n) {
  stringstream rr;
  rr << n;
  return rr.str();
}
const int size = 1e5 + 2;
const double eps = 0.0001;
const long double PI = 3.1415926535897932384626433832795;
const long long MOD = 1000000007;
const long long INF = 1LL << 60;
const long long MAX5 = 100001;
const long long MAX6 = 1000001;
void solution();
void include_file();
long long bin_search(long long left, long long right);
int main() {
  ios_base::sync_with_stdio(false);
  solution();
  return 0;
}
void include_file() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
inline bool isPrime(long long n) {
  for (int i = 2; i * i <= n; ++i)
    if (n % i == 0) return false;
  return true;
}
string ekv(string a) {
  if (a.size() & 1) return a;
  string x = ekv(a.substr(0, a.size() / 2));
  string y = ekv(a.substr(a.size() / 2));
  return min(x + y, y + x);
}
long long cubic_root(long long x) {
  long long l = 0, r = MAX6;
  while (l != r) {
    long long m = (l + r + 1) / 2;
    if (m * m * m > x)
      r = m - 1;
    else
      l = m;
  }
  return l;
}
float FastInvSqrt(float x) {
  float xhalf = 0.5f * x;
  int i = *(int *)&x;
  i = 0x5f3759df - (i >> 1);
  x = *(float *)&i;
  x = x * (1.5f - (xhalf * x * x));
  return x;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
void yes() { cout << "YES"; }
void no() { cout << "NO"; }
void yes(bool res) {
  if (res)
    cout << "YES";
  else
    cout << "NO";
}
void dabl(double x) { printf("%.10lf", x); }
namespace bits {
template <typename X>
inline X MAX(const X &a, const X &b) {
  return b & ((a - b) >> 31) | a & (~(a - b) >> 31);
}
template <typename X>
inline X MIN(const X &a, const X &b) {
  return a & ((a - b) >> 31) | b & (~(a - b) >> 31);
}
bool check2(const long long n) { return n > 0 && (n & (n - 1)); }
long long ostatok2(const long long n, const long long m) { return m & (n - 1); }
template <typename X>
void SWAP(X &a, X &b) {
  a ^= b;
  b ^= a;
  a ^= b;
}
size_t count_1_in_LL(unsigned long long n) {
  std::size_t i(0);
  for (; n; ++i) n &= n - 1;
  return i;
}
}  // namespace bits
vector<vector<int> > g;
void solution() {
  string a, b;
  cin >> a >> b;
  int k1 = 0, k2 = 0;
  for (int i = 0; i <= a.size(); i += 2) {
    if (a[i] == b[i])
      continue;
    else if (a[i] == '[') {
      if (b[i] == '(')
        k1++;
      else
        k2++;
    } else if (a[i] == '(') {
      if (b[i] == '8')
        k1++;
      else
        k2++;
    } else if (a[i] == '8') {
      if (b[i] == '[')
        k1++;
      else
        k2++;
    }
  }
  if (k1 > k2)
    cout << "TEAM 1 WINS";
  else if (k1 < k2)
    cout << "TEAM 2 WINS";
  else
    cout << "TIE";
}

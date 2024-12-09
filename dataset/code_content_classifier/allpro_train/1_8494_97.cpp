#include <bits/stdc++.h>
using namespace std;
long long read() {
  int f = 1;
  long long res = 0;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = -f;
  } while (ch < '0' || ch > '9');
  do {
    res = res * 10 + ch - '0';
    ch = getchar();
  } while (ch >= '0' && ch <= '9');
  return f == 1 ? res : -res;
}
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int N = 1000010;
const int mod = 1000000007;
const long long INF = 1e18;
int n, m, q;
int A[N];
long long p[N];
long long invp[N];
template <class T>
T mmax(T a, T b) {
  return a < b ? b : a;
}
template <class T>
T mmin(T a, T b) {
  return a < b ? a : b;
}
int countOne(int set) {
  int res = 0;
  while (set) {
    res++;
    set &= set - 1;
  }
  return res;
}
bool contain(int set, int i) { return (set & (1 << i)) > 0; }
long long myPow(long long a, int p) {
  if (p == 0) return 1;
  long long res = myPow(a, p / 2);
  res *= res;
  res %= mod;
  if (p % 2 == 1) {
    res *= a;
    res %= mod;
  }
  return res;
}
void addMod(int &a, long long b) { a = (a + b) % mod; }
long long mul(long long a, long long b) { return a * b % mod; }
template <class T>
void mySwap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}
long long C(int n, int k) {
  if (n < k) return 0;
  if (n == k) return 1;
  return p[n] * invp[k] % mod * invp[n - k] % mod;
}
long long f(int n, int k) {
  if (n - k - 1 < 0) return mul(k, myPow(n, mod - 2));
  return mul(k, myPow(n, n - k - 1));
}
int main() {
  fast_io();
  int a, b;
  cin >> n >> m >> a >> b;
  p[0] = 1;
  invp[0] = 1;
  for (int i = 1; i <= mmax(n, m); i++) {
    p[i] = p[i - 1] * i % mod;
    invp[i] = myPow(p[i], mod - 2);
  }
  int res = 0;
  long long choosePath = 1;
  for (int i = 1; i < n; i++) {
    addMod(res, mul(mul(mul(choosePath, C(m - 1, i - 1)), myPow(m, n - 1 - i)),
                    f(n, i + 1)));
    choosePath = mul(choosePath, n - i - 1);
  }
  cout << res << endl;
  return 0;
}

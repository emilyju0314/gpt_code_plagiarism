#include <bits/stdc++.h>
using namespace std;
string vow = "aeiou";
long long month[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const long long dxhorse[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const long long dyhorse[] = {1, -1, 2, -2, 2, -2, 1, -1};
const long long dx4[] = {-1, 0, 1, 0};
const long long dy4[] = {0, 1, 0, -1};
const long long dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const long long dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const long double pie = 3.1415926535897932384626;
const long long mod = 1e9 + 7;
long long fp(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * (a % mod)) % mod;
    a = ((a % mod) * (a % mod)) % mod;
    b = b >> 1;
  }
  return res;
}
long long fibo(long long n, long long memo[]) {
  if (n < 2) {
    memo[n] = n;
    return n;
  }
  if (memo[n] != -1) return memo[n];
  memo[n] = fibo(n - 1, memo) + fibo(n - 2, memo);
  return memo[n];
}
void solve() {
  long long a[3][3];
  for (long long i = 0; i < 3; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
  long long x, y, z, s = 0;
  for (long long i = 0; i < 3; i++) {
    for (long long j = 0; j < 3; j++) s += a[i][j];
  }
  s = s / 2;
  x = s - a[0][1] - a[0][2];
  y = s - a[1][0] - a[1][2];
  z = s - a[2][0] - a[2][1];
  a[0][0] = x;
  a[1][1] = y;
  a[2][2] = z;
  for (long long i = 0; i < 3; i++)
    cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  for (long long i = 1; i <= t; i++) solve();
}

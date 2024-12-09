#include <bits/stdc++.h>
using namespace std;
const long long modul = 1e9 + 7;
const long long maxn = 2e5 + 5;
const string fi = "input.txt";
const string fo = "output.txt";
long long a[maxn], b[maxn];
string c[1004];
long long ucln(long long m, long long n) {
  while (n != 0) {
    long long du = m % n;
    m = n;
    n = du;
  }
  return m;
}
long long ans(long long a, long long b) {
  long long x = ucln(a, b);
  a = a / x;
  b = b / x;
  long long cnt = 0;
  while (a % 2 == 0) {
    a = a / 2;
    cnt++;
  }
  while (a % 3 == 0) {
    a = a / 3;
    cnt++;
  }
  while (a % 5 == 0) {
    a = a / 5;
    cnt++;
  }
  while (b % 2 == 0) {
    b = b / 2;
    cnt++;
  }
  while (b % 3 == 0) {
    b = b / 3;
    cnt++;
  }
  while (b % 5 == 0) {
    b = b / 5;
    cnt++;
  }
  if (a != 1 or b != 1) return -1;
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie();
  long long a, b;
  cin >> a >> b;
  cout << ans(a, b);
}

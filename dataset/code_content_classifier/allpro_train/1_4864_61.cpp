#include <bits/stdc++.h>
using namespace std;
fstream fout;
fstream fin;
const long double pi = 3.141592653589793;
const long double EPS = 1e-9;
long long GCD(long long a, long long b) { return (a) ? GCD(b % a, a) : b; }
long long LCM(long long a, long long b) { return (a / GCD(a, b)) * b; }
long long fastpow(long long b, long long p) {
  if (!p) return 1;
  long long ret = fastpow(b, p >> 1);
  ret *= ret;
  if (p & 1) ret *= b;
  return ret;
}
long long PowMod(long long bs, long long ex, long long M) {
  if (!ex) return 1;
  long long p = PowMod((bs * bs) % M, ex >> 1, M);
  return (ex & 1) ? (p * bs) % M : p;
}
long long ModInverse(long long a) {
  return PowMod(a, 1000000007 - 2, 1000000007);
}
void solve(int TT) {
  int x;
  cin >> x;
  for (int i = 2; i < x; i++) {
    if (x % i) continue;
    cout << i << x / i << '\n';
    break;
  }
}
void init() {}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  if (0) {
    fout.open("output.txt", ios::out);
    if (!fout) cout << "noo!\noutput filee!\n\n";
  }
  if (0) {
    fin.open("input.txt", ios::in);
    if (!fin) cout << "noo!\ninput filee!\n\n";
  }
  int t = 1;
  init();
  for (int tt = 1; tt <= t; tt++) solve(tt);
  if (0) fout.close();
  if (0) fin.close();
  return 0;
}

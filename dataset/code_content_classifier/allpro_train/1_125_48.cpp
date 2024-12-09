#include <bits/stdc++.h>
using namespace std;
string out[20] = {"x^y^z", "x^z^y", "(x^y)^z", "(x^z)^y",
                  "y^x^z", "y^z^x", "(y^x)^z", "(y^z)^x",
                  "z^x^y", "z^y^x", "(z^x)^y", "(z^y)^x"};
const int Maxn = 1e5 + 1000;
long double a, b, c, mx = -5e100l;
int res;
void put_in() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> a >> b >> c;
}
void output() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << out[res] << '\n';
}
void cmp1(long double x, long double y, long double z, int i) {
  long double tmp = logl(x);
  if (tmp * powl(y, z) > mx) {
    mx = tmp * powl(y, z);
    res = i;
  }
}
void cmp2(long double x, long double y, long double z, int i) {
  long double tmp = logl(x);
  cerr << out[i] << ": " << setprecision(200) << fixed << tmp * y * z << '\n';
  if (tmp * y * z > mx) {
    mx = tmp * y * z;
    res = i;
  }
}
void problem_fucker() {
  cmp1(a, b, c, 0);
  cmp1(a, c, b, 1);
  cmp2(a, b, c, 2);
  cmp1(b, a, c, 4);
  cmp1(b, c, a, 5);
  cmp2(b, a, c, 6);
  cmp1(c, a, b, 8);
  cmp1(c, b, a, 9);
  cmp2(c, a, b, 10);
}
int main() {
  put_in();
  problem_fucker();
  output();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / __gcd(a, b));
}
template <class T>
T power(T N, T P) {
  return (P == 0) ? 1 : N * power(N, P - 1);
}
long long toInt64(string s) {
  long long r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
double LOG(double N, double B) { return (log10l(N)) / (log10l(B)); }
string itoa(long long a) {
  if (a == 0) return "0";
  string ret;
  for (long long i = a; i > 0; i = i / 10) ret.push_back((i % 10) + 48);
  reverse(ret.begin(), ret.end());
  return ret;
}
vector<string> token(char *s, char *d) {
  vector<string> v;
  char *pch = strtok(s, d);
  while (pch) {
    v.push_back(pch);
    pch = strtok(NULL, d);
  }
  return v;
}
int toggle(int N, int pos) {
  if ((N & (1 << (pos)))) return N = (N & ~(1 << (pos)));
  return N = (N | (1 << (pos)));
}
void pbit(int N) {
  printf("(");
  for (int i = 10; i >= 0; i--) {
    bool x = (N & (1 << (i)));
    cout << x;
  }
  puts(")");
}
bool eq(double a, double b) { return (fabs(a - b) < 1e-9); }
double x[500002], v[500002];
double f(double mid, int n) {
  double MAX = -(1e25);
  bool coll = 0;
  for (int i = 0; i < (int)n; i++) {
    double nx = x[i] + v[i] * mid;
    if (v[i] > 0)
      MAX = max(MAX, nx);
    else {
      if (nx < MAX) {
        coll = 1;
        break;
      }
    }
  }
  return coll;
}
double search(int n) {
  double ans = -1;
  double lo = 0, hi = 3e9, mid;
  for (int lp = 0; lp < (int)100; lp++) {
    mid = (lo + hi) / 2;
    double coll = f(mid, n);
    if (coll) {
      ans = mid;
      hi = mid;
    } else
      lo = mid;
  }
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (int)n; i++) {
    scanf("%lf %lf", &x[i], &v[i]);
  }
  printf("%.13lf\n", search(n));
}

#include <bits/stdc++.h>
using namespace std;
struct comp {
  bool operator()(const vector<int>& lhs, const vector<int>& rhs) const {
    return lhs.size() > rhs.size();
  }
};
struct comps {
  bool operator()(const string& lhs, const string& rhs) const {
    return lhs > rhs;
  }
};
bool ff(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }
double dis(double x1, double y1, double x2, double y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
int gcd(long long unsigned int a, long long unsigned int b) {
  return (b == 0) ? a : gcd(b, a % b);
}
int comb(int a, int b) {
  if (a == 0) return 1;
  if (a < b) return 1;
  if (a == b) return 1;
  if (b == 1) return a;
  if (b == 0) return 1;
  long long unsigned int aa = 1, bb = 1;
  for (int i = b; i > 0; i--, a--) {
    aa *= a;
    bb *= i;
    int gc = gcd(aa, bb);
    if (gc > 1) {
      aa /= gc;
      bb /= gc;
    }
  }
  return aa % 1000000007;
}
bool isprime(long long unsigned int n) {
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
bool f(pair<int, int> p1, pair<int, int> p2) {
  if (p1.first < p2.first)
    return true;
  else if ((p1.first == p2.first) && (p1.second > p2.second))
    return true;
  else
    return false;
}
double t[100005];
double v[100005];
double tt[100005];
int main() {
  double n, a, d;
  scanf("%lf%lf%lf", &n, &a, &d);
  for (int i = 0; i < n; i++) scanf("%lf%lf", &t[i], &v[i]);
  tt[0] = ((v[0] * v[0] * 1.0) / (2 * a) >= d + 0.0001)
              ? sqrt(2 * d / a)
              : d / v[0] + v[0] / (2 * a);
  tt[0] += t[0];
  for (int i = 1; i < n; i++) {
    tt[i] = ((v[i] * v[i] * 1.0) / (2 * a) >= d + 0.0001)
                ? sqrt(2 * d / a)
                : d / v[i] + v[i] / (2 * a);
    if (tt[i - 1] > t[i] + tt[i] + 0.0001)
      tt[i] = tt[i - 1];
    else
      tt[i] = t[i] + tt[i];
  }
  for (int i = 0; i < n; i++) printf("%.10lf\n", tt[i]);
  return 0;
}

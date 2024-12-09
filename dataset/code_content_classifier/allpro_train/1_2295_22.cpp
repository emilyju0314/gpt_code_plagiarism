#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T abs(T a) {
  return ((a < 0) ? -a : a);
}
template <typename T>
inline T sqr(T a) {
  return a * a;
}
const int INF = (int)1E9 + 7;
const long double EPS = 1E-10;
const long double PI = 3.1415926535897932384626433832795;
int n;
vector<long double> a;
bool check(const vector<long double>& a) {
  if (int((a).size()) <= 1) return true;
  if (fabs(a[0]) < EPS) {
    for (int i = 0; i < int(int((a).size())); ++i)
      if (fabs(a[i]) > EPS) return false;
    return true;
  }
  long double b = a[1] / a[0], cur = a[0];
  for (int i = 0; i < int(int((a).size())); ++i) {
    if (fabs(a[i] - cur) > EPS) return false;
    cur *= b;
  }
  return true;
}
vector<int> getz(const vector<long double>& a) {
  vector<int> z(int((a).size()));
  int l = 0, r = -1;
  for (int i = int(1); i < int(int((a).size())); ++i) {
    z[i] = i > r ? 0 : min(z[i - l], r - i + 1);
    while (i + z[i] < int((a).size()) && fabs(a[z[i]] - a[i + z[i]]) < EPS)
      z[i]++;
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
int main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < int(n); ++i) {
    int x;
    scanf("%d", &x);
    a[i] = x;
  }
  if (check(a)) {
    puts("0");
    exit(0);
  }
  for (int i = 0; i < int(2); ++i) {
    vector<long double> b = a;
    b.erase(b.begin() + i);
    if (check(b)) {
      puts("1");
      exit(0);
    }
  }
  vector<long double> ok(n - 1, 0);
  if (fabs(a[0]) > EPS) {
    long double d = a[1] / a[0];
    ok[0] = a[0], ok[1] = a[1];
    for (int i = int(2); i < int(int((ok).size())); ++i) ok[i] = ok[i - 1] * d;
  }
  vector<long double> t1 = ok;
  t1.insert(t1.end(), (a).begin(), (a).end());
  vector<int> z1 = getz(t1);
  reverse((ok).begin(), (ok).end());
  reverse((a).begin(), (a).end());
  ok.insert(ok.end(), (a).begin(), (a).end());
  vector<int> z2 = getz(ok);
  if (z1[n - 1] + z2[n - 1] >= n - 1)
    puts("1");
  else
    puts("2");
  return 0;
}

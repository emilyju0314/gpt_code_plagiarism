#include <bits/stdc++.h>
int diri[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dirj[] = {0, 1, 0, -1, 1, 1, -1, -1};
int compare(double d1, double d2) {
  if (fabs(d1 - d2) < 1e-9) return 0;
  if (d1 < d2) return -1;
  return 1;
}
using namespace std;
int n, v;
double valid(double x, vector<int> &a, vector<int> &mx) {
  double sum = 0;
  for (int i = 0; i < (int)a.size(); i++) {
    if (compare(x * a[i], mx[i]) == 1) return -1;
    sum += x * a[i];
    if (compare(sum, v) == 1) return -1;
  }
  return sum;
}
int main() {
  cin >> n >> v;
  vector<int> a(n), mx(n);
  for (int i = 0; i < (int)n; i++) cin >> a[i];
  for (int i = 0; i < (int)n; i++) cin >> mx[i];
  double s = 0, e = 10000;
  while (compare(s, e) < 0) {
    double md = s + (e - s) / 2;
    if (valid(md, a, mx) != -1) {
      s = md;
    } else {
      e = md;
    }
  }
  cout << valid(s, a, mx) << endl;
  return 0;
}

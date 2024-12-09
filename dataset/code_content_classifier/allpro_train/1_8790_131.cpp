#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-11;
int n;
long long tim, T;
struct node {
  double a, t;
  long long l, r;
} pro[200500];
bool cmp1(node a, node b) { return a.a / a.t > b.a / b.t; }
bool cmp2(node a, node b) { return a.a < b.a; }
bool check(double c) {
  double maxx = 0;
  for (int i = 1, j = 1; i <= n; i = j) {
    double max2 = 0;
    while (j <= n && pro[i].a == pro[j].a) {
      double max1 = pro[j].a * (1.0 - c * pro[j].l / T);
      double min1 = pro[j].a * (1.0 - c * pro[j].r / T);
      if (max2 < max1 + eps) max2 = max1;
      if (min1 + eps < maxx) return false;
      j++;
    }
    if (maxx + eps < max2) maxx = max2;
  }
  return true;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> pro[i].a;
  for (int i = 1; i <= n; i++) cin >> pro[i].t, T += pro[i].t;
  sort(pro + 1, pro + 1 + n, cmp1);
  for (int i = 1, j = 1; i <= n; i = j) {
    double sum = 0;
    while (j <= n && fabs(pro[i].a / pro[i].t - pro[j].a / pro[j].t) <= eps) {
      pro[j].l = tim + pro[j].t;
      sum += pro[j].t;
      j++;
    }
    for (int k = i; k < j; k++) pro[k].r = tim + sum;
    tim += sum;
  }
  sort(pro + 1, pro + 1 + n, cmp2);
  double l = 0, r = 1;
  while (l + eps < r) {
    double mid = (l + r) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%.11f", l);
  return 0;
}

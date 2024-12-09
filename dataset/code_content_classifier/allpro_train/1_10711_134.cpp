#include <bits/stdc++.h>
using namespace std;
int arr[100];
int main() {
  double k, n, s, p;
  scanf("%lf%lf%lf%lf", &k, &n, &s, &p);
  double tot = k * ceil(n / s);
  printf("%.0lf\n", ceil(tot / p));
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
template <typename F>
double ternary_search(double lb, double ub, double prec, F fun) {
  for (;;) {
    if (ub - lb < prec) return (ub + lb) / 2;
    double lmid = (2 * lb + ub) / 3, umid = (lb + 2 * ub) / 3;
    if (fun(lmid) > fun(umid))
      lb = lmid;
    else
      ub = umid;
  }
}
struct dist {
  double l, a, b;
  dist(double l, double a, double b) : l(l), a(a), b(b) {}
  double operator()(double x) {
    double h = sqrt(l * l - x * x);
    return (h * a + b * x - x * h) / l;
  }
};
int main() {
  int a, b, l;
  cin >> a >> b >> l;
  if (a > b) swap(a, b);
  double ret;
  if (l <= a)
    ret = l;
  else if (l <= b)
    ret = a;
  else {
    dist fun(l, a, b);
    double x0 = ternary_search(0, l, 1e-8, fun);
    ret = fun(x0);
  }
  if (ret < 1e-8)
    puts("My poor head =(");
  else
    printf("%.7f\n", ret);
}

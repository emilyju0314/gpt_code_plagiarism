#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k, d, t;
  scanf("%lld%lld%lld", &k, &d, &t);
  double time = 0, c = 1.0 / t, w = 0.5 / t;
  if (k % d == 0)
    time = 1.0 * t;
  else if (k < d) {
    double ui = k * c + (d - k) * w;
    long long cnt = (long long)(1.0 / ui);
    time += cnt * d;
    double left = 1.0 - cnt * ui;
    if (left <= c * k)
      time += left / c;
    else
      time += k + (left - c * k) / w;
  } else {
    long long gap = (k / d + 1) * d - k;
    double ui = k * c + gap * w;
    long long cnt = (long long)(1.0 / ui);
    time += cnt * (k + gap);
    double left = 1.0 - cnt * ui;
    if (left <= c * k)
      time += left / c;
    else
      time += k + (left - c * k) / w;
  }
  printf("%f\n", time);
}

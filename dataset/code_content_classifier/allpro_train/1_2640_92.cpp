#include <bits/stdc++.h>
using namespace std;
bool debug = 1;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
long long ln, lk, lm;
int x[100005], d[100005];
long long L[100005], R[100005];
void cal() {
  set<pair<long long, long long>> s;
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    L[i] = -1;
    if (x[i] < d[i] + d[i]) {
      L[i] = 2 * d[i];
    }
    while (!s.empty()) {
      auto p = *s.begin();
      if (L[p.second] < x[i]) {
        s.erase(p);
      } else {
        long long tmp = -p.first;
        L[i] = (long long)d[i] * 2 + tmp;
        break;
      }
    }
    if (L[i] > x[i]) {
      if (L[i] >= x[n + 1]) {
        puts("0");
        exit(0);
      }
      s.insert({-x[i], i});
    }
  }
  s.clear();
  for (int i = n; i >= 1; i--) {
    R[i] = (1LL << 60);
    if (x[n + 1] - x[i] < d[i] + d[i]) {
      R[i] = x[n + 1] - 2 * d[i];
    }
    while (!s.empty()) {
      auto p = *s.begin();
      if (R[p.second] > x[i]) {
        s.erase(p);
      } else {
        long long tmp = p.first;
        R[i] = (long long)tmp - d[i] * 2;
        break;
      }
    }
    if (R[i] < x[i]) {
      assert(R[i] > 0);
      s.insert({x[i], i});
    }
  }
  long long ans = x[n + 1];
  s.clear();
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    if (!s.empty() && R[i] < x[i]) {
      auto it = s.lower_bound({R[i], -(1LL << 60)});
      if (it != s.end()) {
        ans = min(x[i] + (*it).second, ans);
      }
    }
    if (L[i] > x[i]) {
      s.insert({L[i], -x[i]});
      ans = min(ans, (long long)x[n + 1] - x[i]);
    }
    if (R[i] < x[i]) {
      ans = min(ans, (long long)x[i]);
    }
  }
  printf("%.1lf\n", (double)ans / 2);
}
int main() {
  scanf("%d", &n);
  for (int(i) = 0; (i) < (int)(n + 2); (i)++) {
    scanf("%d", x + i);
  }
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    scanf("%d", d + i);
  }
  cal();
  return 0;
}

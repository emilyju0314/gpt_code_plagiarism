#include <bits/stdc++.h>
using namespace std;
constexpr int N = 10;
int m, nf, ne, ns, cnt[N], upp[N], sum;
double rf, re, rs, df, de, ans, diff[N * 2];
inline void trans(double& d) { d = sqrt(d * d - 1); }
inline int pos(int i) { return (i >= sum / 2) ? i - sum / 2 : i; }
inline double calc(double r0, int x0, double r1, int x1) {
  return max(min(x0 + r0, x1 + r1) - max(x0 - r0, x1 - r1), 0.0);
}
int main() {
  scanf("%d %d %d", &nf, &ne, &ns);
  scanf("%lf %lf %lf", &rf, &re, &rs);
  trans(rf);
  trans(re);
  trans(rs);
  scanf("%lf %lf", &df, &de);
  sum = nf + ne + ns;
  m = (sum + 1) / 2;
  for (int i = 0; i < sum; ++i) ++upp[pos(i)];
  vector<bool> prm(ns, true);
  prm.resize(sum);
  do {
    memset(cnt, 0, m * sizeof(int));
    for (int i = 0; i < sum; ++i) cnt[pos(i)] += prm[i];
    int tmp_cnt = 0;
    double tmp_ans = 0;
    for (int i = 0; i < m; ++i) {
      if (cnt[i] < upp[i]) {
        for (int k = cnt[i]; k < upp[i]; ++k) {
          double ff = 2 * rf * df, ee = 2 * re * de;
          for (int j = 0; j < m; ++j) {
            if (cnt[j]) {
              ff += df * calc(rf, i, rs, j) * cnt[j];
              ee += de * calc(re, i, rs, j) * cnt[j];
            }
          }
          diff[tmp_cnt++] = ee - ff;
          tmp_ans += ee;
        }
      }
    }
    sort(diff, diff + tmp_cnt);
    for (int i = 0; i < nf; ++i) tmp_ans -= diff[i];
    ans = max(ans, tmp_ans);
  } while (prev_permutation(prm.begin(), prm.end()));
  printf("%.8f\n", ans);
}

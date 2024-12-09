#include <bits/stdc++.h>
using namespace std;
const int MaxN = 5010, inf = 1 << 20;
int tim[MaxN][3];
bool hack[MaxN][3];
vector<int> drop[MaxN];
int dtot, hacksum[3];
int score[MaxN][3], sum[3], limit[7], pro[3];
int my_score;
int n;
inline int bit(int s, int i) { return (s >> i) & 1; }
inline int get_score(int s, int t) { return s * (250 - t) / 250; }
inline int cmax(int &x, int v) { return x < v ? x = v : x; }
int f[95][95][95];
int dp() {
  if (!dtot) return 1;
  memset(f, 0, sizeof f);
  int ret = 0;
  for (int p = 1; p <= dtot; ++p)
    for (int i = pro[0]; i >= 0; --i)
      for (int j = pro[1]; j >= 0; --j)
        for (int k = pro[2]; k >= 0; --k)
          for (auto s : drop[p]) {
            int ni = i + bit(s, 0), nj = j + bit(s, 1), nk = k + bit(s, 2);
            if (ni > pro[0] || nj > pro[1] || nk > pro[2]) continue;
            cmax(f[ni][nj][nk], f[i][j][k] + 1);
            cmax(ret, f[ni][nj][nk]);
          }
  return dtot - ret + 1;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < 3; ++j) {
      scanf("%d", &tim[i][j]);
      if (tim[i][j] < 0) {
        hack[i][j] = 1;
        ++hacksum[j];
        tim[i][j] = -tim[i][j];
      }
      sum[j] += (tim[i][j] > 0);
    }
  for (int i = 0; i <= 5; ++i) limit[i] = n + 1;
  for (int k = n; k >= 0; --k)
    for (int j = 1; j <= 5; ++j)
      if ((k << j) > n) limit[j] = k;
  int ans = n;
  for (int i = 1; i <= 6; ++i)
    for (int j = 1; j <= 6; ++j)
      for (int k = 1; k <= 6; ++k) {
        if (sum[0] < limit[i] || sum[1] < limit[j] || sum[2] < limit[k])
          continue;
        pro[0] = min(sum[0] - limit[i], hacksum[0]);
        pro[1] = min(sum[1] - limit[j], hacksum[1]);
        pro[2] = min(sum[2] - limit[k], hacksum[2]);
        if (sum[0] - limit[i - 1] >= pro[0] ||
            sum[1] - limit[j - 1] >= pro[1] || sum[2] - limit[k - 1] >= pro[2])
          continue;
        my_score = (pro[0] + pro[1] + pro[2]) * 100;
        for (int p = 1; p <= n; ++p) {
          if (tim[p][0]) score[p][0] = get_score(i * 500, tim[p][0]);
          if (tim[p][1]) score[p][1] = get_score(j * 500, tim[p][1]);
          if (tim[p][2]) score[p][2] = get_score(k * 500, tim[p][2]);
        }
        my_score += (score[1][0] + score[1][1] + score[1][2]);
        dtot = 0;
        for (int p = 2; p <= n; ++p) {
          int sc = score[p][0] + score[p][1] + score[p][2];
          if (sc > my_score) {
            ++dtot;
            drop[dtot].clear();
            for (int s = 1; s < 8; ++s) {
              int sum = 0;
              for (int t = 0; t < 3; ++t)
                if (bit(s, t)) {
                  if (!hack[p][t])
                    sum = -inf;
                  else
                    sum += score[p][t];
                }
              if (sc - sum <= my_score) drop[dtot].push_back(s);
            }
          }
        }
        ans = min(ans, dp());
      }
  cout << ans << endl;
  return 0;
}

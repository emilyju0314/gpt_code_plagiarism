#include <bits/stdc++.h>
using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
i64 arr[100005];
bool isin[105][100005];
int heavyidx[100005];
vector<int> group[100005];
vector<int> heavy;
i64 intersect[100005][105];
i64 counter[105];
i64 sum[105];
int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
  int bucket = 1005;
  for (int i = 1; i <= m; i++) {
    int k;
    scanf("%d", &k);
    group[i].resize(k);
    if (k > bucket) {
      heavyidx[i] = heavy.size();
      heavy.push_back(i);
    }
    for (int j = 0; j < k; j++) {
      scanf("%d", &group[i][j]);
      if (k > bucket) {
        isin[heavyidx[i]][group[i][j]] = true;
        sum[heavyidx[i]] += arr[group[i][j]];
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    for (auto& mi : group[i]) {
      for (int j = 0; j < heavy.size(); j++) {
        if (isin[j][mi]) intersect[i][j]++;
      }
    }
  }
  for (int i = 0; i < q; i++) {
    char buf[3];
    int k;
    scanf("%s %d", buf, &k);
    if (buf[0] == '?') {
      i64 ans = 0;
      if (group[k].size() <= bucket) {
        for (auto& gi : group[k]) ans += arr[gi];
      } else {
        ans = sum[heavyidx[k]];
      }
      for (int h = 0; h < heavy.size(); h++)
        ans += intersect[k][h] * counter[h];
      printf("%lld\n", ans);
    } else {
      int x;
      scanf("%d", &x);
      if (group[k].size() <= bucket) {
        for (auto& gi : group[k]) arr[gi] += x;
        for (int h = 0; h < heavy.size(); h++) sum[h] += intersect[k][h] * x;
      } else {
        counter[heavyidx[k]] += x;
      }
    }
  }
  return 0;
}

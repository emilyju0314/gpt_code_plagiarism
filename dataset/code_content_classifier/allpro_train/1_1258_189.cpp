#include <bits/stdc++.h>
using namespace std;
int n, dp[1000005], p[1000005], i, ind[1000005];
bool h[21][1000005];
bool mx_cnt[1000005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  scanf("%d", &n);
  int ans = 0;
  p[0] = -1;
  for (i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
    p[i]--;
    int m = 1;
    int v = p[i], fhdjskdhdf = i;
    while (v != -1) {
      if (h[m][fhdjskdhdf] == 1) break;
      h[m][fhdjskdhdf] = true;
      if (dp[v] > m) break;
      if (dp[v] < m) {
        dp[v] = m;
        mx_cnt[v] = 0;
        ind[v] = fhdjskdhdf;
      } else {
        if (v != 0) {
          if (mx_cnt[v] || (!mx_cnt[v] && ind[v] != fhdjskdhdf)) m++;
          if (!mx_cnt[v] && ind[v] != fhdjskdhdf) {
            mx_cnt[v] = 1;
            ind[v] = fhdjskdhdf;
          }
        }
      }
      fhdjskdhdf = v;
      v = p[v];
    }
    if (v == -1) ans = m;
    printf("%d ", ans);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, k, m[100005], ans, ini;
vector<int> ma[100005];
int main() {
  int i, j, a;
  scanf("%d%d", &n, &k);
  for (i = 1; i <= k; i++) {
    scanf("%d", &m[i]);
    for (j = 1; j <= m[i]; j++) {
      scanf("%d", &a);
      ma[i].push_back(a);
    }
  }
  for (i = 1; i <= k; i++) {
    if (ma[i][0] == 1) {
      for (j = 1; j < ma[i].size(); j++)
        if (ma[i][j] != ma[i][j - 1] + 1) {
          break;
        }
      ans += ma[i].size() - j;
      ini = j;
    } else
      ans += ma[i].size() - 1;
  }
  ans += (n - ini);
  printf("%d\n", ans);
  return 0;
}

#include <bits/stdc++.h>
const int N = 300300;
const int magic = 547;
using namespace std;
long long n, m, w[N], ans[N], d[N];
vector<pair<int, int> > v[magic + 1];
int main() {
  scanf("%I64d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d", &w[i]);
  scanf("%I64d", &m);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (b > magic)
      for (int j = a; j <= n; j += b) ans[i] += w[j];
    else
      v[b].push_back({a, i});
  }
  for (int i = 1; i <= magic; i++) {
    for (int j = 1; j <= n; j++) d[j] = w[j];
    for (int j = n; j > i; j--) d[j - i] += d[j];
    for (int j = 0; j < v[i].size(); j++)
      ans[v[i][j].second] = d[v[i][j].first];
  }
  for (int i = 1; i <= m; i++) printf("%I64d\n", ans[i]);
}

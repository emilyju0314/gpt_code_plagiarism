#include <bits/stdc++.h>
using namespace std;
int n, d[509][509], inf = 1e9, x, a[509], take[509];
long long ans;
vector<long long> v;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &d[i][j]);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = n; i > 0; i--) {
    ans = 0;
    int k = a[i];
    take[k] = 1;
    for (int a = 1; a <= n; a++)
      for (int b = 1; b <= n; b++) d[a][b] = min(d[a][b], d[a][k] + d[k][b]);
    for (int a = 1; a <= n; a++)
      for (int b = 1; b <= n; b++)
        if (d[a][b] < inf && take[a] && take[b]) ans += d[a][b];
    v.push_back(ans);
  }
  reverse(v.begin(), v.end());
  for (auto i : v) cout << i << " ";
}

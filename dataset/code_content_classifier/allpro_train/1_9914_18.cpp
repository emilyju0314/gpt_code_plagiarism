#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int maxn = 1000005;
const int mod = 100000000;
long long dpr[maxn], dpc[maxn], sumc[1005], sumr[1005];
int n, m, p, k;
int a[1005][1005];
void solve() {
  priority_queue<long long> Q;
  dpr[0] = dpc[0] = 0;
  for (int i = 1; i <= n; i++) Q.push(sumr[i]);
  for (int i = 1; i <= k; i++) {
    long long tmp = Q.top();
    Q.pop();
    dpr[i] = dpr[i - 1] + tmp;
    tmp -= m * p;
    Q.push(tmp);
  }
  while (!Q.empty()) Q.pop();
  for (int i = 1; i <= m; i++) Q.push(sumc[i]);
  for (int i = 1; i <= k; i++) {
    long long tmp = Q.top();
    Q.pop();
    dpc[i] = dpc[i - 1] + tmp;
    tmp -= n * p;
    Q.push(tmp);
  }
}
int main() {
  while (~scanf("%d%d%d%d", &n, &m, &k, &p)) {
    memset(sumr, 0, sizeof(sumr));
    memset(sumc, 0, sizeof(sumc));
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        scanf("%d", &a[i][j]);
        sumr[i] += a[i][j];
        sumc[j] += a[i][j];
      }
    solve();
    long long ans = dpr[0] + dpc[k];
    for (int i = 0; i <= k; i++) {
      ans = max(ans, dpr[i] + dpc[k - i] - (long long)i * (k - i) * p);
    }
    cout << ans << endl;
  }
  return 0;
}

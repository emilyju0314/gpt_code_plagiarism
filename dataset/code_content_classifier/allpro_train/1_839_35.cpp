#include <bits/stdc++.h>
using namespace std;
const int N = 100005, A = 5005;
int n, k, f[N], d[N], D[A], F[A], a[20];
int solve(int x, int y) {
  for (int i = 1; i <= n * k; i++) D[i] = F[i] = 0;
  for (int i = 1; i <= x; i++) {
    for (int j = 1; j <= y; j++)
      for (int z = 1; z <= min(j, k); z++) D[j] = max(D[j], F[j - z] + a[z]);
    for (int j = 1; j <= y; j++) F[j] = D[j], D[j] = 0;
  }
  return F[y];
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n * k; i++) {
    int x;
    cin >> x;
    f[x]++;
  }
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    d[x]++;
  }
  for (int i = 1; i <= k; i++) cin >> a[i];
  int ans = 0;
  for (int i = 1; i <= 100000; i++)
    if (d[i]) ans += solve(d[i], f[i]);
  cout << ans << endl;
  return 0;
}

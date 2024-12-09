#include <bits/stdc++.h>
using namespace std;
long long dgr[1000010], n, m;
int main() {
  int i, u, v;
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    dgr[u]++;
    dgr[v]++;
  }
  long long tot, cut = 0;
  for (i = 1; i <= n; i++) cut += dgr[i] * (dgr[i] - 1) / 2;
  cut -= m * (n - 2);
  tot = n * (n - 1) * (n - 2) / 6;
  tot += cut;
  cout << tot << endl;
  return 0;
}

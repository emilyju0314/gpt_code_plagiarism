#include <bits/stdc++.h>
using namespace std;
long long P = 1e9 + 7;
long long INF = 1e9 + 7;
int a[5005];
int color[500];
pair<int, int> p[5005];
int main() {
  int n, m;
  cin >> n >> m;
  int i;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    color[a[i]]++;
    p[i] = make_pair(a[i], i);
  }
  int fl = 0;
  for (i = 1; i <= m; i++)
    if (color[i] > n / 2) {
      cout << 2 * n - color[i] * 2 << "\n";
      fl = 1;
      break;
    }
  if (fl == 0) cout << n << "\n";
  sort(p, p + n);
  for (i = 0; i < n; i++) {
    int j = p[i].second;
    int i_new = (i + n / 2) % n;
    cout << a[j] << " " << a[p[i_new].second] << "\n";
  }
  return 0;
}

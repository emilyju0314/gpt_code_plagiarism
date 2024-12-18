#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int n, m, k;
int pos[MAXN];
pair<int, int> a[MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  long long sum = 0;
  int cnt = 0, Cnt = 0;
  for (int i = 1; i <= m * k; i++) sum += a[i].first;
  for (int i = 1; i <= n; i++) pos[a[i].second] = i;
  cout << sum << endl;
  for (int i = 1; i <= n; i++)
    if (pos[i] <= m * k) {
      cnt++;
      if (cnt == m) {
        Cnt++;
        if (Cnt < k) cout << i << ' ';
        cnt = 0;
      }
    }
  cout << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int rd() { return RAND_MAX == 32767 ? ((rand() << 15) ^ rand()) : rand(); }
const int maxn = 2000010;
int q[maxn], w[maxn];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> q[i] >> w[i];
  sort(w, w + m);
  reverse(w, w + m);
  int opt = 1;
  if (m >= 2 && n >= 2) opt = 2;
  for (int k = 3; k <= m; k++)
    if (k % 2 == 1) {
      if ((long long)k * (k - 1) / 2 + 1 <= n) opt = k;
    } else {
      int odd = k / 2;
      if ((long long)k * (k - 1) / 2 + odd <= n) opt = k;
    }
  long long res = 0;
  for (int i = 0; i < opt; i++) res += w[i];
  cout << res << endl;
  return 0;
}

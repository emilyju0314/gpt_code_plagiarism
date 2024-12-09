#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int f[N], A[N], C[20], n, m, x, y;
int main() {
  string s;
  cin >> s;
  n = s.size();
  s = ' ' + s;
  memset(f, 0xf, sizeof(f));
  long long ans = 0;
  for (int i = n - 2; i >= 1; --i) {
    f[i] = min(f[i], f[i + 1]);
    for (int j = 1; j <= 20 && i + j * 2 <= n && i + j * 2 <= f[i]; ++j) {
      if (s[i] == s[i + j] && s[i + j] == s[i + j * 2]) {
        f[i] = i + j * 2;
        break;
      }
    }
    if (f[i] < N) ans += n - f[i] + 1;
  }
  cout << ans << endl;
}

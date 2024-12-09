#include <bits/stdc++.h>
using namespace std;
long long int n, cur[5001][27], tot[5005], ext[5005], C[5005][5005];
string s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> s;
  s = "$" + s;
  cur[1][s[1] - 'a' + 1] = 1;
  tot[1] = 1;
  for (long long int i = 2; i <= n; ++i) {
    long long int c = s[i] - 'a' + 1;
    ext[1] = 1;
    for (long long int len = 2; len <= n; ++len)
      ext[len] = ((tot[len - 1] - cur[len - 1][c]) % 1000000007 + 1000000007) %
                 1000000007;
    for (long long int len = 1; len <= n; ++len) {
      long long int tem = cur[len][c];
      cur[len][c] = (ext[len]) % 1000000007;
      tot[len] = (tot[len] + ext[len]) % 1000000007;
      tot[len] = (tot[len] - tem) % 1000000007;
      tot[len] += 1000000007;
      tot[len] %= 1000000007;
    }
  }
  for (long long int i = 0; i <= n; ++i) C[i][0] = 1;
  for (long long int i = 1; i <= n; ++i)
    for (long long int j = 1; j <= i; ++j) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % 1000000007;
    }
  long long int ans = 0;
  for (long long int len = 1; len <= n; ++len) {
    ans = (ans + (C[n - 1][len - 1] * tot[len]) % 1000000007) % 1000000007;
  }
  cout << ans << '\n';
}

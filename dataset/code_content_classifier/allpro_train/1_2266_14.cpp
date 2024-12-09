#include <bits/stdc++.h>
using namespace std;
char CRTBUFF[30000];
struct debugger {
  static void call(const char* it) {}
  template <typename T, typename... aT>
  static void call(const char* it, T a, aT... rest) {
    string b;
    for (; *it && *it != ','; ++it)
      if (*it != ' ') b += *it;
    cerr << b << "=" << a << " ";
    call(++it, rest...);
  }
};
long long pow(int n, int e) {
  long long ans = 1;
  while (e--) {
    ans = ((ans % 1000000007) * n) % 1000000007;
  }
  return (ans) % 1000000007;
}
long long power(long long x, long long y) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0)
    return ((power(x, y / 2)) % 1000000007) * ((power(x, y / 2) % 1000000007)) %
           1000000007;
  else
    return ((x * (power(x, y / 2) % 1000000007)) % 1000000007) *
           ((power(x, y / 2)) % 1000000007) % 1000000007;
}
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  };
  long long n, m;
  cin >> n >> m;
  long long r[n + 10], c[m + 10], dp[n + 10][m + 10];
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= m + 1; j++) dp[i][j] = -1;
  }
  for (int i = 1; i <= n; i++) {
    cin >> r[i];
    for (int j = 1; j <= r[i]; j++) {
      dp[i][j] = 1;
    }
    dp[i][r[i] + 1] = 0;
  }
  long long ck = 0;
  for (int i = 1; i <= m; i++) {
    cin >> c[i];
    for (int j = 1; j <= c[i]; j++) {
      if (dp[j][i] == 0) {
        cout << 0 << endl;
        return 0;
      }
      dp[j][i] = 1;
    }
    if (dp[c[i] + 1][i] == 1) {
      cout << 0 << endl;
      return 0;
    }
    dp[c[i] + 1][i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (dp[i][j] == -1) {
        ck++;
      }
    }
  }
  cout << power(2, ck) % 1000000007 << endl;
}

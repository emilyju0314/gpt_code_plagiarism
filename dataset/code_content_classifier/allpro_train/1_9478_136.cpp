#include <bits/stdc++.h>
using namespace std;
struct t {
  int x;
  int y;
  int z;
};
int main() {
  string s;
  cin >> s;
  long long n = s.size();
  char c = s[0];
  struct t dp[100005];
  for (long long i = 0; i < 100005; i++) {
    dp[i].x = 0;
    dp[i].y = 0;
    dp[i].z = 0;
  }
  if (c == 'x')
    dp[1].x = 1;
  else if (c == 'y')
    dp[1].y = 1;
  else if (c == 'z')
    dp[1].z = 1;
  for (long long i = 2; i <= n; i++) {
    c = s[i - 1];
    if (c == 'x') {
      dp[i].x = dp[i - 1].x + 1;
      dp[i].y = dp[i - 1].y;
      dp[i].z = dp[i - 1].z;
    } else if (c == 'y') {
      dp[i].y = dp[i - 1].y + 1;
      dp[i].x = dp[i - 1].x;
      dp[i].z = dp[i - 1].z;
    } else if (c == 'z') {
      dp[i].z = dp[i - 1].z + 1;
      dp[i].y = dp[i - 1].y;
      dp[i].x = dp[i - 1].x;
    }
  }
  long long m;
  cin >> m;
  while (m--) {
    long long l, r;
    cin >> l >> r;
    long long x2, y2, z2;
    x2 = (dp[r].x - dp[l - 1].x);
    y2 = (dp[r].y - dp[l - 1].y);
    z2 = (dp[r].z - dp[l - 1].z);
    long long k = max(abs(x2 - y2), max(abs(x2 - z2), abs(y2 - z2)));
    if (k > 1 && r - l >= 2)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}

#include <bits/stdc++.h>
using namespace std;
int n, d;
int islands[30001];
int dp[30001][250 * 2];
int visit(int p, int l) {
  if (p >= 30001) return 0;
  if (dp[p][l - d + 250] != -1) return dp[p][l - d + 250];
  int ret = max(visit(p + l, l), visit(p + l + 1, l + 1));
  if (l >= 2) ret = max(ret, visit(p + l - 1, l - 1));
  return dp[p][l - d + 250] = ret + islands[p];
}
int main() {
  int temp;
  while (cin >> n >> d) {
    memset(islands, 0, sizeof(islands));
    memset(dp, -1, sizeof(dp));
    for (int i = int(0); i < int(n); i++) {
      cin >> temp;
      islands[temp]++;
    }
    cout << visit(d, d) << endl;
  }
  return 0;
}

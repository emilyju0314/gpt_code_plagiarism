#include <bits/stdc++.h>
using namespace std;
string commands;
int dp[101][51][2][2];
bool visited[101][51][2][2];
int rec(int p, int n, int d, bool wantMin) {
  if (visited[p][n][d][wantMin]) return dp[p][n][d][wantMin];
  int &res = dp[p][n][d][wantMin];
  res = (wantMin ? 1000000009 : -1000000009);
  if (p == commands.size()) {
    if (n % 2 == 0) res = 0;
  } else {
    for (int doChange = 0; doChange < 2; ++doChange) {
      if ((doChange == 0) || (n > 0)) {
        int nn = n;
        int dd = d;
        char dir = commands[p];
        if (doChange) {
          dir = (dir == 'T' ? 'F' : 'T');
          nn--;
        }
        int x = 0;
        if (dir == 'T')
          dd = !d;
        else {
          if (d == 0)
            x++;
          else
            x--;
        }
        if (wantMin)
          res = min(res, x + rec(p + 1, nn, dd, wantMin));
        else
          res = max(res, x + rec(p + 1, nn, dd, wantMin));
      }
    }
  }
  visited[p][n][d][wantMin] = true;
  return res;
}
int main() {
  cin >> commands;
  int k;
  cin >> k;
  memset(visited, 0, sizeof(visited));
  int minn = abs(-rec(0, k, 0, true));
  int maxx = abs(-rec(0, k, 0, false));
  cout << max(minn, maxx);
  return 0;
}

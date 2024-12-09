#include <bits/stdc++.h>
using namespace std;
const int MAXV = 1001;
string a, b;
int dp[MAXV + 1][MAXV + 1];
int res[MAXV + 1][MAXV + 1];
int solve(int l, int r) {
  if (dp[l][r] != -1) {
    return dp[l][r];
  } else if (l == a.length() + 1) {
    dp[l][r] = b.length() - r + 1;
    for (int i = r; i <= b.length(); i++) {
      res[l][i] = 0;
    }
  } else if (r == b.length() + 1) {
    dp[l][r] = a.length() - l + 1;
    for (int i = l; i <= a.length(); i++) {
      res[i][r] = 1;
    }
  } else {
    if (a[l - 1] == b[r - 1]) {
      dp[l][r] = solve(l + 1, r + 1);
      res[l][r] = 3;
    } else {
      dp[l][r] = solve(l + 1, r) + 1;
      res[l][r] = 1;
      if (dp[l][r] > solve(l, r + 1) + 1) {
        dp[l][r] = solve(l, r + 1) + 1;
        res[l][r] = 0;
      } else if (dp[l][r] > solve(l + 1, r + 1) + 1) {
        dp[l][r] = solve(l + 1, r + 1) + 1;
        res[l][r] = 2;
      }
    }
  }
  return dp[l][r];
}
void print_sol(int l, int r, int op, int idx) {
  int nl = l + 1;
  int nr = r + 1;
  if (op == 0) {
    cout << "INSERT " << l + idx << " " << b[r - 1] << endl;
    idx += 1;
    nl = l;
  } else if (op == 1) {
    cout << "DELETE " << l + idx << endl;
    nr = r;
    idx -= 1;
  } else if (op == 2) {
    cout << "REPLACE " << l + idx << " " << b[r - 1] << endl;
  }
  if (nl <= a.length() + 1 && nr <= b.length() + 1) {
    print_sol(nl, nr, res[nl][nr], idx);
  }
}
int main() {
  cin >> a;
  cin >> b;
  int l = a.length();
  int r = b.length();
  for (int i = 0; i <= max(l, r) + 1; i++) {
    for (int j = 0; j <= max(l, r) + 1; j++) {
      dp[i][j] = -1;
      res[i][j] = 3;
    }
  }
  int ans = solve(1, 1);
  cout << ans << endl;
  print_sol(1, 1, res[1][1], 0);
}

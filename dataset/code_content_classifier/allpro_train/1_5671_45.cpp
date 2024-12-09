#include <bits/stdc++.h>
using namespace std;
pair<double, pair<double, double> > mem[101][101][101];
int done[101][101][101];
vector<double> dp(int a, int b, int c) {
  vector<double> ret(3);
  pair<double, pair<double, double> > ans;
  if (a < 0 || b < 0 || c < 0) return ret;
  if (done[a][b][c]) {
    ans = mem[a][b][c];
    ret[0] = ans.first;
    ret[1] = ans.second.first;
    ret[2] = ans.second.second;
    return ret;
  }
  if (b + c == 0) {
    ret[0] = 1;
    ret[1] = 0;
    ret[2] = 0;
    return ret;
  }
  if (a + c == 0) {
    ret[0] = 0;
    ret[1] = 1;
    ret[2] = 0;
    return ret;
  }
  if (a + b == 0) {
    ret[0] = ret[1] = 0;
    ret[2] = 1;
    return ret;
  }
  vector<double> ge = dp(a - 1, b, c);
  ret[0] += ((ge[0] * a * c) / (a * c + b * c + a * b));
  ret[1] += ((ge[1] * a * c) / (a * c + b * c + a * b));
  ret[2] += ((ge[2] * a * c) / (a * c + b * c + a * b));
  ge = dp(a, b - 1, c);
  ret[0] += ((ge[0] * a * b) / (a * c + b * c + a * b));
  ret[1] += ((ge[1] * a * b) / (a * c + b * c + a * b));
  ret[2] += ((ge[2] * a * b) / (a * c + b * c + a * b));
  ge = dp(a, b, c - 1);
  ret[0] += ((ge[0] * b * c) / (a * c + b * c + a * b));
  ret[1] += ((ge[1] * b * c) / (a * c + b * c + a * b));
  ret[2] += ((ge[2] * b * c) / (a * c + b * c + a * b));
  mem[a][b][c].first = ret[0];
  mem[a][b][c].second.first = ret[1];
  mem[a][b][c].second.second = ret[2];
  done[a][b][c] = 1;
  return ret;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  int i, j, k, l;
  cin >> i >> j >> k;
  std::vector<double> ans;
  ans = dp(i, j, k);
  printf("%.9lf %.9lf %.9lf\n", ans[0], ans[1], ans[2]);
  return 0;
}

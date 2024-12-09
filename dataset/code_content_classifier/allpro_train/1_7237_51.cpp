#include <bits/stdc++.h>
using namespace std;
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int &x, int y, int mod = 1000000007) {
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et() {
  puts("-1");
  exit(0);
}
long long t[3][300105];
int pre[3][300105];
map<pair<int, int>, int> mp;
int cal(int x, int y) {
  int mi = min(x, y);
  if (pre[0][x] <= 0 && pre[1][y] <= 0 && pre[2][mi] <= 0) return 0;
  if (mp.find({x, y}) != mp.end()) return mp[{x, y}];
  int ans = 0;
  if (pre[2][mi] > 0) {
    ans = max(ans, cal(pre[2][mi] - 1, pre[2][mi] - 1) + 1);
  }
  if (pre[0][x] > 0 || pre[1][y] > 0) {
    if (pre[0][x] > pre[1][y]) {
      ans = max(ans, cal(pre[0][x] - 1, y) + 1);
    } else
      ans = max(ans, cal(x, pre[1][y] - 1) + 1);
  }
  return mp[{x, y}] = ans;
}
void fmain(int tid) {
  scanf("%d", &n);
  for (int(i) = 0; (i) < (int)(2); (i)++)
    for (int(j) = 1; (j) <= (int)(n); (j)++) scanf("%lld", &t[i][j]);
  for (int(j) = 1; (j) <= (int)(n); (j)++) {
    t[2][j] = t[0][j] + t[1][j];
  }
  for (int(i) = 0; (i) < (int)(3); (i)++)
    for (int(j) = 1; (j) <= (int)(n); (j)++) t[i][j] += t[i][j - 1];
  for (int(i) = 0; (i) < (int)(3); (i)++) {
    map<long long, int> mp;
    mp[0] = 0;
    for (int(j) = 1; (j) <= (int)(n); (j)++) {
      pre[i][j] = pre[i][j - 1];
      if (mp.find(t[i][j]) != mp.end()) {
        pre[i][j] = max(pre[i][j], mp[t[i][j]] + 1);
      }
      mp[t[i][j]] = j;
    }
  }
  printf("%d\n", cal(n, n));
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}

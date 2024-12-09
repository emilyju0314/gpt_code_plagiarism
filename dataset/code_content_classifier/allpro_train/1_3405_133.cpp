#include <bits/stdc++.h>
using namespace std;
long cx, cy, n, x[2000];
string dir[2000];
set<long> dx, dy;
set<long>::iterator it;
map<long, long> mx, my, rmx, rmy;
long val;
long calcx, calcy;
long nx, ny;
bool forb[(1 << 12) + 100][(1 << 12) + 100];
bool used[(1 << 12) + 100][(1 << 12) + 100];
long long ans;
bool cmove(long a, long b) {
  if (a <= 0 || b <= 0 || a > calcx || b > calcy) return false;
  if (used[a][b]) return false;
  if (forb[a][b]) return false;
  return true;
}
void dfs(long a, long b) {
  used[a][b] = 1;
  if (cmove(a - 1, b)) dfs(a - 1, b);
  if (cmove(a + 1, b)) dfs(a + 1, b);
  if (cmove(a, b - 1)) dfs(a, b - 1);
  if (cmove(a, b + 1)) dfs(a, b + 1);
}
void ap(long x, long y) {
  dx.insert(x);
  dy.insert(y);
  dx.insert(x + 1);
  dy.insert(y + 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cx = cy = 1000000000;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> dir[i] >> x[i];
    ap(cx, cy);
    if (dir[i] == "U") cx -= x[i];
    if (dir[i] == "D") cx += x[i];
    if (dir[i] == "L") cy -= x[i];
    if (dir[i] == "R") cy += x[i];
  }
  ap(cx, cy);
  ap(1, 1);
  for (it = dx.begin(); it != dx.end(); it++) {
    val = (*it);
    ++calcx;
    mx[val] = calcx;
    rmx[calcx] = val;
  }
  for (it = dy.begin(); it != dy.end(); it++) {
    val = (*it);
    ++calcy;
    my[val] = calcy;
    rmy[calcy] = val;
  }
  cx = cy = 1000000000;
  for (int i = 1; i <= n; i++) {
    nx = cx;
    ny = cy;
    if (dir[i] == "U") {
      nx -= x[i];
      for (int j = mx[nx]; j <= mx[cx]; j++) forb[j][my[cy]] = 1;
    }
    if (dir[i] == "D") {
      nx += x[i];
      for (int j = mx[cx]; j <= mx[nx]; j++) forb[j][my[cy]] = 1;
    }
    if (dir[i] == "L") {
      ny -= x[i];
      for (int j = my[ny]; j <= my[cy]; j++) forb[mx[cx]][j] = 1;
    }
    if (dir[i] == "R") {
      ny += x[i];
      for (int j = my[cy]; j <= my[ny]; j++) forb[mx[cx]][j] = 1;
    }
    cx = nx;
    cy = ny;
  }
  dfs(1, 1);
  for (int i = 1; i <= calcx; i++)
    for (int j = 1; j <= calcy; j++) {
      if (used[i][j]) continue;
      ans += (rmx[i + 1] - rmx[i]) * 1ll * (rmy[j + 1] - rmy[j]);
    }
  cout << ans << endl;
  cin.get();
  cin.get();
  return 0;
}

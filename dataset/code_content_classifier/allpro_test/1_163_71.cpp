#include <bits/stdc++.h>
using namespace std;
bool isrange(int second, int first, int n, int m) {
  if (0 <= second && second < n && 0 <= first && first < m) return true;
  return false;
}
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1},
    ddy[8] = {1, 0, -1, 0, 1, 1, -1, -1}, ddx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
const int MAX = 1e5 + 100;
const long long int mod = 1e9 + 7;
long long int calc(long long int now, long long int num) {
  if (num == 0) return 1;
  if (num == 1) return now;
  long long int now2 = calc(now, num / 2);
  if (num % 2 == 0) return (now2 * now2) % mod;
  return (((now2 * now2) % mod) * now) % mod;
}
long long int divs(long long int a, long long int b) {
  return (a * calc(b, mod - 2)) % mod;
}
struct inf {
  int second, first, dy, dx;
  inf(int second, int first, int dy, int dx)
      : second(second), first(first), dy(dy), dx(dx) {}
};
bool operator<(const inf& X, const inf& O) {
  if (X.second != O.second) return X.second < O.second;
  if (X.first != O.first) return X.first < O.first;
  if (X.dy != O.dy) return X.dy < O.dy;
  return X.dx < O.dx;
}
void solve(int tc) {
  int n, m, sy, sx, ey, ex, P;
  cin >> n >> m >> sy >> sx >> ey >> ex >> P;
  int st = 0, dy = 1, dx = 1;
  map<inf, int> mm;
  vector<int> K;
  if (sy == n) dy = -1;
  if (sx == m) dx = -1;
  while (mm[inf(sy, sx, dy, dx)] == 0) {
    if (sy == ey || sx == ex) {
      K.push_back(st);
      mm[inf(sy, sx, dy, dx)] = 1;
    }
    if (sy == n && dy == 1) dy = -1;
    if (sy == 1 && dy == -1) dy = 1;
    if (sx == m && dx == 1) dx = -1;
    if (sx == 1 && dx == -1) dx = 1;
    st++;
    sy += dy;
    sx += dx;
    if (sy == n && dy == 1) dy = -1;
    if (sy == 1 && dy == -1) dy = 1;
    if (sx == m && dx == 1) dx = -1;
    if (sx == 1 && dx == -1) dx = 1;
  }
  long long int v1 = st - K[0];
  long long int v2 = (int)K.size();
  long long int k1 = 1, k2 = 1;
  for (int e = 0; e < v2; e++) {
    k1 = (k1 * (100 - P)) % mod;
    k2 = (k2 * 100) % mod;
  }
  k1 = divs(k1, k2);
  long long int f1 = (v1 * k1) % mod;
  long long int f2 = (1ll - k1 + mod) % mod;
  long long int vvv = divs(P, 100), kk = divs(100 - P, 100);
  for (int e = 0; e < (int)K.size(); e++) {
    long long int nn = (vvv * K[e]) % mod;
    f1 = (f1 + nn) % mod;
    vvv = (vvv * kk) % mod;
  }
  cout << divs(f1, f2) << "\n";
}
int main(void) {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  cin >> tc;
  for (int test_number = 1; test_number <= tc; test_number++) {
    solve(test_number);
  }
  return 0;
}

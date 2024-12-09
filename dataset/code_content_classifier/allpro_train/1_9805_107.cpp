#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector<string> a;
vector<string> b;
vector<vector<long long>> psum;
vector<vector<bool>> mark;
long long dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
long long dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
long long cal(long long x1, long long y1, long long x2, long long y2) {
  return psum[x2][y2] - psum[x1 - 1][y2] - psum[x2][y1 - 1] +
         psum[x1 - 1][y1 - 1];
}
bool check(long long x) {
  queue<pair<long long, pair<long long, long long>>> CurrList;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) {
      mark[i][j] = false;
      if (i >= x * 2 + 1 && j >= x * 2 + 1)
        if (cal(i - x * 2, j - x * 2, i, j) == (x * 2 + 1) * (x * 2 + 1)) {
          mark[i - x][j - x] = true;
          CurrList.push(pair<long long, pair<long long, long long>>(
              x, pair<long long, long long>(i - x, j - x)));
        }
    }
  while (!CurrList.empty()) {
    long long rem = CurrList.front().first;
    long long x = CurrList.front().second.first;
    long long y = CurrList.front().second.second;
    CurrList.pop();
    if (!rem) continue;
    for (long long i = 0; i < 8; i++) {
      long long xx = x + dx[i];
      long long yy = y + dy[i];
      if (1 <= xx && xx <= n && 1 <= yy && yy <= m && !mark[xx][yy]) {
        if (a[xx][yy] == '.') return false;
        mark[xx][yy] = true;
        CurrList.push(pair<long long, pair<long long, long long>>(
            rem - 1, pair<long long, long long>(xx, yy)));
      }
    }
  }
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++)
      if (a[i][j] == 'X' && !mark[i][j]) return false;
  return true;
}
void trace(long long x) {
  queue<pair<long long, pair<long long, long long>>> CurrList;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) {
      b[i][j] = '.';
      mark[i][j] = false;
      if (i >= x * 2 + 1 && j >= x * 2 + 1)
        if (cal(i - x * 2, j - x * 2, i, j) == (x * 2 + 1) * (x * 2 + 1)) {
          mark[i - x][j - x] = true;
          CurrList.push(pair<long long, pair<long long, long long>>(
              x, pair<long long, long long>(i - x, j - x)));
          b[i - x][j - x] = 'X';
        }
    }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) cout << b[i][j];
    cout << '\n';
  }
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  a.resize(n + 1);
  b.resize(n + 1);
  psum.resize(n + 1);
  mark.resize(n + 1);
  psum[0].resize(m + 1);
  for (long long j = 0; j <= m; j++) psum[0][j] = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = '*' + a[i];
    psum[i].resize(m + 1);
    b[i].resize(m + 1);
    psum[i][0] = 0;
    mark[i].resize(m + 1);
    for (long long j = 1; j <= m; j++) {
      mark[i][j] = false;
      long long tmp = 0;
      if (a[i][j] == 'X') tmp++;
      psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + tmp;
    }
  }
  long long l = 1, r = 1000000;
  long long ans = 0;
  while (l <= r) {
    long long mi = (l + r) / 2;
    if (check(mi)) {
      ans = mi;
      l = mi + 1;
    } else
      r = mi - 1;
  }
  cout << ans << '\n';
  trace(ans);
}

#include <bits/stdc++.h>
using namespace std;
int ROW[] = {+1, -1, +0, +0};
int COL[] = {+0, +0, +1, -1};
int X[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int Y[] = {-1, +1, +0, +0, +1, +1, -1, -1};
int KX[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int KY[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int GCD(int a, int b) { return b == 0 ? a : GCD(b, a % b); }
int LCM(int a, int b) { return a * (b / GCD(a, b)); }
bool CMP(int a, int b) { return a > b; }
int a[] = {1,      10,      100,      1000,      10000,
           100000, 1000000, 10000000, 100000000, 1000000000};
int firstDigit(int n) {
  int x = 1;
  while (n >= 10) {
    n /= 10;
    x *= 10;
  }
  return n;
}
int po(int n) {
  int x = 1;
  while (n >= 10) {
    n /= 10;
    x *= 10;
  }
  return n * x;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, mn = int(1e9 + 9), x = 0, y = 0;
    cin >> n;
    string s;
    cin >> s;
    pair<int, int> now = {0, 0}, ans;
    map<pair<int, int>, int> m;
    m[now] = 0;
    for (int i = 1; i <= n; i++) {
      if (s[i - 1] == 'L')
        x--;
      else if (s[i - 1] == 'R')
        x++;
      else if (s[i - 1] == 'U')
        y++;
      else if (s[i - 1] == 'D')
        y--;
      now = {x, y};
      if (m.count(now)) {
        int dis = i - m[now] - 1;
        if (dis < mn) {
          mn = dis;
          ans = {m[now] + 1, i};
        }
      }
      m[now] = i;
    }
    if (mn == int(1e9 + 9))
      cout << "-1" << endl;
    else
      cout << ans.first << " " << ans.second << endl;
  }
  return 0;
}

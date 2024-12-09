#include <bits/stdc++.h>
using namespace std;
struct P {
  long long int x0, y0, x1, y1;
};
int main() {
  vector<P> point;
  long long int n, m, k;
  cin >> n >> m >> k;
  vector<string> mp(n);
  vector<long long int> vx, vy;
  for (long long int i = 0; i < ((long long int)n); i++) cin >> mp[i];
  for (long long int i = 0; i < ((long long int)n); i++)
    for (long long int j = 0; j < ((long long int)m); j++)
      if (mp[i][j] == '*') {
        long long int x1 = i, y1 = j;
        while (x1 < n && mp[x1][j] == '*') x1++;
        while (y1 < m && mp[i][y1] == '*') y1++;
        point.push_back((P){i, j, x1 - 1, y1 - 1});
        for (long long int k = i; k < x1; k++)
          for (long long int l = j; l < y1; l++) mp[k][l] = '.';
        vx.push_back(i);
        vx.push_back(x1 - 1);
      }
  sort(vx.begin(), vx.end());
  vx.erase(unique(vx.begin(), vx.end()), vx.end());
  long long int res = 0;
  for (long long int num = 1; num <= 3; num++) {
    for (long long int right = 0; right < ((long long int)vx.size()); right++)
      for (long long int left = 0; left <= right; left++) {
        vector<pair<pair<long long int, long long int>, long long int> > vy;
        for (long long int i = 0;
             i < ((long long int)((long long int)point.size())); i++)
          if (vx[left] <= point[i].x1 && point[i].x0 <= vx[right]) {
            long long int p =
                (point[i].x0 < vx[left] || vx[right] < point[i].x1) ? 1000 : 1;
            vy.push_back(make_pair(make_pair(point[i].y0, p), point[i].x0));
            vy.push_back(make_pair(make_pair(point[i].y1, 0), point[i].x1));
          }
        sort(vy.begin(), vy.end());
        long long int sum = 0, ok = 0, l = 0, r = 0;
        bool flag = true;
        while (flag) {
          if (sum == 0) {
            if (ok == num) {
              long long int top =
                  vy[l].first.first - ((l == 0) ? -1 : vy[l - 1].first.first);
              long long int bottom =
                  ((r == ((long long int)vy.size())) ? m : vy[r].first.first) -
                  vy[r - 1].first.first;
              long long int left_space =
                  vx[left] - ((left == 0) ? -1 : vx[left - 1]);
              long long int right_space =
                  ((right + 1 == ((long long int)vx.size())) ? n
                                                             : vx[right + 1]) -
                  vx[right];
              res += top * bottom * right_space * left_space;
            }
          }
          if (ok < num) {
            if (r == ((long long int)vy.size())) {
              flag = false;
              break;
            }
            do {
              if (vy[r].first.second == 0)
                sum--;
              else
                sum++;
              ok += vy[r++].first.second;
            } while (r != ((long long int)vy.size()) &&
                     (vy[r].first.first == vy[r - 1].first.first || sum != 0));
          } else {
            do {
              if (vy[l].first.second == 0)
                sum++;
              else
                sum--;
              ok -= vy[l++].first.second;
            } while (l != ((long long int)vy.size()) &&
                     (vy[l].first.first == vy[l - 1].first.first || sum != 0));
          }
        }
      }
  }
  cout << res << endl;
}

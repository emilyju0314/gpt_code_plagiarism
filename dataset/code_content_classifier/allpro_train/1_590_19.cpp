#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <queue>
#include <cassert>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const int INF = 1<<29;

int main() {
  int p,s;
  int ffff = 0;
  while(cin>>p,p) {
    cin >> s;
    if (ffff) cout << endl;
    else ffff = 1;
    int a[s+1][p+1];
    vector<int> vx;
    vector<int> vy;
    REP(i,p+1) {
      REP(j,s+1) {
        string str;
        cin >> str;
        if (str == "?") {
          a[j][i] = INF;
          vx.push_back(j);
          vy.push_back(i);
        } else a[j][i] = atoi(str.c_str());
      }
    }

    bool update = 1;
    while(update) {
      update = 0;
      REP(x, s) {
        int cnt = 0;
        int xx, yy;
        int sum = 0;
        REP(y, p) {
          if (a[x][y] == INF) {
            cnt++;
            xx = x; yy = y;
          } else
            sum += a[x][y];
        }
        if (cnt == 1) {
          //cout << xx << " " << yy << " " << sum << endl;
          a[xx][yy] = a[x][p] - sum;
          update = 1;
        }
      }
      REP(y, p) {
        int cnt = 0;
        int xx, yy;
        int sum = 0;
        REP(x, s) {
          if (a[x][y] == INF) {
            cnt++;
            xx = x; yy = y;
          } else
            sum += a[x][y];
        }
        //    cout << sum << endl;
        if (cnt == 1) {
          //cout << xx << " " << yy << endl;
          a[xx][yy] = a[s][y] - sum;
          update = 1;
        }
      }
    }
    vector<int> res;
    REP(i,vx.size()) {
      if (a[vx[i]][vy[i]] != INF) {
        res.push_back(a[vx[i]][vy[i]]);
      }
    }
    if (res.size() != vx.size())
      cout << "NO" << endl;
    else
      FOR(it,res)
        cout << *it << endl;
  }
}
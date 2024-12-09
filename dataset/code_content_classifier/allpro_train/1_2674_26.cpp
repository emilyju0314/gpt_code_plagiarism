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
#include <set>
#include <map>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const int INF = 1<<29;

int ba[8][8];
int dx[] ={0,1,0,-1};
int dy[] ={-1,0,1,0};
typedef pair<int,int> pii;
vector<pair<int, pii> > v;
int n;

bool solve(int);

bool visited[8][8];
int cnt = 0;
bool rec(int x, int y, int sum, int k) {
//  printf("x=%d,y=%d, sum=%d, k=%d\n",x,y,sum,k);
  REP(i,4) {
    int xx = x+dx[i];
    int yy = y+dy[i];
    if (xx<0||xx>=n||yy<0||yy>=n) continue;
    if (visited[xx][yy] || ba[xx][yy] < 0) continue;

    if (sum + ba[xx][yy] > v[k].first) continue;
    visited[xx][yy] = 1;
    cnt++;
    if (sum + ba[xx][yy] == v[k].first) {
      //        printf("OK %d,%d\n", xx,yy);
      if(solve(k+1))
        return 1;
    } else  if (rec(xx,yy,sum+ba[xx][yy],k))
      return 1;
    visited[xx][yy] = 0;
    cnt--;
  }
  return 0;
}

bool solve(int k) {
//  cout << "k="<<k <<  endl;
  if (k==v.size()) {
    if (cnt == n*n-v.size()) return 1;
    else return 0;
  }
  pii p = v[k].second;
  int x = p.first, y = p.second;
//  cout << x << " " << y << endl;
  if (rec(x,y,0,k))
    return 1;
  return 0;
}

int main() {
  while(cin >> n,n) {
    v.clear();
    REP(y,n) {
      REP(x,n) {
        cin >> ba[x][y];
        if (ba[x][y] < 0) {
          v.push_back(make_pair(-ba[x][y], pii(x,y)));
        }
      }
    }
    sort(ALL(v));
    // FOR(it, v) {
    //   pii p = it->second;
    //   cout << it->first << " " << p.first << ", " << p.second << endl;
    // }
    memset(visited,0,sizeof(visited));
    cnt = 0;
    if (solve(0))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    
  }
}
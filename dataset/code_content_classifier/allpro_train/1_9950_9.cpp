#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <cassert>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;
const int M = 100000007;

int combi[500][500];

ll func(vector<int> v) {
  ll res = 1;
  int now = v[0];
  for (int i=1; i<v.size(); ++i) {
    res = (res * combi[v[i]+now][v[i]]) % M;
    now += v[i];
  }
  return res;
}

int main() {
  REP(i,500) combi[i][0] = 1;
  REP(i,500-1) REP(j,500-1) combi[i+1][j+1] = (combi[i][j+1]+combi[i][j]) % M;
  int n;
  while(cin>>n,n) {
    double p[n],q[n];
    int a[n], b[n];    
    REP(i,n) {
      cin>>p[i]>>a[i]>>q[i];
      b[a[i]] = i;
    }
    bool visited[n];
    memset(visited,0,sizeof(visited));
    vector<vector<int> > cycle;
    REP(i, n) {
      if (visited[i]) continue;
      int now = i;
      vector<int> tmp;
      do {
        tmp.push_back(now);
        visited[now] = 1;
        now = b[now];
      } while(now!=i);
      cycle.push_back(tmp);
    }
    double ans = 0;
    ll sub = 1;
    REP(i, cycle.size()) {
      int start;
      double mi = INF;
      int tmp = 0;
      REP(j, cycle[i].size()) {
        //cout << mi << " " << q[cycle[i][j]] - p[cycle[i][j]] << endl;
        int cc = cycle[i][j];
        if (abs(mi - (1/p[cc] - 1/q[cc])) < EPS) {
          tmp++;
        } else if (mi > 1/p[cc] - 1/q[cc]) {
          mi = 1/p[cc] - 1/q[cc];
          start = j;
          tmp = 1;
        }
      }
      sub = (sub*tmp)%M;
      //cout << "start = " << start << endl;
      REP(j, cycle[i].size()) {
        //cout << cycle[i][j] << " ";
        if (start == j) {
          ans += 1.0/p[cycle[i][j]];
        } else {
          ans += 1.0/q[cycle[i][j]];
        }
      }
    }
    vector<int> v;
    REP(i, cycle.size()) {
      v.push_back(cycle[i].size());
    }
    printf("%.12f %lld\n", ans, (sub*func(v)) % M);
    //cout << ans << " " << (sub*func(v)) % M << endl;
  }
}
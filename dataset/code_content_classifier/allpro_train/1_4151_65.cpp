#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
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
typedef pair<int,int> pii;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

int damage[26];
int step[1010];
char ba[100][100];

int dp[2][1<<12];                   // dp[i][j] = 集合jのポーションを使ったときの体力の最大

int main() {
  int HPini, HPmax;
  while(cin>>HPini>>HPmax,HPini||HPmax) {
    int r,c;
    cin >> r >> c;
    REP(i,r) REP(j,c) cin>>ba[i][j];
    int t;cin >> t;
    REP(i,t) {
      char c; int m;
      cin >> c >> m;
      damage[c-'A'] = m;
    }
    int s; cin >> s;
    int num = 1;
    step[0] = damage[ba[0][0]-'A'];
    int y=0, x=0;
    const int dx[] = {0,1,0,-1};
    const int dy[] = {-1,0,1,0};
    REP(i,s) {
      char c; int m;
      cin >> c >> m;
      int d = 0;
      if (c=='D') d=2;
      else if (c=='L') d=3;
      else if (c=='R') d=1;
      REP(i,m) {
        y += dy[d];
        x += dx[d];
        step[num++] = damage[ba[y][x]-'A'];
      }
    }
    int P; cin >> P;
    int p[P];
    REP(i,P) cin >> p[i];

    memset(dp,0,sizeof(dp));
    dp[0][0] = HPini;
    REP(i,num) {
      //cout << step[i] << endl;
      REP(S,1<<P) dp[(i+1)%2][S] = 0;
      REP(S,1<<P) {
        if (dp[i%2][S] == 0) continue; // 死んでる
        // ポーションを使わない
        dp[(i+1)%2][S] = max(dp[(i+1)%2][S], dp[i%2][S]-step[i]);
        // ポーションを使う
        REP(j,P) {
          if (S>>j&1) continue;
          dp[(i+1)%2][S|1<<j] = max(dp[(i+1)%2][S|1<<j], min(HPmax, dp[i%2][S]+p[j])-step[i]);
        }
      }
    }
    bool ans = 0;
    REP(S,1<<P)
      if (dp[num%2][S] > 0) {
        ans = 1;
        //cout << bitset<5>(S) << endl;
      }
    cout << (ans?"YES":"NO") << endl;
  }
}
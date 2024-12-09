#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
void update(int& n, int m){
  n = max(n, m);
}

int main(){
  int C, N, M, X;
  while(cin>>C>>N>>M>>X && C){
    int c_s[101] = {}, e_s[101] = {};
    int c[101] = {}, e[101] = {};
    char tmp[256];
    REP(i, N){
      scanf("%s %d %d", tmp, &c_s[i], &e_s[i]);
    }
    REP(i, M){
      scanf("%s %d %d", tmp, &c[i], &e[i]);
    }
    int dp[2][101][1001] = {}; // i use money
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    for(int i = 0; i < M; i++){
      for(int use = 0; use <= i; use++){
        for(int cost = 0; cost <= C; cost++){
          if(cost + c[i] <= C && dp[i % 2][use][cost] != -1) update(dp[(i + 1) % 2][use + 1][cost + c[i]], dp[i % 2][use][cost] + e[i]);
          update(dp[(i + 1) % 2][use][cost], dp[i % 2][use][cost]);
        }
      }
    }
    for(int use = 1; use <= M; use++){
      for(int cost = 1; cost <= C; cost++){
        update(dp[M%2][use][cost], dp[M%2][use][cost - 1]);
      }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
      for(int j = i + 1; j <= N; j++){
        int rest = C - (c_s[i] + c_s[j]);
        if(rest <= 0) continue;
        int effect_c = e_s[i] + e_s[j];
        int effect = 0;
        for(int use = X; use <= M; use++){
          update(effect, dp[M%2][use][rest]);
        }
        ans = max(ans, effect_c + effect);
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
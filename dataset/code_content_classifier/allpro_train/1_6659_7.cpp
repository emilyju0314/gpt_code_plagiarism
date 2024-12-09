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

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int popcount(int N){
  return __builtin_popcount(N);
}

int main(){
  int N, M;
  while(cin >> N >> M && N){
    vector<int> L(N);
    REP(i, N) cin >> L[i];
    static int dp[1000][1 << 12] = {};
    memset(dp, -1, sizeof(dp));
    for(int S = 0; S < 1 << M; S++){
      if(popcount(S) == L[0]) dp[0][S] = 0;
    }
    int mask = (1 << M) - 1;
    for(int i = 1; i < N; i++){
      for(int S = 0; S < 1 << M; S++){
        if(dp[i - 1][S] != -1){
          int NS = S << 1 & mask;
          if(popcount(NS) == L[i]) dp[i][NS] = S;
          NS |= 1;
          if(popcount(NS) == L[i]) dp[i][NS] = S;
        }
      }
    }
    int CRS = -1;
    for(int S = 0; S < 1 << M; S++) if(dp[N - 1][S] != -1) CRS = S;
    if(CRS == -1){
      cout << "Goofy" << endl;
      continue;
    }
    vector<int> ans;
    for(int i = N - 1; i >= 0; i--){
      ans.push_back(CRS & 1);
      if(i != 0) CRS = dp[i][CRS];
    }
    for(int i = 1; i < M; i++) ans.push_back(CRS >> i & 1);
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) cout << ans[i];
    cout << endl;
  }
  return 0;
}
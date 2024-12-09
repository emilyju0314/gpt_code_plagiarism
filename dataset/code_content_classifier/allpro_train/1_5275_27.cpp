#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define rep(i,j) REP((i), 0, (j))
#define REP(i,j,k) for(int i=(j);(i)<(k);++i)
#define between(a,x,b) ((a)<=(x)&&(x)<=(b))
#define F first
#define S second
#define INF 1 << 30

typedef pair<int, pair<int,int> > pii;

int main(){
  int N, M, t, s, d;
  while(scanf("%d%d", &N, &M) && N+M){
    vector<pii>v(M);
    rep(i, M){
      scanf("%d%d%d", &t, &s, &d);
      s--; d--;
      v[i] = make_pair(t, make_pair(s, d));
    }

    sort(v.begin(), v.end());
    vector<bool>f(N, 0);
    f[0] = 1;
    rep(i, M){
      int a = v[i].S.F; int b = v[i].S.S;
      if(f[a]) f[b] = 1;
    }
    int res = 0;
    rep(i, N) if(f[i]) res++;
    //    printf("%d %d %d\n", (int)f[0], (int)f[1], (int)f[2]);
    printf("%d\n", res);
  }
  return 0;
}
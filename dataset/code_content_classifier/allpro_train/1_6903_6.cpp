#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
const ll MOD = 998244353ll;

int n,m;
int a[52525], b[52525], c[52525];
unordered_map<int,int> M[125252];
int dp[252521];

ll modpow(ll a, ll b){
  ll r = 1;
  while(b){
    if(b&1)r=r*a%MOD;
    a=a*a%MOD;
    b>>=1;
  }
  return r;
}

bool ppcnt[16];

int main(){
  scanf("%d%d",&n,&m);
  REP(i,m)scanf("%d%d%d",a+i,b+i,c+i),a[i]--,b[i]--;
  REP(i,16)ppcnt[i] = __builtin_popcount(i)%2==0;
  REP(i,m)M[a[i]][b[i]] = c[i];
  REP(j,16){
    if(!ppcnt[j])continue;
    bool ok = true;
    REP(i,4)if(M[i>>1].count(i&1) && M[i>>1][i&1] != (j>>i&1)){
      ok = false;
    }
    if(ok)dp[j>>3&1] += 1;
  }
  REP(i,n-2)REP(r2,2)if(dp[i*2+r2]){
    int ci = i+1;
    REP(ld,2){
      int ru = r2 ^ ld;
      if(M[ci-1].count(ci+1) && M[ci-1][ci+1] != ld)continue;
      if(M[ci+1].count(ci-1) && M[ci+1][ci-1] != ru)continue;
      REP(to,8){
        int nj = to*2+r2;
        if(!ppcnt[nj])continue;
        if(M[ci+1].count(ci+0) && M[ci+1][ci+0] != (nj>>1&1))continue;
        if(M[ci+0].count(ci+1) && M[ci+0][ci+1] != (nj>>2&1))continue;
        if(M[ci+1].count(ci+1) && M[ci+1][ci+1] != (nj>>3&1))continue;
        (dp[(i+1)*2+(nj>>3)] += dp[i*2+r2]) %= MOD;
      }
    }
  }
  ll base = (dp[(n-2)*2] + dp[(n-2)*2+1]) % MOD;
  ll fr = n<=3 ? 0ll : ((ll)n*n - 7ll*2 - 5ll*(n-4))/2;
  REP(i,m){
    int x = a[i], y = b[i], z = c[i];
    if(abs(x-y)<=2)continue;
    if(M[y].count(x)){
      if(M[y][x] != z){
        base = 0;
      }else if(x<y){
        fr--;
      }
    }else{
      fr--;
    }
  }
  ll ans = base * modpow(2ll, fr) % MOD;
  printf("%lld\n",ans);
  return 0;
}

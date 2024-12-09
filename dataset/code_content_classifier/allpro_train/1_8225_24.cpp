#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int,int> pii;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define FORR(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)

#define MOD 1000000007

int n;
char s[2521];
ll dp[2521][2521];

set<int> cs[26];

int main(){
  scanf("%s",s);
  n = strlen(s);
  REP(i,n)cs[s[i]-'a'].insert(i);

  dp[0][n] = 1;
  ll ans = 0;
  FORR(len,0,n+1)REP(l,n){
    int r = l+len;
    if(r>n)break;
    ll cnt = dp[l][r];
    if(cnt==0)continue;
    // step
    REP(i,26){
      auto it1 = cs[i].lower_bound(l);
      auto it2 = cs[i].lower_bound(r);
      if(it1==cs[i].end())continue;
      if(it2==cs[i].begin())continue;
      it2--;
      int x = *it1;
      int y = *it2;
      if(x>=y)continue;
      if(x>=r)continue;
      if(y<l)continue;
      ans += cnt;
      ans %= MOD;
      (dp[x+1][y] += cnt) %= MOD;
      // printf("%c(%d-%d)%c: %lld\n",'a'+i,x+1,y-1,'a'+i,cnt);
    }
    // finish
    REP(i,26){
      auto it = cs[i].lower_bound(l);
      if(it==cs[i].end())continue;
      int x = *it;
      if(x<r){
        // printf("%c single\n",'a'+i);
        ans += cnt;
        ans %= MOD;
      }
    }
  }
  printf("%lld\n",ans);
  return 0;
}


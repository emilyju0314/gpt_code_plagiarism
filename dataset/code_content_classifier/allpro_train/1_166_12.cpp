#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

// mod
const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

// floating
typedef double Real;
const Real EPS = 1e-11;
#define EQ0(x) (abs(x)<EPS)
#define EQ(a,b) (abs(a-b)<EPS)
typedef complex<Real> P;

ll n,q,k,d;
ll low[1252525], high[1252525];

int main(){
  scanf("%lld%lld%lld%lld",&n,&q,&k,&d);
  --k;--d;
  low[0] = high[0] = d;
  REP(i,q){
    low[i+1] = n; high[i+1] = -1;
    {
      ll x = low[i];
      if(x>=n/2)x-=n/2;
      CHMIN(low[i+1], 2*x);
      CHMAX(high[i+1], 2*x+1);
    }
    {
      ll x = high[i];
      if(x>=n/2)x-=n/2;
      CHMIN(low[i+1], 2*x);
      CHMAX(high[i+1], 2*x+1);
    }
    if(low[i]<=n/2-1 && n/2-1<=high[i]){
      ll x = n/2-1;
      if(x>=n/2)x-=n/2;
      CHMIN(low[i+1], 2*x);
      CHMAX(high[i+1], 2*x+1);
    }
    if(low[i]<=n/2 && n/2<=high[i]){
      ll x = n/2;
      if(x>=n/2)x-=n/2;
      CHMIN(low[i+1], 2*x);
      CHMAX(high[i+1], 2*x+1);
    }
  }
  if(k<low[q] || k>high[q]){
    puts("-1");return 0;
  }
  ll x = k;
  FORR(i,0,q){
    if(low[i]<=x/2 && x/2<=high[i]){
      puts(x%2==0 ? "0" : "1");
      x = x/2;
    }else{
      puts(x%2==0 ? "1" : "0");
      x = x/2 + n/2;
    }
  }
  assert(x == d);
  return 0;
}


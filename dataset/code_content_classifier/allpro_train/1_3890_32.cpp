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

int n,a,d;
int m;
int x[252521],y[252521],z[252521];
int k;

int main(){
  scanf("%d%d%d%d",&n,&a,&d,&m);
  REP(i,m)scanf("%d%d%d",x+i,y+i,z+i),--y[i],--z[i];
  scanf("%d",&k),--k;
  FORR(i,0,m){
    if(x[i]!=0)continue;
    int l = y[i], r = z[i];
    if(!(l<=k && k<=r))continue;
    k -= l; r -= l;
    k = r-k;
    k += l;
  }
  int val = a + d*k;
  REP(i,m){
    if(x[i]==0){
      int l = y[i], r = z[i];
      if(!(l<=k && k<=r))continue;
      k -= l; r -= l;
      k = r-k;
      k += l;
    }else if(x[i]==1){
      if(y[i]<=k && k<=z[i])val++;
    }else{
      if(y[i]<=k && k<=z[i])val/=2;
    }
  }
  printf("%d\n",val);
  return 0;
}
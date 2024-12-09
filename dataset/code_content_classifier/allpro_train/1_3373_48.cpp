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

int n;
char buf[425252];

const int LIM = 4;

vector<bool> chk[LIM];

int enc(char *s, int len){
  int ret = 0;
  REP(i,len){
    ret *= 26;
    ret += s[i]-'a';
  }
  return ret;
}
string dec(int x,int len){
  string ret = "";
  REP(i,len){
    ret = string(1,(char)(x%26)+'a') + ret;
    x/=26;
  }
  return ret;
}

int main(){
  {
    int k = 26;
    REP(i,LIM){
      chk[i].assign(k,false);
      k *= 26;
    }
  }
  int n;
  scanf("%d",&n);
  REP(i,n){
    scanf("%s",buf);
    int len = strlen(buf);
    REP(j,len){
      REP(k,LIM){
        if(j+k<len){
          int v = enc(buf+j,k+1);
          chk[k][v] = true;
        }
      }
    }
  }
  string ans = "";
  REP(k,LIM){
    bool ok = false;
    REP(i,chk[k].size())if(!chk[k][i]){
      ans = dec(i,k+1);
      ok = true;
      break;
    }
    if(ok)break;
  }
  assert(ans != "");
  cout<<ans<<endl;
  return 0;
}
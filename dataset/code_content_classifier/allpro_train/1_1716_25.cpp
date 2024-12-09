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
char s[2521];
const int MIN = 830;
const int MAX = 252;
vi a;
pii dfs(vi &a,int &p){
  if(p>=a.size()){
    return pii(0,99);
  }
  int po = a[p++];
  if(po==MIN){
    pii x = dfs(a,p);
    pii y = dfs(a,p);
    pii ret;
    ret.first = min(x.first,y.first);
    ret.second = min(x.second,y.second);
    return ret;
  }else if(po==MAX){
    pii x = dfs(a,p);
    pii y = dfs(a,p);
    pii ret;
    ret.first = max(x.first,y.first);
    ret.second = max(x.second,y.second);
    return ret;
  }else{
    return pii(po,po);
  }
}
int calc(vi &a){
  int x = a.back();
  pii tmp;
  int it;
  int ans;
  if(x<0){
    a.back() = -x;
    it = 0;
    tmp = dfs(a,it);
    if(tmp.second != tmp.first){
      a.back() = x;
      return -1;
    }
    int yes = tmp.first;
    a.back() = -x*10+9;
    it = 0;
    tmp = dfs(a,it);
    if(tmp.first != yes || tmp.second != yes){
      a.back() = x;
      return -1;
    }
    ans = tmp.first;
    a.back() = x;
  }else{
    it = 0;
    tmp = dfs(a,it);
    if(tmp.second != tmp.first)return -1;
    ans = tmp.first;
  }
  return ans;
}
void solve(){
  scanf("%s",s);
  n = strlen(s);
  a.clear();
  REP(i,n){
    char c = s[i];
    if(c=='_'){
      a.push_back(MIN);
    }else if(c=='^'){
      a.push_back(MAX);
    }else if(c=='('){
      // nothing
    }else if(c==',' || c=='?'){
      if(a.back()<0){
        a.back() = -a.back();
      }
    }else if(c==')'){
      // stack pop
      if(a.back()<0){
        a.back() = -a.back();
      }
      int x = a.back(); a.pop_back();
      int y = a.back(); a.pop_back();
      int op = a.back(); a.pop_back();
      if(op==MIN){
        a.push_back(min(x,y));
      }else if(op==MAX){
        a.push_back(max(x,y));
      }
    }else{
      int x = c-'0';
      if(a.size()>0 && a.back()<0){
        int y = -a.back(); a.pop_back();
        a.push_back(10*y + x);
      }else{
        a.push_back(-x);
      }
    }
    // check
    int k = calc(a);
    if(k!=-1){
      printf("%d %d\n",k,i+1);
      return;
    }
  }
}

int main(){
  int q;
  scanf("%d",&q);
  while(q--)solve();
  return 0;
}

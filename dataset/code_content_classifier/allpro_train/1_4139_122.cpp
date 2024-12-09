#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
#define dumpR(x) cerr<<"\x1b[31m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
#define dumpY(x) cerr<<"\x1b[33m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
#define dumpG(x) cerr<<"\x1b[32m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define dumpR(x) ;
#define dumpY(x) ;
#define dumpG(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }

typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
  template<class S,class T>
  ostream &operator <<(ostream& out,const pair<S,T>& a){
    out<<'('<<a.fr<<','<<a.sc<<')';
    return out;
  }
}
template<lint mod>
struct Int_{
  unsigned x;
  unsigned mpow(Int_ a,unsigned k){
    Int_ res=1;
    while(k){
      if(k&1) res=res*a;
      a=a*a;
      k>>=1;
    }
    return res.x;
  }
  unsigned inverse(Int_ a){
    return mpow(a,mod-2);
  }
  Int_(): x(0) { }
  Int_(long long sig) {
    int sigt=sig%mod;
    if(sigt<0) sigt+=mod;
    x=sigt;
  }
  unsigned get() const { return (unsigned)x; }

  Int_ &operator+=(Int_ that) { if((x += that.x) >= mod) x -= mod; return *this; }
  Int_ &operator-=(Int_ that) { if((x += mod - that.x) >= mod) x -= mod; return *this; }
  Int_ &operator*=(Int_ that) { x = (unsigned long long)x * that.x % mod; return *this; }
  Int_ &operator=(Int_ that) { x=that.x; return *this;}
  Int_ &operator/=(Int_ that) { x=(unsigned long long) x * inverse(that.x)%mod; return *this;}
  bool operator==(Int_ that) const { return x==that.x; }
  bool operator!=(Int_ that) const { return x!=that.x; }

  Int_ operator-() const { return Int_(0)-Int_(*this);}
  Int_ operator+(Int_ that) const { return Int_(*this) += that; }
  Int_ operator-(Int_ that) const { return Int_(*this) -= that; }
  Int_ operator*(Int_ that) const { return Int_(*this) *= that; }
  Int_ operator/(Int_ that) const { return Int_(*this) /= that; }
  Int_ inv(){
    return Int_(mpow(x,mod-2));
  }
};

namespace std{
  template<lint mod>
  ostream &operator <<(ostream& out,const Int_<mod>& a){
    out<<a.get();
    return out;
  }
  template<lint mod>
  istream &operator >>(istream& in,Int_<mod>& a){
    in>>a.x;
    return in;
  }
};

typedef Int_<998244353> Int;

Int mpow(Int a,lint k){
  Int res=1;
  while(k){
    if(k&1) res=res*a;
    a=a*a;
    k>>=1;
  }
  return res;
}
int n,m;
char S[10005],T[10005];
int memo[10005][10005];

Int fact[10005],invf[10005];

Int P(int a,int b){
  return fact[a]*invf[a-b];
}

Int C(int a,int b){
  if(a<0 || b<0 || a<b) return 0;
  return fact[a]*invf[b]*invf[a-b];
}
Int rec(int a,int b){
  if(a<0 || b<0) return 0;
  if(a==0 && b==0) return 1;
  int& res=memo[a][b];
  if(~res) return res;

  Int res2=0;
  if(b==0){
    res2=P(m,a)*fact[a];
  }else{
    res2+=rec(a-1,b)*a*b;
    res2+=rec(a,b-1)*b*b;
  }
  res=res2.x;
  return res2;
}
int main(){
#ifdef LOCAL_REDIR
  freopen("/home/hog/Dropbox/pg/working/in.txt","r",stdin);
#endif
  scanf("%s%s",S,T);
  n=strlen(S);
  fact[0]=invf[0]=1;
  REP(i,n+1){
    fact[i+1]=fact[i]*(i+1);
    invf[i+1]=fact[i+1].inv();
  }

  int a=0,b=0,c=0;
  memset(memo,-1,sizeof(memo));
  REP(i,n){
    if(S[i]==T[i] && S[i]=='1') ++a;
    if(S[i]=='0' && T[i]=='1') ++b;
    if(S[i]=='1' && T[i]=='0') ++c;
  }
  assert(b==c);
  m=a+b;

  Int ans=rec(a,b);

  cout<<ans<<endl;
  return 0;
}





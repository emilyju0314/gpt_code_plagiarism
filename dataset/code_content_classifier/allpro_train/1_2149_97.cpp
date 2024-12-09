#define DEB
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


#ifdef DEB
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
struct uf{
  static const int MAXN=200005;
  int par[MAXN];
  int size[MAXN];
  void init(){
    memset(par,-1,sizeof(par));
    REP(i,MAXN) size[i]=1;
  }
  int root(int a){
    if(par[a]==-1) return a;
    return par[a]=root(par[a]);
  }
  void unite(int a,int b){
    a=root(a);b=root(b);
    if(a==b) return;
    if(size[a]<size[b]) swap(a,b);

    par[b]=a;
    size[a]+=size[b];
  }
  bool same(int a,int b){
    return root(a)==root(b);
  }
};

uf u;

int n,m,K;
int col[100005];
pair<int,pi> es[100005];
int main(){
  cin>>n>>m>>K;

  int K2=K;
  REP(i,n){
    scanf("%d",&col[i]);
    --col[i];
    if(col[i]==-1) col[i]=K2++;
  }
  REP(i,m){
    int a,b,w;scanf("%d%d%d",&a,&b,&w);
    --a;--b;
    int ca=col[a],cb=col[b];
    es[i]={w,{ca,cb}};
  }
  sort(es,es+m);
  u.init();
  int comp=K2;
  int uni=0;

  lint tot=0;
  lint res=-1;
  REP(i,m) {
    if(!u.same(es[i].sc.fr,es[i].sc.sc)){
      u.unite(es[i].sc.fr,es[i].sc.sc);
      --comp;
      ++uni;
      tot+=es[i].fr;
      if(uni==K-1){
        res=tot;
        break;
      }
    }
  }
  cout<<res<<endl;
  return 0;
}
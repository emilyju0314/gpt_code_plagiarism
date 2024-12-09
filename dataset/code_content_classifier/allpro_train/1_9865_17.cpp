#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <complex>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <stack>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cassert>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
#define EPS (1e-10)
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define REP(i, n) rep (i, n)
#define F first
#define S second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define min3(a,b,c) min((a),min((b),(c)))
#define min4(a,b,c,d) min((a),min3((b),(c),(d)))
#define SZ(a) (int)((a).size())
#define ALL(a) a.begin(),a.end()
#define FLL(a,b) memset((a),b,sizeof(a))
#define CLR(a) memset((a),0,sizeof(a))
#define FOR(it,a) for(__typeof(a.begin())it=a.begin();it!=a.end();++it)
template<typename T,typename U> ostream& operator<< (ostream& out, const pair<T,U>& val){return out << "(" << val.F << ", " << val.S << ")";}
template<class T> ostream& operator<< (ostream& out, const vector<T>& val){out << "{";rep(i,SZ(val)) out << (i?", ":"") << val[i];return out << "}";}
typedef double FP;
typedef complex<FP> pt;
typedef pt P;
typedef pair<pt,pt> line;
FP dot(P a,P b){return real(conj(a)*b);}
FP crs(P a,P b){return imag(conj(a)*b);}
P ortho(P a){return a*P(0,1);}
P ortho(line a){return ortho(a.S-a.F);}
P crspt(P a,P b,P c,P d){b-=a,d-=c;return a+b*crs(d,c-a)/crs(d,b);}
P crspt(line a,line b){return crspt(a.F,a.S,b.F,b.S);}
bool onl(P a1,P a2,P b){return abs(b-a1)+abs(b-a2)<abs(a1-a2)+EPS;}
bool onl(line a,P b){return onl(a.F,a.S,b);}
bool iscrs(line a,line b){P c=crspt(a,b);return onl(a,c)&&onl(b,c);}
void pkuassert(bool t){t=1/t;};
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={1,0,-1,0,-1,1,1,-1};
enum{TOP,BTM,LFT,RGT,FRT,BCK};
int dxdy2ce[]={RGT,FRT,LFT,BCK};
template<class T> T shift(T a,int b,int c,int d,int e){
 __typeof(a[0])t=a[b];a[b]=a[c];a[c]=a[d];a[d]=a[e];a[e]=t;
 return a;}
template<class T> T rgt(T a){return shift(a,TOP,LFT,BTM,RGT);}
template<class T> T lft(T a){return shift(a,TOP,RGT,BTM,LFT);}
template<class T> T frt(T a){return shift(a,TOP,BCK,BTM,FRT);}
template<class T> T bck(T a){return shift(a,TOP,FRT,BTM,BCK);}
line mkl(P a,P v){return line(a,a+v);}
FP lpdist(line a,P b){return abs(b-crspt(a,mkl(b,ortho(a))));}
FP spdist(line a,P b){
  P c(crspt(a,mkl(b,ortho(a))));
  return onl(a,c)?abs(b-c):min(abs(a.F-b),abs(a.S-b));
}
FP ssdist(line a,line b){
 return
  iscrs(a,b)?0.:
   min4(spdist(a,b.F),spdist(a,b.S),
        spdist(b,a.F),spdist(b,a.S));
}
namespace std{
  bool operator<(const P&a,const P&b){
    return mp(real(a),imag(a))<mp(real(b),imag(b));
  }
}

int h,w;
int in[12][12];

PI rinsetu[12*12];
int rsz;
bool isrinsetu[12][12];
bool issh[12][12];
vector<PI> choco;
PI tree[12*12];
int tsz=0;
int row[12],col[12];

int maxdist[6];

bool iddfs(int depth,int ne,int ch){
  if(depth==0)
    return ch==SZ(choco);

  if(ne)
    rep(j,SZ(choco))
      if(depth<maxdist[j]) return false;
  if(ne&&ch==SZ(choco)-1) return true;
  
  int crsz=rsz;
  int back[6];
  rep(i,SZ(choco)) back[i]=maxdist[i];
  
  for(int i=ne;i<crsz;++i){
    PI node=rinsetu[i];
    if(!row[node.F] && !col[node.S]) continue;
    bool flag[4]={};
    int nu=0;
    rep(k,4){
      int nx=node.F+dx[k];
      int ny=node.S+dy[k];
      if(min(nx,ny)<0 || nx>=h || ny>=w) continue;
      nu += issh[nx][ny];
      if(isrinsetu[nx][ny])
        continue;
      isrinsetu[nx][ny]=true;
      flag[k]=true;
      rinsetu[rsz++]=PI(nx,ny);
    }
    issh[node.F][node.S]=true;
    tree[tsz++]=node;
    int ok=0;
    //bool ok=false;
    rep(j,SZ(choco)){
      int b=maxdist[j];
      maxdist[j]=
      min(maxdist[j],
          abs(node.F-choco[j].F)+abs(node.S-choco[j].S));
      ok|=(b!=maxdist[j])<<j;
    }
    
    if((nu<2 || in[node.F][node.S]) && ok &&
       iddfs(depth-1,i+1,ch+in[node.F][node.S]))
      return true;
    
    rep(j,SZ(choco)) maxdist[j]=back[j];
    
    --tsz;
    rep(k,4)if(flag[k]){
      int nx=node.F+dx[k];
      int ny=node.S+dy[k];
      isrinsetu[nx][ny]=false;
    }
    rsz=crsz;
    issh[node.F][node.S]=false;
    if(in[node.F][node.S]) return false;
  }
  return false;
}



void solve(){
  CLR(row);
  CLR(col);
  int low=0;
  choco.clear();
  rep(i,h)rep(j,w){
    cin >> in[i][j];
    low += in[i][j];
    row[i]+=in[i][j];
    col[j]+=in[i][j];
    if(in[i][j]) choco.pb(mp(i,j));
  }
  

  if(SZ(choco)<1){
    cout << h*w << endl;
    return;
  }
  int maxdist=0;
  rep(i,SZ(choco))rep(j,i)
    maxdist=
    max(maxdist,
        abs(choco[i].F-choco[j].F)+abs(choco[i].S-choco[j].S));
  low=max(low,maxdist);
  
  for(int depth=low;depth<=h*w;++depth){
    //cerr << depth << endl;
    CLR(isrinsetu);
    CLR(issh);
    rsz=0;
    int idx=0;rand()%SZ(choco);
    rinsetu[rsz++]=choco[idx];
    //cerr << choco[idx] << endl;
    isrinsetu[choco[idx].F][choco[idx].S]=1;
    tsz=0;
    rep(i,SZ(choco)) ::maxdist[i]=140;
    
    if(iddfs(depth,0,0)){
      cout << h*w-depth << endl;
      return;
    }
  }
  
}

int main(int argc, char *argv[])
{
  while(cin >> h >> w && h) solve();
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF 1e16
#define mod 1000000007

int P,R,T;
int init[303];
int need[303][303];
int p[200001],r[200001];

bool f(int t){
  vector<int> crtr(R);
  vector<vector<int> > crtp(P,vector<int>(R));
  vector<int> crtnz(P,0);
  vector<bool> used(P,false);

  rep(i,R)crtr[i]=init[i];
  rep(i,P)rep(j,R)crtp[i][j]=need[i][j];
  rep(i,P)rep(j,R)if(crtp[i][j]==0)crtnz[i]++;
  rep(i,t){
    crtr[r[i]]--;
    crtp[p[i]][r[i]]--;
    if(crtr[r[i]]<0)return false;
    if(crtp[p[i]][r[i]]==0)crtnz[p[i]]++;
    if(crtnz[p[i]]==R){
      used[p[i]]=true;
      rep(j,R)crtr[j]+=need[p[i]][j];
    }
  }

  bool update=true;
  while(update){
    update=false;
    rep(i,P){
      if(used[i])continue;
      bool ok=true;
      rep(j,R)if(crtp[i][j]>crtr[j])ok=false;
      if(!ok)continue;
      rep(j,R)crtr[j]+=need[i][j]-crtp[i][j];
      used[i]=true;
      update=true;
      break;
    }
  }
  bool ok=true;
  rep(i,P)if(!used[i])ok=false;
  return ok;
}

int main(){
  scanf("%d%d%d",&P,&R,&T);
  rep(i,R)scanf("%d",init+i);
  rep(i,P)rep(j,R)scanf("%d",&need[i][j]);
  rep(i,T){
    scanf("%d%d",p+i,r+i);
    p[i]--;r[i]--;
  }

  int lb=0,ub=T+1;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(f(mid))lb=mid;
    else ub=mid;
  }
  if(ub==T+1)cout<<-1<<endl;
  else cout<<ub<<endl;
  return 0;
}


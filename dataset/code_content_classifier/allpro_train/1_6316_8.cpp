#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcountll

#define INF INT_MAX/3
#define mod 1000000007

vector<P> g[100010];
int sz[100010];
bool dame[100010];
vector<int> cent;

void compute_subtree_size(int v,int pre){
  sz[v]=1;
  for(P e : g[v]){
    int nv=e.fi;
    if(nv==pre||dame[nv])continue;
    compute_subtree_size(nv,v);
    sz[v]+=sz[nv];
  }
}

void search_centroid(int v,int pre,int tot){
  bool is_cent=true;
  for(P e : g[v]){
    int nv=e.fi;
    if(nv==pre||dame[nv])continue;
    search_centroid(nv,v,tot);
    if(sz[nv]>tot/2)is_cent=false;
  }
  if(tot-sz[v]>tot/2)is_cent=false;
  if(is_cent)cent.push_back(v);
}

vector<int> downs;
int ans=0;

void update(int v,int pre,int depth,int crtup,int upmx){
  for(P e : g[v]){
    int nv=e.fi;
    if(nv==pre){
      crtup+=e.se; break;
    }
  }
  if(crtup>=upmx){
    int lb=0,ub=downs.size();
    while(ub-lb>1){
      int mid=(ub+lb)/2;
      if(crtup+downs[mid]>=0)lb=mid;
      else ub=mid;
    }
    maxch(ans,depth+lb);
  }
  for(P e : g[v]){
    int nv=e.fi;
    if(dame[nv]||nv==pre)continue;
    update(nv,v,depth+1,crtup,max(crtup,upmx));
  }
}

int calcdown(int v,int pre,int depth,int crtdown,int downmn){
  maxch(downs[depth],downmn);
  for(P e : g[v]){
    int nv=e.fi;
    if(dame[nv]||nv==pre)continue;
    downs[depth]=max(downs[depth],calcdown(nv,v,depth+1,crtdown+e.se,min(crtdown+e.se,downmn)));
  }
  return downs[depth];
}

void solve_subprob(int v){ // main
  compute_subtree_size(v,-1);
  cent.clear();
  search_centroid(v,-1,sz[v]);
  int c=cent[0];
  int szv=sz[v];
  dame[c]=true;

  // devide
  for(P e : g[c]){
    int nv=e.fi;
    if(dame[nv])continue;
    solve_subprob(nv);
  }

  dame[c]=false;
  // conquer
  for(int i=0;i<2;reverse(all(g[c])),i++){
    downs.resize(szv);
    rep(j,szv)downs[j]=-INF;
    downs[0]=0;
    for(P e : g[c]){
      int nv=e.fi;
      if(dame[nv])continue;
      update(nv,c,1,0,0);
      downs[0]=max(downs[0],calcdown(nv,c,1,e.se,e.se));
    }
  }
  reverse(all(g[c]));
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin>>N;
  vector<int> A(N);
  rep(i,N)cin>>A[i];
  rep(i,N-1){
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    g[a].push_back(P(b,A[a]-c));
    g[b].push_back(P(a,A[b]-c));
  }
  solve_subprob(0);
  cout<<ans+1<<endl;

  return 0;
}


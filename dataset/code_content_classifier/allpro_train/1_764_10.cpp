#include<bits/stdc++.h>
using namespace std;
using Int = long long;

struct LCA{
  int n;
  vector<int> P,D,E,A,T,ht;
  vector<vector<int> > G,dat;
  LCA(int n):
    n(n),P(n,-1),D(n),E(n*2,0),A(n*2,-1),G(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void dfs(int v,int p,int d,int &k){
    D[v]=k;
    A[k]=P[v]=p;
    E[k++]=d;
    for(int u:G[v])
      if(u!=p) dfs(u,v,d+1,k);
    A[k]=P[v];
    E[k++]=d-1;
  }

  // if it need leftmost, then add: if(E[i]==E[j]) return i<j?i:j;
  inline int comp(int i,int j){return E[i]<E[j]?i:j;};
  
  void build(int r=0){
    int k=0;
    dfs(r,-1,1,k);

    int h=1,m=n*2;
    while((1<<h)<m) h++;
    dat.assign(h,vector<int>(m,-1));
    ht.assign(m+1,0);
    for(int j=2;j<=m;j++) ht[j]=ht[j>>1]+1;
    
    for(int j=0;j<m;j++) dat[0][j]=j;
    
    for(int i=1,p=1;i<h;i++,p<<=1)
      for(int j=0;j<m;j++)
        dat[i][j]=comp(dat[i-1][j],dat[i-1][min(j+p,m-1)]);
  }

  inline int rmq(int a,int b){
    int l=b-a;
    return comp(dat[ht[l]][a],dat[ht[l]][b-(1<<ht[l])]);
  }
  
  inline int lca(int l,int r){
    if(l==r) return l;
    if(D[l]>D[r]) swap(l,r);
    int x=D[l],y=D[r];
    int m=rmq(x,y);
    return m==x?l:A[m];
  }
};

struct LevelAncestor{
  LCA &tree;
  int n,h;
  vector<vector<int> > G,par,lad;
  vector<int> dep,nxt,len,pth,ord,hs;
  LevelAncestor(LCA &lca,int n):
    tree(lca),n(n),G(n),dep(n),nxt(n,-1),len(n),pth(n),ord(n),hs(n+1,0){
    h=1;
    while((1<<h)<=n) h++;
    par.assign(h,vector<int>(n,-1));
    
    for(int i=2;i<=n;i++) hs[i]=hs[i>>1]+1;
  }

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  
  void dfs(int v,int p,int d,int f){
    if(nxt[v]<0){
      par[0][nxt[v]=v]=p;
      len[v]=dep[v]=d;
      for(int u:G[v]){
	if(u==p) continue;
	dfs(u,v,d+1,0);
	if(len[v]<len[u]) nxt[v]=u,len[v]=len[u];
      }
    }
    if(!f) return;
    pth[v]=lad.size();
    lad.emplace_back();
    for(int k=v;;k=nxt[k]){
      lad.back().emplace_back(k);
      pth[k]=pth[v];
      if(k==nxt[k]) break;
    }
    for(;;p=v,v=nxt[v]){	
      for(int u:G[v])
	if(u!=p&&u!=nxt[v]) dfs(u,v,d+1,1);	
      if(v==nxt[v]) break;
    }
  }
  
  void build(int r=0){
    dfs(r,-1,0,1);
    for(int k=0;k+1<h;k++){
      for(int v=0;v<n;v++){
	if(par[k][v]<0) par[k+1][v]=-1;
	else par[k+1][v]=par[k][par[k][v]];
      }
    }
    for(int i=0;i<(int)lad.size();i++){
      int v=lad[i][0],p=par[0][v];
      if(~p){
	int k=pth[p],l=min(ord[p]+1,(int)lad[i].size());
	lad[i].resize(l+lad[i].size());
	for(int j=0,m=lad[i].size();j+l<m;j++)
	  lad[i][m-(j+1)]=lad[i][m-(j+l+1)];
	for(int j=0;j<l;j++)
	  lad[i][j]=lad[k][ord[p]-l+j+1];
      }
      for(int j=0;j<(int)lad[i].size();j++)
	if(pth[lad[i][j]]==i) ord[lad[i][j]]=j;
    }
  }
  
  inline int lca(int u,int v){
    return tree.lca(u,v);
  }

  inline int up(int v,int d){
    if(d==0) return v;
    v=par[hs[d]][v];
    d-=1LL<<hs[d];
    return lad[pth[v]][ord[v]-d];
  }
  
  inline int distance(int u,int v){
    return dep[u]+dep[v]-dep[tree.lca(u,v)]*2;
  }
  
  inline int path(int u,int v,int d){
    if(d==0) return u;
    int r=tree.lca(u,v);
    int x=distance(u,r),y=distance(r,v);
    if(d<=x) return up(u,d);
    return up(v,(x+y)-d);
  }
  
};

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  int n,q;
  scanf("%d %d",&n,&q);
  using P = pair<int, int>;
  vector<vector<P> > G(n);
  LCA lca(n);
  LevelAncestor la(lca,n);
  for(int i=1;i<n;i++){
    int u,v,w;
    scanf("%d %d %d",&u,&v,&w);
    u--;v--;
    lca.add_edge(u,v);
    la.add_edge(u,v);
    G[u].emplace_back(v,w);
    G[v].emplace_back(u,w);
  }

  lca.build();
  la.build();

  vector<int> dep(n,0);
  {
    queue<P> q;
    q.emplace(0,-1);
    while(!q.empty()){
      int v,p;
      tie(v,p)=q.front();q.pop();
      for(auto e:G[v]){
	int u,c;
	tie(u,c)=e;
	if(u==p) continue;
	dep[u]=dep[v]+c;
	q.emplace(u,v);
      }
    }
  }
  
  auto dist=[&](int u,int v){return dep[u]+dep[v]-2*dep[lca.lca(u,v)];};
  for(int i=0;i<q;i++){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    a--;b--;c--;
    auto calc=[&](int v,int u=-1){
		return max({dist(a,v)*(a!=u),
			    dist(b,v)*(b!=u),
			    dist(c,v)*(c!=u)});
	      };
    
    int p=lca.lca(a,b),q=lca.lca(b,c),r=lca.lca(c,a);
    int v=la.dep[p]>la.dep[q]?p:(la.dep[q]>la.dep[r]?q:r);
    
    int ans=min({calc(a),calc(b),calc(c),calc(v)});
    for(int u:{a,b,c}){
      if(calc(v,u)>=ans) continue;
      int l=0,r=la.distance(u,v);
      while(l+1<r){
	int m=(l+r)>>1;
	int x=la.path(u,v,m);
	if(calc(x,u)<dist(x,u)) r=m;
	else l=m;
      }
      chmin(ans,calc(la.path(u,v,l)));
      chmin(ans,calc(la.path(u,v,r)));
    }
    printf("%d\n",ans);
  }
  return 0;
}


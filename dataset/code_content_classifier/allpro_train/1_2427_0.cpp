#include<bits/stdc++.h>
using namespace std;
#define MAX_N 500
#define MAX_M 50000
struct edge{ int from,to,id; };

int N,M;
int a[MAX_M],b[MAX_M];
bool flg[MAX_M];

vector<edge> G[MAX_N];

bool visited[MAX_N];
int depth[MAX_N];
int cnt[MAX_N];
int par[MAX_N];


vector<edge> bridges;


vector<edge> edge_;

void dfs(int pos,int prev){
  visited[pos]=true;
  for(int i=0;i<(int)G[pos].size();i++){
    int to=G[pos][i].to;
    if(to==prev)continue;
    if(!visited[to]){
      depth[to]=depth[pos]+1;
      par[to]=pos;
      dfs(to,pos);
      cnt[pos]+=cnt[to];
      if(cnt[to]==0)bridges.push_back(G[pos][i]);
    }else if(depth[to]<depth[pos]){
      cnt[pos]++;
      cnt[to]--;
      edge_.push_back(G[pos][i]);
    }
  }
}

int countB(int id){
  bridges.clear();
  edge_.clear();
  
  memset(visited,false,sizeof(visited));
  memset(depth,0,sizeof(depth));
  memset(cnt,0,sizeof(cnt));
  memset(par,-1,sizeof(par));
  
  for(int i=0;i<N;i++)G[i].clear();
  for(int i=0;i<M;i++){
    if(i==id)continue;
    G[ a[i] ].push_back( (edge){ a[i],b[i],i } );
    G[ b[i] ].push_back( (edge){ b[i],a[i],i } );
  }
  for(int i=0;i<N;i++){
    if(visited[i])continue;
    dfs(i,-1);
  }
  return bridges.size();
}

bool isDag(int id){
  queue<int> Q;  
  vector<int> C(N,0);
  int cc=0;
  
  for(int i=0;i<N;i++)G[i].clear();
  for(int i=0;i<M;i++){
    if(i==id)continue;
    G[ a[i] ].push_back( (edge){a[i],b[i],i} );
    C[ b[i] ]++;
  }
  for(int i=0;i<N;i++)if(C[i]==0)Q.push(i);

  while(!Q.empty()){
    int pos=Q.front();Q.pop();
    cc++;
    for(int i=0;i<(int)G[pos].size();i++){
      int to=G[pos][i].to;
      C[to]--;
      if(C[to]==0)Q.push(to);
    }
  }
  return (cc==N);
}

void visit(int v){
  if(visited[v])return;
  visited[v]=true;
  for(int i=0;i<(int)G[v].size();i++){
    visit(G[v][i].to);
  }
}

int calcDec(int id){
  for(int i=0;i<N;i++)G[i].clear();
  for(int i=0;i<M;i++){
    if(i==id)continue;
    G[ a[i] ].push_back( (edge){a[i],b[i],i} );
    G[ b[i] ].push_back( (edge){b[i],a[i],i} );
  }
  int res=0;
  memset(visited,false,sizeof(visited));
  for(int i=0;i<N;i++){
    if(!visited[i]){
      res++;
      visit(i);
    }
  }
  return res;
}

map<int,int> mm;
bool check(int id){
  if(mm.count(id))return false;
  mm[id]=true;
  
  if(countB(id) + calcDec(id)>=3&&isDag(id))return true;
  else return false;
}

vector<edge> loope;
bool rec(int pos,int si){
  if(visited[pos])return (pos==si);
  visited[pos]=true;
  for(int i=0;i<(int)G[pos].size();i++){
    edge e=G[pos][i];
    if( rec(e.to,si) ){
      loope.push_back(e);
      return true;
    }
  }
  return false;
}

bool solve2(){
  for(int i=0;i<N;i++)G[i].clear();
  for(int i=0;i<M;i++)G[ a[i] ].push_back( (edge){a[i],b[i],i} );
  
  for(int i=0;i<N;i++){
    memset(visited,false,sizeof(visited));
    loope.clear();
    if( rec(i,i) )break;
  }
  
  for(int i=0;i<(int)loope.size();i++)
    if(check( loope[i].id ))return true;

  return false;
}

bool solve(){
  int B=countB(-1);
  if(B==M)return false;
  
  if( !isDag(-1) )return solve2();

  /*
  for(int i=0;i<M;i++){
    if(check(i)){
      return true;
    }
  }
  */
  int maxm=0;

  
  B=countB(-1);
  for(int i=0;i<(int)edge_.size();i++){
    edge e=edge_[i];
    int a=e.from;
    int cc=0;
    while(1){
      if(a==e.to)break;
      if(cnt[a]==1)cc++;
      a=par[a];
    }
    maxm=max(maxm,cc);
  }

  for(int i=0;i<M;i++)
    if(check(i))return true;
  /*
  vector<edge> tmp=edge_;
  for(int i=0;i<(int)tmp.size();i++){
    edge e=tmp[i];
    if(check(e.id))return true;
  }
  */
  return (B+maxm>=2);
}

int main(){
  cin>>N>>M;
  for(int i=0;i<M;i++){
    cin>>a[i]>>b[i];
    a[i]--;
    b[i]--;
  }
  cout<< ( solve() ? "YES" : "NO" ) <<endl;
  return 0;
}
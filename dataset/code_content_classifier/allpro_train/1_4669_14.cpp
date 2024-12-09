#include<bits/stdc++.h>
using namespace std;

int n,m;
double x[100],y[100],v[100];
double px[100],py[100];
double t[100][100];
vector<int> G[200];

void add_edge(int u,int v){
  G[u].push_back(v);
  G[v].push_back(u);
}

int match[200],used[200];

bool dfs(int v){
  used[v]=true;
  for(int i=0;i<(int)G[v].size();i++){
    int u=G[v][i],w=match[u];
    if(w<0||(!used[w]&&dfs(w))){
      match[v]=u;
      match[u]=v;
      return true;
    }
  }
  return false;
}

int bipartite_matching(){
  int res=0;
  memset(match,-1,sizeof(match));
  for(int v=0;v<n+m;v++){
    if(match[v]<0){
      memset(used,0,sizeof(used));
      if(dfs(v))res++;
    }
  }
  return res;
}

bool check(double X){
  for(int i=0;i<n+m;i++)G[i].clear();
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if(t[i][j]<X)
        add_edge(i,n+j);
  if(bipartite_matching()==m)return true;
  return false;
}

double solve(){
  double l=0,r=1e8,m;
  for(int i=0;i<200;i++){
    m=(l+r)*0.5;
    if(check(m))r=m;
    else l=m;
  }
  return l;
}

int main(){
  while(1){
    cin>>n>>m;
    if(n==0&&m==0)break;
    for(int i=0;i<n;i++)cin>>x[i]>>y[i]>>v[i];
    for(int i=0;i<m;i++)cin>>px[i]>>py[i];
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        double dx=x[i]-px[j];
        double dy=y[i]-py[j];
        t[i][j]=sqrt(dx*dx+dy*dy)/v[i];
      }
    }
    printf("%.10f\n",solve());
  }
  return 0;
}
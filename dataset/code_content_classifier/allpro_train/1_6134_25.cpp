#include<bits/stdc++.h>
using namespace std;
#define MAX_N 2000
int a[MAX_N],b[MAX_N],c[MAX_N],m,t,x;
vector<int> G[MAX_N];
void init(){
  t=x=0;
  memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  memset(c,0,sizeof(c));
  for(int i=0;i<MAX_N;i++) G[i].clear();
}
void dfs(int d){
  int v=t,p=++x;
  b[d]=p;
  for(int i=0;(int)G[p].size()<a[v];i++){
    t++;
    if(a[t]>0){
      G[p].push_back(x+1);
      G[x+1].push_back(p);
      dfs(d+1);
    }else if(a[t]<0){
      G[p].push_back(b[d+a[t]]);
      G[b[d+a[t]]].push_back(p);
    }else break;
  }
}
int main(){
  int n;cin>>n;
  while(n--){
    init();
    for(int i=0;;i++){
      cin>>a[i];
      if(!a[i]){
	m=i;
	break;
      }
    }
    dfs(0);
    for(int i=1;i<=x;i++){
      if(G[i].size()==0) break;
      cout<<i<<" ";
      sort(G[i].begin(),G[i].end());
      for(int j=0;j<(int)G[i].size();j++)
	cout<<G[i][j]<<" \n"[j==(int)G[i].size()-1];
    }
  }
  return 0;
}
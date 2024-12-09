#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

vector<int> A[10010],B;
int color[10010],indeg[10010];
int v,e;

void bfs(int s){
  queue<int> q;
  q.push(s);
  color[s]=1;
  while(!q.empty()){
    int u=q.front(); q.pop();
    B.push_back(u);
    for(auto x:A[u]){
      indeg[x]--;
      if(indeg[x]==0 && color[x]==0){
        color[x]=1;
        q.push(x);
      }
    }
  }  
}

int main(){
  cin>>v>>e;
  
  int s,t;
  rep(i,e){
    cin>>s>>t;
    indeg[t]++;
    A[s].push_back(t);
  }
  
  rep(i,v){
    if(indeg[i]==0 && color[i]==0) bfs(i);
  }
  
  rep(i,v) cout<<B[i]<<endl;
  
  return 0;
}

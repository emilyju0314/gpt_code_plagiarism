#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
#include<cstdio>
#define F first
#define S second
#define INF 1<<30
using namespace std;
typedef pair<int,int> P;
int n,m;
int prim();
int main(){
  while(1){
    cin>>n;
    if(n==0)break;
    cin>>m;
    cout<<prim()/100-(n-1)<<endl;
  }
}
int prim(){
  vector<P> cost[111];
  bool used[111];
  int ans=0;
  int from,to,mm;
  for(int i=0;i<m;i++){
    scanf("%d,%d,%d",&from,&to,&mm);
    cost[from].push_back(P(to,mm));
    cost[to].push_back(P(from,mm));
  }
  for(int i=0;i<111;i++){
    used[i]=false;
  }
  priority_queue< P ,vector<P>,greater<P> > q;
  q.push(P(0,0));
  while(!q.empty()){
    P p=q.top();
    q.pop();
    if(used[p.S]==true){
      continue;
    }
    used[p.S]=true;
    ans+=p.F;
    for(int i=0;i<cost[p.S].size();i++){
      q.push(P(cost[p.S][i].S,cost[p.S][i].F));
    }
  }
  return ans;
}
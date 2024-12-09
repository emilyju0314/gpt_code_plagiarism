#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<P,P> P1;
int G[4][4],sum,ans=6;
int X[6][4][4];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int tim[4][4];

void dfs(int dep,int s){
  if(dep==6)return;
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++){
      int cnt=0;
      if(!G[i][j])continue;
      G[i][j]--;
      X[dep][i][j]++;
      cnt++;
      queue<P1> q;
      for(int k=0;k<4;k++){
	int ny=i+dy[k],nx=j+dx[k];
	if(ny<0||nx<0||4<=ny||4<=nx)continue;
	if(G[i][j])continue;
	tim[i][j]=0;
	q.push(P1(P(1,k),P(ny,nx)));
      }
      while(!q.empty()){
	P1 t=q.front(); q.pop();
	int y=t.second.first,x=t.second.second;
	int cost=t.first.first,d=t.first.second;
	if(!G[y][x]){
	  if(tim[y][x]==cost)continue;
	  int ny=y+dy[d],nx=x+dx[d];
	  if(ny<0||nx<0||4<=ny||4<=nx)continue;
	  q.push(P1(P(cost+1,d),P(ny,nx)));
	}else{
	  G[y][x]--;
	  X[dep][y][x]++;
	  cnt++;
	  for(int k=0;k<4;k++){
	    int ny=y+dy[k],nx=x+dx[k];
	    if(ny<0||nx<0||4<=ny||4<=nx)continue;
	    if(G[y][x])continue;
	    tim[y][x]=cost;
	    q.push(P1(P(cost+1,k),P(ny,nx)));
	  }
	}
      }
      if(s+cnt==sum)ans=min(ans,dep);
      dfs(dep+1,s+cnt);
      for(int y=0;y<4;y++)
	for(int x=0;x<4;x++){
	  G[y][x]+=X[dep][y][x];
	  if(G[y][x])tim[y][x]=0;
	  X[dep][y][x]=0;
	}
    }
}

int main(){
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++){
      cin>>G[i][j];
      G[i][j]=5-G[i][j];
      if(G[i][j]==5)G[i][j]=0;
      sum+=G[i][j];
    }
  dfs(1,0);
  if(sum==0)cout<<0<<endl;
  else if(ans==6)cout<<-1<<endl;
  else cout<<ans<<endl;
  return 0;
}
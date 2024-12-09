#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cassert>
#include<climits>
#include<map>
#include<set>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define IINF (INT_MAX)
#define MAX 200

using namespace std;

struct Data{
  int from,to,cost,index;
  Data(int from=-1,int to=-1,int cost=-1,int index=-1):from(from),to(to),cost(cost),index(index){}
};

int V,E;
vector<Data> G[MAX];
bool visited[MAX];

void isconnect(int cur,int &counter,int *ban){
  if(visited[cur])return;
  visited[cur] = true;
  counter++;
  rep(i,G[cur].size()){
    if( ban[0] == G[cur][i].index || ban[1] == G[cur][i].index ) continue;
    isconnect(G[cur][i].to,counter,ban);
  }
}

int main(){
  while(cin >> V >> E,V|E){
    Data *input = new Data[E];
    int mincost = IINF,coef = 0;
    rep(i,V)G[i].clear();
    rep(i,E){
      cin >> input[i].from >> input[i].to >> input[i].cost;
      input[i].index = i;
      if( input[i].cost < 0 ) coef += input[i].cost;
      else {
	G[input[i].from].push_back(input[i]);
	G[input[i].to].push_back(Data(input[i].to,input[i].from,input[i].cost,input[i].index));
      }
    }

    int counter = 0;
    int ban[2] = {-1,-1};
    rep(i,V)visited[i] = false;
    isconnect(0,counter,ban);
    if(counter != V)mincost = min(mincost,coef);

    rep(i,E){
      if( input[i].cost < 0 ) continue;
      rep(j,E){
	if( input[j].cost < 0 ) continue;
	rep(k,V)visited[k] = false;
	ban[0] = i, ban[1] = j;
	counter = 0;
	isconnect(0,counter,ban);
	if( counter != V )mincost = min(mincost,coef+input[i].cost+((i==j)?0:input[j].cost));
      }
    }
    cout << mincost << endl;

    delete [] input;
  }
  return 0;
}
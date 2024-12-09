#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
 
using namespace std;
 
#define sz size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define clr(a, b) memset((a), (b) ,sizeof(a))
 
#define MOD 1000000007

#define MAX_V 300000
#define INF 1000000000

struct edge{int to, cost;};
typedef pair<int,int> P;

vector<edge> G[MAX_V];
int mn[MAX_V];

void ae(int from, int to, int cost){
  edge e = {to,cost};
  G[from].push_back(e);
}

void dijk(int start, int V){
  priority_queue<P, vector<P>, greater<P> > que;
  rep(i,0,V)mn[i] = 1000000000;
  mn[start] = 0;
  que.push(P(0,start));
  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    if(mn[v]<p.first)continue;
    for(int i = 0; i < G[v].size(); i++){
      edge e = G[v][i];
      if(mn[e.to] > mn[v]+e.cost){
        mn[e.to] = mn[v]+e.cost;
        que.push(P(mn[e.to],e.to));
      }
    }
  }
}

int main(){
  int n,x;
  cin>>n>>x;
  vector<int> d;
  vector<int> c;
  rep(i,0,n){
    int a,b;
    cin>>a>>b;
    d.pb(a);
    c.pb(b);
  }
  rep(i,0,200005){
    rep(j,0,d.sz){
      if(i-d[j]>=0){
        ae(i,i-d[j],c[j]);
      }
      if(i+d[j]<200005){
        ae(i,i+d[j],c[j]);
      }
    }
  }
  dijk(0,200005);
  if(mn[x]==INF){
    cout << "-1" << endl;
    return 0;
  }
  cout << mn[x] << endl;
  return 0;
}

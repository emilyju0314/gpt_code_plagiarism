#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define dbg(x) cout<<#x<<":"<<x<<endl
#define int long long
#define MOD 1000000007
typedef pair<int,int> P;
typedef pair<int,P> PP;

signed main(){
  int n,m,s,t;
  cin>>n>>m>>s>>t;
  s--,t--;
  vector<vector<int> > g(n);
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    x--,y--;
    g[x].pb(y);
    g[y].pb(x);
  }
  int INF = 1000000000;
  queue<P> que;
  que.push(P(s,0));
  vector<int> d(n,INF);
  while(que.size()){
    int v=que.front().fi;
    int cost=que.front().se;
    que.pop();
    if(d[v]!=INF)continue;
    d[v]=cost;
    for(int i=0;i<g[v].size();i++){
	 int to=g[v][i];
	 if(d[to]==INF)que.push(P(to,cost+1));
    }
  }

  queue<P> que2;
  que2.push(P(t,0));
  vector<int> d2(n,INF);
  while(que2.size()){
    int v=que2.front().fi;
    int cost=que2.front().se;
    que2.pop();
    if(d2[v]!=INF)continue;
    d2[v]=cost;
    for(int i=0;i<g[v].size();i++){
	 int to=g[v][i];
	 if(d2[to]==INF)que2.push(P(to,cost+1));
    }
  }
  int l=d[t];
  vector<int> cntd(l+1,0),cntd2(l+1,0);
  for(int i=0;i<n;i++){
    //  cout<<d[i]<<" "<<d2[i]<<endl;
    if(d[i]<=l)cntd[d[i]]++;
    if(d2[i]<=l)cntd2[d2[i]]++;
  }
  
  int ans=0;
  for(int i=0;i<=l-2;i++){
    ans+=cntd[i]*cntd2[l-2-i];
  }
  cout<<ans<<endl;
  
  return 0;
}


#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <complex>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << #x << " = " << (x) << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 2010

vector<vector<int> > G, rev, G2, rev2;
vector<int> id;
vector<int> idDic;
vector<vector<int> > groupList;
vector<int> group;
vector<vector<int> > dp;

int dfs1(int now, int num=1){
  if(id[now] != -1) return num;

  id[now] = 0;
  
  for(int i=0;i<G[now].size();i++){
    num = dfs1(G[now][i], num);
  }

  id[now] = num;
  idDic[num] = now;
  num++;

  return num;
}

bool dfs2(int now, int g){
  if(group[now] >= 0)
    return false;

  group[now] = g;
  groupList[g].push_back(now);
  
  for(int i=0;i<rev[now].size();i++)
    dfs2(rev[now][i], g);

  return true;
}

vector<int> TopologicalSort(vector<vector<int> > G,int n= -1){
  if(n==-1) n=(int)G.size();
  
  int u;
  vector<int> ret,ret2;
  queue<int> que;
  vector<int> indeg(n+1,0);
  
  for(int i=0;i<n;i++){
    for(int j=0;j<G[i].size();j++){
      indeg[G[i][j]]++;
    }
  }
  
  for(int i=0;i<n;i++){
    if(indeg[i]==0){
      que.push(i);
    }
  }
  
  while(!que.empty()){
    u = que.front();
    que.pop();
    
    ret.push_back(u);
    
    for(int i=0;i<G[u].size();i++){
      indeg[G[u][i]]--;
      if(indeg[G[u][i]]==0){
        que.push(G[u][i]);
      }
    }
  }
  
  if(n==(int)ret.size()){
    return ret;
  }else{
    return ret2;
  }
}

bool solve(){
  int N,M,T;
  int p[SIZE], t[SIZE], k[SIZE];
  int a[SIZE], b[SIZE];
  bool selfloop[SIZE] = {};
  
  scanf("%d%d%d",&N,&M,&T);

  if(N == 0) return false;
  
  G.assign(N, vector<int>());
  rev.assign(N, vector<int>());
  G2.assign(N, vector<int>());
  rev2.assign(N, vector<int>());
  id.assign(N, -1);
  idDic.assign(N, -1);
  group.assign(N, -1);
  groupList.assign(N, vector<int>());

  for(int i=0;i<N;i++)
    scanf("%d%d%d",p+i, t+i, k+i);
  
  for(int i=0;i<M;i++){
    scanf("%d%d",a+i, b+i);
    a[i]--; b[i]--;
    G[a[i]].push_back(b[i]);
    rev[b[i]].push_back(a[i]);

    if(a[i] == b[i])
      selfloop[a[i]] = true;
  }
  
  int num = 1, g = 0;
  for(int i=0;i<N;i++) num = dfs1(i, num);
  for(int i=N;i>=1;i--) g += dfs2(idDic[i], g);
  assert(num == N+1);
  
  bool used[110][110] = {};
  
  for(int i=0;i<M;i++){
    int ga = group[a[i]];
    int gb = group[b[i]];
    if(!used[ga][gb] && ga != gb){
       G2[ga].push_back(gb);
       rev2[gb].push_back(ga);
       used[ga][gb] = true;
    }
  }

  auto vec = TopologicalSort(G2, g);
  dp.assign(g, vector<int>(T+1, -INF));
  int ans = 0;
  
  for(int i=0;i<g;i++){
    int gid = vec[i];
    dp[gid][0] = 0;
    bool flag = groupList[gid].size() > 1 || selfloop[groupList[gid][0]];
    
    for(int j=0;j<rev2[gid].size();j++){
      for(int l=0;l<=T;l++)
        dp[gid][l] = max(dp[gid][l], dp[rev2[gid][j]][l]);
    }
    
    for(int j=0;j<groupList[gid].size();j++){
      int q = groupList[gid][j];
      int curk = flag ? k[q] : 1;
      
      for(int base=0;base<t[q];base++){
        priority_queue<pair<int,int> > pq;
        for(int l=base;l<=T;l+=t[q]){
          while(pq.size() && pq.top().second + curk < l/t[q])
            pq.pop();
          
          if(pq.size()){
            auto pqtop = pq.top();
            if(dp[gid][l] >= 0) pq.push({dp[gid][l] - l/t[q] * p[q], l/t[q]});
            dp[gid][l] = max(dp[gid][l], pqtop.first + l/t[q] * p[q]);
          }else{
            if(dp[gid][l] >= 0) pq.push({dp[gid][l] - l/t[q] * p[q], l/t[q]});
          }
        }
      }
    }

    for(int j=0;j<=T;j++){
      ans = max(ans, dp[gid][j]);
    }
  }

  printf("%d\n",ans);

  return true;
}

int main(){

  while(solve());
  
  return 0;
}
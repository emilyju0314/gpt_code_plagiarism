#include<bits/stdc++.h>
using namespace std;

struct lowlink{
  vector<int> ord,low,used;
  vector<vector<int>> adj,tree;
  int root,n;
  lowlink(){}
  lowlink(vector<vector<int>> const& a,int r):adj(a),root(r){
    n = adj.size();
    ord.resize(n);
    low.resize(n);
    used.resize(n);
    tree.reserve(n);
    int k=0;
    dfs(root,-1,k);
  }
  void dfs(int cur,int par,int& k){
    ord[cur] = k++;
    low[cur] = ord[cur];
    used[cur] = 1;
    for(auto nxt:adj[cur]){
      if(used[nxt]==0){
        dfs(nxt,cur,k);
        tree[cur].emplace_back(nxt);
        low[cur] = min(low[cur],low[nxt]);
      }
      else if(ord[nxt]<ord[cur]&&nxt!=par){
        low[cur] = min(low[cur],ord[nxt]);
      }
    }
  }
  vector<int> articulation_points(){
    // 関節点 := 頂点u,子vについて、ord[u] <= low[v] or 根の次数>1
    vector<int> res;
    if(tree[root].size()>1)res.emplace_back(root);
    for(int u=0;u<n;++u){
      if(u==root)continue;
      for(auto v:tree[u]){
        if(ord[u]<=low[v]){
          res.emplace_back(u);
          break;
        }
      }
    }
    return res;
  }
  vector<pair<int,int>> bridges(){
    // 橋 := 辺uvについて、ord[u]<low[v]
    vector<pair<int,int>> res;
    for(int u=0;u<n;++u){
      for(auto v:tree[u]){
        if(ord[u]<low[v]){
          res.emplace_back(min(u,v),max(u,v));
        }
      }
    }
    sort(res.begin(),res.end());
    return res;
  }
  void dump(){
    cout<<"idx : ";
    for(int i=0;i<n;++i)cout<<i<<(i+1<n?" ":"\n");
    cout<<"ord : ";
    for(int i=0;i<n;++i)cout<<ord[i]<<(i+1<n?" ":"\n");
    cout<<"low : ";
    for(int i=0;i<n;++i)cout<<low[i]<<(i+1<n?" ":"\n");
  }
};

signed main(){

  int n,m;
  cin>>n>>m;
  vector<vector<int>> adj(n);
  for(int i=0;i<m;++i){
    int u,v;cin>>u>>v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  lowlink g(adj,0);
  for(auto ans:g.bridges()){
    cout<<ans.first<<" "<<ans.second<<endl;
  }

}

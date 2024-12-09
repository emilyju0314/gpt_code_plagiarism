#include<bits/stdc++.h>
#define rep(i,n)  for(int i=0;i<(int)(n);i++)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;

inline int encode(int a, int b, int c, int d){
  int res = a;
  res *= 100; res += b;
  res *= 100; res += c;
  res *= 20;  res += d;
  return res;
}

void vis_dfs(int x, vector< vector<pii> > &g, vi &use){
  stack<int> s; s.push(x);
  use[x] = 1;

  while(s.size()){
    int v = s.top(); s.pop();

    for(pii e : g[v]){
      int u = e.second;
      if(!use[u]){
	use[u] = 1;
	s.push(u);
      }
    }
  }
}

int main(){
  cin.tie(0); ios::sync_with_stdio(0);
  int n,m;
  cin >> n >> m;

  vector<string> w(n);
  rep(i,n)cin >> w[i];

  vector< vi > g(n),rg(n);
  rep(i,m){
    int a,b; cin >> a >> b; a--; b--;
    g[a].push_back(b);
    rg[b].push_back(a);
  }

  //construct extended graph
  int s = encode(1,n,0,0), t = s+1, N = t+1;
  vector< vector<pii> > eg(N);
  rep(x,n){
    int X = w[x].size();
    rep(i,X){
      bool f = true;
      rep(j,i+1){
	if(w[x][j] != w[x][i-j])f = false;
      }
      if(f)eg[s].push_back(pii(i+1,encode(0,x,x,i+1)));

      f = true;
      rep(j,i+1){
	if(w[x][X-1-j] != w[x][X-1-i+j])f = false;
      }
      if(f)eg[s].push_back(pii(i+1,encode(1,x,x,i+1)));
    }

    for(int y : g[x]){
      int X = w[x].size(), Y = w[y].size();
      int l = min(X,Y);
      bool f = true;
      rep(i,l){
	if(w[x][X-1-i] != w[y][i])f = false;
      }
      if(f){
	if(X<=Y)eg[s].push_back(pii(2*l,encode(0,x,y,l)));
	else eg[s].push_back(pii(2*l,encode(1,y,x,l)));
      }
    }
  }

  rep(x,n)rep(y,n){
    for(int u : rg[x]){
      rep(i,w[y].size()+1){
	int U = w[u].size(), Y = w[y].size()-i;
	int l = min(U,Y);
	bool f = true;
	rep(k,l){
	  if(w[u][U-1-k] != w[y][i+k])f = false;
	}
	if(f){
	  int cur = encode(0,x,y,i);
	  if(U<=Y)eg[cur].push_back(pii(2*l,encode(0,u,y,i+l)));
	  else eg[cur].push_back(pii(2*l,encode(1,y,u,l)));
	}
      }
    }

    for(int u : g[x]){
      rep(i,w[y].size()+1){
	int U = w[u].size(), Y = w[y].size()-i;
	int l = min(U,Y);
	bool f = true;
	rep(k,l){
	  if(w[u][k] != w[y][Y-1-k])f = false;
	}
	if(f){
	  int cur = encode(1,x,y,i);
	  if(U<=Y)eg[cur].push_back(pii(2*l,encode(1,u,y,i+l)));
	  else eg[cur].push_back(pii(2*l,encode(0,y,u,l)));
	}
      }
    }
  }

  rep(x,n)rep(y,n){
    eg[encode(0,x,y,w[y].size())].push_back(pii(0,t));
    eg[encode(1,x,y,w[y].size())].push_back(pii(0,t));
  }

  vector< vector<pii> > reg(N);
  rep(i,N){
    for(pii e : eg[i]){
      reg[e.second].push_back(pii(e.first,i));
    }
  }
  /*
  cout << "complete to construct extended graph" << endl;

  cout << "s-t: " << s << " " << t << endl;
  rep(i,N){
    for(pii e : eg[i])cout << i << " " << e.second << endl;
  }
  */

  //pruning graph s.t. all vertices are reached from s and reach to t.
  vi vis_s(N,0), vis_t(N,0);
  vis_dfs(s,eg,vis_s); vis_dfs(t,reg,vis_t);

  n = 0;
  map<int,int> re_id;
  rep(i,N){
    if(vis_s[i] && vis_t[i])re_id[i] = n++;
  }

  if(re_id.count(s)==0){
    cout << 0 << endl;
    return 0;
  }

  s = re_id[s]; t = re_id[t]; 

  vector< vector<pii> > mg(n);
  vi deg(n,0);
  rep(i,N){
    if(re_id.count(i) == 0)continue;
    int v = re_id[i];
    for(pii e : eg[i]){
      if(re_id.count(e.second) == 0)continue;
      int u = re_id[e.second];
      mg[v].push_back(pii(e.first,u));
      deg[u]++;
    }
  }

  //cout << "complete to modify graph" << endl;
  /*
  cout << "s-t: " << s << " " << t << endl;
  rep(i,n){
    for(pii e : mg[i])cout << i << " " << e.second << " " << e.first << endl;
  }
  */

  //topological sort
  if(deg[s]!=0){
    cout << -1 << endl;
    return 0;
  }

  queue<int> q; q.push(s);
  vi ord;
  while(q.size()){
    int v = q.front(); q.pop();
    ord.push_back(v);

    for(pii e : mg[v]){
      int u = e.second;
      if(--deg[u] == 0)q.push(u);
    }
  }

  if((int)ord.size()!=n){
    cout << -1 << endl;
    return 0;
  }
  //cout << "complete topological sort" << endl;

  //dynamic programming
  vector<int> dp(n,0);
  rep(i,n){
    int v = ord[i];
    for(pii e : mg[v]){
      int u = e.second;
      dp[u] = max(dp[u], dp[v] + e.first);
    }
  }
  //cout << "complete dp" << endl;

  cout << dp[t] << endl;
}
#include<bits/stdc++.h>
using namespace std;
using Int = long long;

const Int inf = 1LL<<55;

Int n;
Int p[111];
vector<Int> graph[111];

map<Int, Int> mp;

using Pi = pair<Int, Int>;

Pi val[111][222][222];
Int dp_min[111][222][222];
Int dp_max[111][222][222];
bool visited[111][222][222];

Pi dfs(Int v, Int a, Int b) {
  if(visited[v][mp[a]][mp[b]]) return val[v][mp[a]][mp[b]];
  visited[v][mp[a]][mp[b]] = true;  
  if(graph[v].empty()) {
    dp_min[v][mp[a]][mp[b]] = 1;
    dp_max[v][mp[a]][mp[b]] = 1;
    val[v][mp[a]][mp[b]] = Pi(p[v], p[v]);
    //cout<<v<<" "<<val[v][mp[a]][mp[b]].first<<" "<<val[v][mp[a]][mp[b]].second<<endl;
    return val[v][mp[a]][mp[b]];
  }
  val[v][mp[a]][mp[b]] = Pi(-inf, inf);
  dp_min[v][mp[a]][mp[b]] = inf;
  dp_max[v][mp[a]][mp[b]] = -inf;  
  do {
    Pi a_tmp = Pi(a, a), b_tmp = Pi(b, b);
    Int mn = 0, mx = 0;
    bool f_mn = true, f_mx = true;
    for(Int u : graph[v]) {
      if(f_mn) {
	Int x = -dfs(u, -b_tmp.first, -a_tmp.first).first;
	mn += dp_min[u][mp[-b_tmp.first]][mp[-a_tmp.first]];
	if(x >= b_tmp.first) {
	  a_tmp.first = x;
	  f_mn = false;
	} else if(x > a_tmp.first) {
	  a_tmp.first = x;
	}
      }
      if(f_mx) {
	Int x = -dfs(u, -b_tmp.second, -a_tmp.second).second;
	mx += dp_max[u][mp[-b_tmp.second]][mp[-a_tmp.second]];	
	if(x >= b_tmp.second) {
	  a_tmp.second = x;
	  f_mx = false;
	} else if(x > a_tmp.second) {
	  a_tmp.second = x;
	}
      }
    }
    if(dp_min[v][mp[a]][mp[b]] >= mn) {
      dp_min[v][mp[a]][mp[b]] = mn;
      val[v][mp[a]][mp[b]].first = max(val[v][mp[a]][mp[b]].first, a_tmp.first);
    }
    if(dp_max[v][mp[a]][mp[b]] <= mx) {
      dp_max[v][mp[a]][mp[b]] = mx;
      val[v][mp[a]][mp[b]].second = min(val[v][mp[a]][mp[b]].second, a_tmp.second);
    }
  }while(next_permutation(graph[v].begin(), graph[v].end()));
  //cout<<v<<" "<<val[v][mp[a]][mp[b]].first << " " << val[v][mp[a]][mp[b]].second << endl;
  //assert(val[v][mp[a]][mp[b]].first == val[v][mp[a]][mp[b]].second); 
  return val[v][mp[a]][mp[b]];
}

signed main(){  
  cin.tie(0);
  ios::sync_with_stdio(0);

  cin >> n;
  for(Int i = 0; i < n; ++i) cin >> p[i];
  for(Int i = 0; i < n; ++i) {
    Int k; cin >> k;
    for(Int j = 0; j < k; ++j) {
      Int t; cin >> t; --t;
      graph[i].push_back(t);
    }
    sort(graph[i].begin(), graph[i].end());
  }
  vector<Int> vec;
  vec.push_back(-inf);
  vec.push_back(inf);
  for(Int i = 0; i < n; ++i) {
    vec.push_back(p[i]);
    vec.push_back(-p[i]);
  }
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  for(Int i = 0; i < n; ++i) {
    mp[p[i]] = lower_bound(vec.begin(), vec.end(), p[i])-vec.begin();
    mp[-p[i]] = lower_bound(vec.begin(), vec.end(), -p[i])-vec.begin();
  }
  memset(visited, false, sizeof(visited));
  dfs(0, -inf, inf);
  cout << dp_min[0][mp[-inf]][mp[inf]] << " " << dp_max[0][mp[-inf]][mp[inf]] << endl;
  
  return 0;
}


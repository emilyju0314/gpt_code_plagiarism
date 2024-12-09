#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define resz(v, ...) (v).clear(), (v).resize(__VA_ARGS__)
#define reps(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep(i, n) reps(i, 0, n)

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

using Pi = pair<int, int>;
using Ti = tuple<int, int, int>;
using vint = vector<int>;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

struct edge {
  int to, cost;
  edge(){}
  edge(int to, int cost):to(to), cost(cost){}
};
using Graph = vector<vector<edge>>;

int n, m;
Graph graph;
vint s;

vector<int> vec;
int dp[2002];
void dfs(int u, int p) {
  dp[u] = 0;
  int mxch = -1;
  for(edge& e : graph[u]) {
    if(e.to == p) continue;
    dfs(e.to, u);
    if(dp[u] < dp[e.to]+e.cost) {
      mxch = e.to;
      dp[u] = dp[e.to]+e.cost;
    }
  }
  if(mxch == -1) return;
  for(edge& e : graph[u]) {
    if(e.to == p || e.to == mxch) continue;
    vec.push_back(dp[e.to]+e.cost);
  }
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> n >> m;
  graph.resize(n);
  rep(i, n-1) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    graph[a].emplace_back(b, c);
    graph[b].emplace_back(a, c);
  }
  s.resize(n);
  priority_queue<int> que;
  rep(i, n) cin >> s[i];
  rep(i, n) {
    vec.clear();
    dfs(i, -1);
    //cout<<i<<":"<<endl;
    for(int v : vec) {
      que.push(v*s[i]);
      //cout<<v*s[i]<<endl;
    }
    //cout<<dp[i]*s[i]<<endl;
    que.push(dp[i]*s[i]);
  }
  int ans = 0;
  while(!que.empty() && m--) {
    ans += que.top(); que.pop();
  }
  cout << ans << endl;

  return 0;
}
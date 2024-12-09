#include <iostream>
#include <cctype>
#include <cstdlib>
#include <string>
#include <memory.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int,P> PP;
const int INF = 1 << 29;
const int mod = 1000000007;

struct edge{
  int to;
  string s;
  edge(){}
  edge(int to, string s){
    this->to = to;
    this->s = s;
  }
};

bool ok(const string &s1, const string &s2){
  int n = s1.size();
  rep(i, n) if(s1[i] != s2[i]) return false;
  return true;
}


map<string, ll> dp[600][600][2];

vector<edge> G[2][600];


int main(){
  int T;
  cin >> T;
  int n1, m1, n2, m2;
  int a, b;
  string s, nxt;
  edge e;
  rep(t, T){
    cin >> n1 >> m1;
    rep(i, 600)rep(j, 2) G[j][i].clear();
    rep(i, 600)rep(j, 600)rep(k, 2) dp[i][j][k].clear(); 
    rep(i, m1){
      cin  >> a >> b >> s;
      G[0][a].push_back(edge(b, s));
    }
    cin >> n2 >> m2;
    rep(i, m2){
      cin >> a >> b >> s;
      G[1][a].push_back(edge(b, s));
    }
    dp[0][0][0][""] = 1;
    rep(i, n1)rep(j, n2){
      rep(k, 2){
	for(map<string, ll>::iterator iter = dp[i][j][k].begin(); 
	    iter != dp[i][j][k].end(); iter++){
	  string s = (*iter).first;
	  ll d = (*iter).second;
	  if(k == 1){
	    rep(v, (int)G[k][j].size()){
	      e = G[k][j][v];
	      if(e.s.size() < s.size() && ok(e.s, s)){
		nxt = string(s.begin() + e.s.size(), s.end());
		dp[i][e.to][1][nxt] = (dp[i][e.to][1][nxt] + d) % mod;
	      }
	      if(e.s.size() >= s.size() && ok(s, e.s)){
		nxt = string(e.s.begin() + s.size(), e.s.end());
		dp[i][e.to][0][nxt] = (dp[i][e.to][0][nxt] + d) % mod;
	      }
	    }
	  }else{
	    rep(v, (int)G[k][i].size()){ 
	      e = G[k][i][v];
	      if(e.s.size() <= s.size() && ok(e.s, s)){
		nxt = string(s.begin() + e.s.size(), s.end());
		dp[e.to][j][0][nxt] = (dp[e.to][j][0][nxt] + d) % mod;
	      }
	      if(e.s.size() > s.size() && ok(s, e.s)){
		nxt = string(e.s.begin() + s.size(), e.s.end());
		dp[e.to][j][1][nxt] = (dp[e.to][j][1][nxt] + d) % mod;
	      }
	    }
	  }
	}
      }
    }

    cout << dp[n1-1][n2-1][0][""] << endl;
  }
  return 0;
}
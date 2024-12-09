#include <iostream>
#include <cmath>
#include <map>

using namespace std;

#define fi first
#define se second

typedef pair<double, double> P;
int N;
P h, d, cs[20];

#define SQ(x) ((x)*(x))

inline double getDist(P a, P b) {
  return sqrt(SQ(a.fi-b.fi) + SQ(a.se-b.se));
}

double dist[22][22];

map<int, double> mp;

bool dfs(int S, int now, double cost) {
  
  if(S == (1<<N)-1) {
    return true;
  }
  
  for(int i=0; i<N; i++) {
    if(S >> i & 1) continue;
    if(dist[i][N+1] <= cost + dist[now][i]) return false;
  }
  
  for(int i=0; i<N; i++) {
    if(S >> i & 1) continue;
    if(mp.count(S+(1<<i)) && mp[S+(1<<i)] <= cost+dist[now][i]) continue;
    mp[S+(1<<i)] = cost+dist[now][i];
    if(dfs(S+(1<<i), i, cost+dist[now][i])) return true;
  }
  
  return false;
}

bool solve() {
  
  mp.clear();
  
  for(int i=0; i<N; i++) {
    for(int j=i+1; j<N; j++) {
      dist[i][j] = dist[j][i] = getDist(cs[i], cs[j]);
    }
    dist[i][N] = dist[N][i] = getDist(cs[i], h);
    dist[i][N+1] = dist[N+1][i] = getDist(cs[i], d);
  }
  
  for(int i=0; i<N; i++) {
    if(dist[i][N+1] <= dist[i][N]) continue;
    if(dfs(1<<i, i, dist[N][i])) return true;
  }
  return false;
}

int main() {
  
  while(cin >> N >> h.fi >> h.se >> d.fi >> d.se && (N)) {
    for(int i=0; i<N; i++) {
      cin >> cs[i].fi >> cs[i].se;
    }
    
    cout << (solve() ? "YES" : "NO") << endl;
  }
  
  return 0;
}
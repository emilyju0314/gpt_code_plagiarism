#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<deque>
#include<climits>
#include<cassert>
#include<cstring>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)

using namespace std;

struct Edge { int dst, w; };
struct Data {
  int cur, w;
  bool operator < ( const Data &data ) const {
    if( w != data.w ) return w > data.w;
    return cur < data.cur;
  }
};

#define MAX_V 2000

int V,E;
vector<Edge> G[MAX_V];
int mini[MAX_V][MAX_V];

void dijkstra(int sp) {
  rep(i,V) mini[sp][i] = INT_MAX;
  mini[sp][sp] = 0;
  priority_queue<Data> Q;
  Q.push((Data){sp,0});
  while( !Q.empty() ) {
    Data data = Q.top(); Q.pop();
    int cur = data.cur;
    rep(i,(int)G[cur].size()) {
      Edge &e = G[cur][i];
      if( mini[sp][e.dst] > data.w + e.w ) {
	mini[sp][e.dst] = data.w + e.w;
	Q.push((Data){e.dst,mini[sp][e.dst]});
      }
    }
  }
}

typedef pair<int,int> ii;
bool used[MAX_V];
void compute() {
  rep(i,V) dijkstra(i);
  int maxi = 0;
  rep(i,V) REP(j,i+1,V) maxi = max(maxi,mini[i][j]);
  vector<ii> vec;
  rep(i,V) REP(j,i+1,V) {
    if( maxi == mini[i][j] ) {
      vec.push_back(ii(i,j));
      used[i] = used[j] = true;
    }
  }
  rep(i,V) if( !used[i] ) {
    rep(j,(int)vec.size()) {
      int s = vec[j].first, t = vec[j].second;
      if( mini[s][i] + mini[i][t] == maxi ) {
	used[i] = true;
	break;
      }
    }
  }
  int answer = 0;
  rep(i,V) answer += !used[i];
  cout << answer << endl;
  rep(i,V) if( !used[i] ) cout << i + 1 << endl;

}

int main() {
  cin >> V >> E;
  rep(i,E) {
    int s,t,d;
    cin >> s >> t >> d;
    --s, --t;
    G[s].push_back((Edge){t,d});
    G[t].push_back((Edge){s,d});
  }
  compute();
  return 0;
}
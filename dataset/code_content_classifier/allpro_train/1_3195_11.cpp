#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
struct Edge{
  int src, dst, cost, type;
  Edge(int s, int d, int c, int t):
    src(s), dst(d), cost(c), type(t) {}
  bool operator < (const Edge& e) const {
    if(cost != e.cost) return cost > e.cost;
    return type > e.type;
  }
};
typedef vector<Edge> Node;
typedef vector<Node> Graph;

int main(){
  int N;
  while(cin >> N && N){
    int S, T; cin >> S >> T;
    S--; T--;
    int M;
    cin >> M;
    Graph G(N);
    REP(i, M){
      int A, B;
      cin >> A >> B;
      A--; B--;
      G[A].push_back(Edge(A, B, 1, -1));
      G[B].push_back(Edge(B, A, 1, i));
    }
    Edge start(-1, S, 0, -1);
    priority_queue<Edge> que;
    bool used[1000][1001] = {};
    que.push(start);
    while(!que.empty()){
      Edge s = que.top(); que.pop();
      //printf("%d %d %d\n", s.dst, s.cost, s.type);
      if(s.dst == T){
        cout << s.cost << " " << s.type + 1 << endl;
        break;
      }
      FORIT(e, G[s.dst]){
        Edge next(e->src, e->dst, s.cost + e->cost, e->type);
        //printf("-> %d %d %d\n", next.dst, next.cost, next.type);
        if(next.type != -1 && s.type != -1) continue;
        if(next.type == -1) next.type = s.type;
        if(!used[next.dst][next.type + 1]){
          used[next.dst][next.type + 1] = true;
          que.push(next);
        }
      }
    }
  }
  return 0;
}
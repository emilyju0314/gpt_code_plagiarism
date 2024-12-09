//include
//------------------------------------------
#include <tuple>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <queue>

using namespace std;

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int INF = 1e9;


int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

struct Edge{
  int to, cost;

  Edge(int t, int c): to(t), cost(c)
  {}
  bool operator>(const Edge& rhs) const{
	return cost > rhs.cost;
  }
};
typedef vector< vector<Edge> > Graph;

int H, W, A;
int idx(int x, int y, int dir, int a1, int a2){
  return (((y *W + x) * 4 + dir) * (A+1) + a1) * (A+1) + a2;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> H >> W >> A;
  VS vs(H); REP(i,H) cin >> vs[i];
  int sy, sx, gy, gx;
  REP(y,H) REP(x,W)
	if(vs[y][x] == 'S') sy = y, sx = x;
	else if(vs[y][x] == 'G') gy = y, gx = x;

  // (num,x,y,dir,a1,a2)
  priority_queue<tuple<int,int,int,int,int,int>, vector<tuple<int,int,int,int,int,int> >, greater<tuple<int,int,int,int,int,int> > > pq;
  VI dist(idx(W,H,4,A+1,A+1)+1, INF);

  if(sy + 1 < H && vs[sy+1][sx] != '#'){
	pq.push(make_tuple(0,sx,sy+1,2,0,0));
	dist[idx(sx,sy+1,2,0,0)] = 0;
  }
    
  while(!pq.empty()){
	int num, x, y, d, a1, a2;
	tie(num,x,y,d,a1,a2) = pq.top(); pq.pop();
	if(x == gx && y == gy) break;
	int fr = idx(x,y,d,a1,a2);
	if(dist[fr] < num) continue;

	// ??????????????¨???
	if(vs[y][x] == '.'){
	  // /?????¢
	  if(a1 < A){
		int td = 3 - d;
		int tx = x + dx[td], ty = y + dy[td];
		if(!(tx < 0 || W <= tx || ty < 0 || H <= ty || vs[ty][tx] == '#' || (tx == sx && ty >= sy && td == 0))){
		  int toid = idx(tx,ty,td,a1+1,a2);
		  if(dist[toid] > num+1){
			dist[toid] = num+1;
			pq.push(make_tuple(num+1,tx,ty,td,a1+1,a2));
		  }
		}
	  }
	  // \?????¢
	  if(a2 < A){
		int td = d-(d%2*2-1);
		int tx = x + dx[td], ty = y + dy[td];
		if(!(tx < 0 || W <= tx || ty < 0 || H <= ty || vs[ty][tx] == '#' || (tx == sx && ty >= sy && td == 0))){
		  int toid = idx(tx,ty,td,a1,a2+1);
		  if(dist[toid] > num+1){
			dist[toid] = num+1;
			pq.push(make_tuple(num+1,tx,ty,td,a1,a2+1));
		  }
		}
	  }
	}

	//??´???
	int tx = x + dx[d], ty = y + dy[d];
	if(tx < 0 || W <= tx || ty < 0 || H <= ty
	   || vs[ty][tx] == '#') continue;
	int toid = idx(tx,ty,d,a1,a2);
	if(dist[toid] > num){
	  dist[toid] = num;
	  pq.push(make_tuple(num,tx,ty,d,a1,a2));
	}
  }

  int ans = INF;
  REP(d,4) REP(a1,A+1) REP(a2,A+1){
	int tid = idx(gx,gy,d,a1,a2);
	ans = min(ans, dist[tid]);
  }
  
  cout << (ans >= INF? -1: ans) << endl;
  return 0;
}
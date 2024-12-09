//include
//------------------------------------------
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
const int INF = 1e8;

void compress(VI& xs, map<int,int>& comp, VI& decomp){
  int MX = 0;
  REP(i,SZ(xs))
	if(!comp.count(xs[i])){
	  comp[xs[i]] = MX++;
	  decomp[MX-1] = xs[i];
	}
}

void dfs(int x, int y, vector<vector<LL>>& reg, int W, int H, LL fr){
  if(x < 0 || y < 0 || W <= x || H <= y || reg[y][x] != fr) return;
  reg[y][x] = -1;
  dfs(x+1,y,reg,W,H,fr);
  dfs(x,y+1,reg,W,H,fr);
  dfs(x-1,y,reg,W,H,fr);
  dfs(x,y-1,reg,W,H,fr);
}


int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  while(cin>>N,N){
	vector<PII> lt(N), rb(N);
	VI xs, ys;
	REP(i,N){
	  cin >> lt[i].first >> rb[i].second >> rb[i].first >> lt[i].second;
	  xs.PB(lt[i].first); xs.PB(rb[i].first);
	  ys.PB(lt[i].second); ys.PB(rb[i].second);
	}
	xs.PB(-1); xs.PB(INF);
	ys.PB(-1); ys.PB(INF);
	SORT(xs); xs.erase(unique(ALL(xs)), xs.end());
	SORT(ys); ys.erase(unique(ALL(ys)), ys.end());

	map<int,int> compX, compY;
	VI decompX(SZ(xs)), decompY(SZ(ys));
	compress(xs, compX, decompX);
	compress(ys, compY, decompY);

	REP(i,N){
	  lt[i].first = compX[lt[i].first];
	  rb[i].first = compX[rb[i].first];
	  lt[i].second = compY[lt[i].second];
	  rb[i].second = compY[rb[i].second];
	}

	int H = SZ(ys), W = SZ(xs);
	vector<vector<LL>> reg(H, vector<LL>(W, 0));
	REP(y,H) REP(x,W){
	  REP(i,N){
		if(lt[i].first <= x && x < rb[i].first
		   && lt[i].second <= y && y < rb[i].second)
		  reg[y][x] |= 1LL<<i;
	  }
	}

	int ans = 0;
	REP(y,H) REP(x,W){
	  if(reg[y][x] >= 0){
		dfs(x,y,reg,W,H,reg[y][x]);
		++ans;
	  }
	}
	cout << ans << endl;
  }

  return 0;
}
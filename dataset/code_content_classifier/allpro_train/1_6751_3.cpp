#include <bits/stdc++.h>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using PII = pair<int, int>;
using LL = long long;
using VL = vector<LL>;
using VVL = vector<VL>;
using PLL = pair<LL, LL>;
using VS = vector<string>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}
template<class S, class T>
ostream& operator<<(ostream& os, const pair<S,T>& p){
  return os << p.FF << " " << p.SS;
}
template<class T>
void maxi(T& x, T y){
  if(x < y) x = y;
}
template<class T>
void mini(T& x, T y){
  if(x > y) x = y;
}


const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;

int H, W, N;
PII xs[18][500][500];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> H >> W >> N;
  REP(y,H) REP(x,W)
	cin >> xs[0][y][x];

  vector<PII> ps(N);
  REP(i,N) cin >> ps[i];

  for(int i=1;i<18;++i){
	REP(y,H) REP(x,W){
	  auto&& par = xs[i-1][y][x];
	  xs[i][y][x] = xs[i-1][par.FF][par.SS];
	}
  }

  bool no = true;
  set<PII> s;
  for(auto&& p: ps){
	PII np = xs[17][p.FF][p.SS];
	if(s.count(np)){
	  no = false;
	}
	s.insert(np);
  }
  if(no){
	cout << -1 << endl;
	return 0;
  }

  int ans = 0;
  vector<vector<PII>> db(H, vector<PII>(W));
  REP(y,H) REP(x,W) db[y][x] = MP(y,x);
  for(int i=17;i>=0;--i){
	bool excess = false;
	set<PII> s;
	for(auto&& p: ps){
	  PII np = db[p.FF][p.SS];
	  np = xs[i][np.FF][np.SS];
	  if(s.count(np)){
		excess = true;
		break;
	  }
	  s.insert(np);
	}
	if(!excess){
	  ans |= 1<<i;
	  REP(y,H) REP(x,W){
		PII p = db[y][x];
		db[y][x] = xs[i][p.FF][p.SS];
	  }
	}
  }
  cout << ans+1 << endl;

  return 0;
}
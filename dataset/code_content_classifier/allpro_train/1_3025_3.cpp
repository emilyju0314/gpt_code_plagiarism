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
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))

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

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<PII> xs(N);
  REP(i,N){
	char c;
	cin >> c >> xs[i].FF;
	xs[i].SS = c == 'y';
  }

  function<int(int,int,int)> dfs = [&](int l, int r, int ub){
	if(l >= r) return 0;
	int res = 0;
	int h = -1, k = -1, n = 0, m = 0;
	for(int i=l;i<r;++i){
	  if(xs[i].FF >= ub) continue;
	  if(xs[i].SS == 0){
		++n;
		if(h < xs[i].FF){
		  h = xs[i].FF;
		  k = i;
		}
	  }
	  else ++m;
	}
	if(n == 0 || m == 0){
	  return m? 1: 0;
	}

	int lg = 0, rg = 0;
	FOR(i,l,k){
	  if(xs[i].SS && h < xs[i].FF && xs[i].FF < ub){
		++lg;
		break;
	  }
	}
	FOR(i,k+1,r){
	  if(xs[i].SS && h < xs[i].FF && xs[i].FF < ub){
		++rg;
		break;
	  }
	}
	if(lg && rg){
	  res += min(dfs(l, k, h+1) + dfs(k+1, r, h+1) + 1,
				 dfs(l, k, ub) + dfs(k+1, r, ub));
	}
	else{
	  res += dfs(l, k, ub) + dfs(k+1, r, ub);
	}

	return res;
  };

  cout << dfs(0, N, 1e9) << endl;

  return 0;
}
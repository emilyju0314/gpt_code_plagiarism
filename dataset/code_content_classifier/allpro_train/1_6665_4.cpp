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
const LL INF = 1e18;

class SegT{
private:
  VL dat[2 * (1 << 17) - 1]; // = 131072
  int NN;

  void merge(VL& dst, const VL& s1, const VL& s2){
	for(int i1=0,i2=0;i1<SZ(s1)||i2<SZ(s2);){
	  if(i1 == SZ(s1)){
		dst.push_back(s2[i2++]);
	  }
	  else if(i2 == SZ(s2)){
		dst.push_back(s1[i1++]);
	  }
	  else{
		if(s1[i1] < s2[i2])
		  dst.push_back(s1[i1++]);
		else
		  dst.push_back(s2[i2++]);
	  }
	}
  }
  
public:
  SegT(int n_, VVL& xs){
	NN = 1;
	while(NN < n_) NN <<= 1;
	for(int i=0;i<n_;++i){
	  dat[NN-1+i] = xs[i];
	  SORT(dat[NN-1+i]);
	}
	for(int i=NN-2;i>=0;--i){
	  merge(dat[i], dat[i*2+1], dat[i*2+2]);
	}
  }

  bool query(int a, int b, LL lb, LL ub, int k, int l, int r){
	if(r <= a || b <= l) return false;

	if(a <= l && r <= b){
	  auto it = lower_bound(ALL(dat[k]), lb);
	  return it != end(dat[k]) && *it <= ub;
	}
	else{
	  if(query(a, b, lb, ub, k*2+1, l, (l+r)/2))
		return true;
	  return query(a, b, lb, ub, k*2+2, (l+r)/2, r);
	}
  }
  int query(int a, int b, LL lb, LL ub){
	return query(a, b, lb, ub, 0, 0, NN);
  }
};


LL N, A, B;
vector<PLL> xs[5];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> A >> B;
  REP(i,N){
	LL t, a, b;
	cin >> t >> a >> b;
	xs[t-1].EB(a,b);
  }
  
  set<PLL> S, T, tmp;
  S.insert(MP(0,0));
  REP(i,3){
	tmp = S;
	for(auto&& p: S)
	  for(auto&& x: xs[i]){
		tmp.insert(MP(x.FF+p.FF, x.SS+p.SS));
	  }
	S = tmp;
  }
  T.insert(MP(0,0));
  FOR(i,3,5){
	tmp = T;
	for(auto&& p: T)
	  for(auto&& x: xs[i]){
		tmp.insert(MP(x.FF+p.FF, x.SS+p.SS));
	  }
	T = tmp;
  }
  tmp.clear();

  vector<LL> xx;
  for(auto&& p: T)
	xx.PB(p.FF);
  xx.PB(-INF);
  xx.PB(INF);
  SORT(xx);
  xx.erase(unique(ALL(xx)), end(xx));

  int M = SZ(xx);
  map<LL,int> idx;
  REP(i,M) idx[xx[i]] = i;
  
  VVL dat(M);
  for(auto&& p: T)
	dat[idx[p.FF]].PB(p.SS);

  SegT seg(M, dat);
  for(auto&& p: S){
	int lx = idx.lower_bound(A-p.FF)->SS;
	int rx = idx.upper_bound(B-p.FF)->SS;
	if(seg.query(lx, rx, A-p.SS, B-p.SS)){
	  cout << "Yes" << endl;
	  return 0;
	}
  }
  cout << "No" << endl;

  return 0;
}
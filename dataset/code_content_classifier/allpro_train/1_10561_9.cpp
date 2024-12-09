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

double prob[3][2010][4];
double C[2010][2010];
double acc[2010];

int main(){
	  
  int N, M; cin >> N >> M;
  VVI xs(N, VI(3));
  REP(i,N) REP(j,3) cin >> xs[i][j];

  C[0][0] = 1.;
  FOR(i,1,2010){
	C[i][0] = C[i-1][0] * 2. / 3;
	C[i][i] = C[i-1][i-1] / 3.;
	FOR(j,1,i)
	  C[i][j] = C[i-1][j] * 2./3 + C[i-1][j-1] /3.;
  }
  acc[0] = C[M][0];
  FOR(i,1,M+1){
	acc[i] = acc[i-1] + C[M][i];
  }

  REP(t,3){
	REP(i,M+1){
	  int x = xs[0][t] * i;
	  prob[t][i][0] = prob[t][i][3] = 1.;
	  FOR(j,1,N){
		int l = min((x-1) / xs[j][t], M);
		double w = 0.;
		if(l * xs[j][t] < x){
		  w = acc[l];
		}
		vector<double> np(3);
		REP(k,3) np[k] = prob[t][i][k] * w;
		REP(k,2) np[k+1] += prob[t][i][k] * (1.-w);
		REP(k,3) prob[t][i][k] = np[k];
		prob[t][i][3] *= 1. - w;
	  }
	  prob[t][i][0] = prob[t][i][0] + prob[t][i][1] + prob[t][i][2];
	}
  }

  double ans = -100;
  REP(i,M+1) REP(j,M-i+1){
	int k = M - i - j;
	maxi(ans, prob[0][i][0] * 5 + prob[1][j][0] * 3 + prob[2][k][0] * 2
		 - prob[0][i][3] - prob[1][j][3] - prob[2][k][3]);
  }
  cout << fixed << setprecision(9) << ans << endl;

  return 0;
}
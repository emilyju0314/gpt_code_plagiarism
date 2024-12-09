#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef pair<LL, LL> PLL;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;

int N;
LL dfs(int& i, int lv, VS& vs){
  if(vs[i][lv] == '+'){
	LL res = 0;
	++i;
	while(i<N && SZ(vs[i]) > lv && vs[i][lv] == '.')
	  res += dfs(i, lv+1, vs);
	return res;
  }
  else if(vs[i][lv] == '*'){
	LL res = 1;
	++i;
	while(i<N && SZ(vs[i]) > lv && vs[i][lv] == '.')
	  res *= dfs(i, lv+1, vs);
	return res;
  }

  return vs[i++][lv] - '0';
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  while(cin>>N,N){
	VS str(N);
	REP(i,N) cin >> str[i];
	int i = 0;
	cout << dfs(i, 0, str) << endl;
  }
  
  return 0;
}
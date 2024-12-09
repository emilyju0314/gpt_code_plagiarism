#include <bits/stdc++.h>

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

LL A, B, P;

int dig(LL x){
  int res = 0;
  while(x > 0) x /= 10, ++res;
  return res;
}

LL f(LL x){
  int d = dig(x);
  LL res = 1;
  while(d>0) res *= 10, --d;
  return res;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  while(cin>>A>>B>>P,A){
	LL D = B - A;
	LL dp[100010][2];
	fill((LL*)dp, (LL*)dp+100010*2, 0);
	dp[D][0] = 1;
	dp[D][1] = 1;
	for(int i=D-1;i>=0;--i){
	  LL x = A + i;
	  dp[i][0] = 1;
	  if(dig(x) == dig(x+1))
		dp[i][0] = (dp[i][0] + dp[i+1][1]) % P;

	  for(LL tmp=x*10;tmp<=B;tmp*=10){
		dp[i][0] += dp[tmp-A][1];
		dp[i][0] %= P;
	  }
	  if(dig(x) == dig(x+1))
		dp[i][1] = (dp[i][0] + dp[i+1][1]) % P;
	  else
		dp[i][1] = dp[i][0];
	}
	LL ans = 0;
	REP(i,D+1) ans = (ans + dp[i][0]) % P;
	cout << ans << endl;
  }
  
  
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG_MODE
	#define DBG(n) n;
#else
	#define DBG(n) ;
#endif
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define rep(i,s,g) for(ll (i) = (s);(i) < (g);++i)
#define rrep(i,s,g) for(ll (i) = (s);i >= (g);--(i))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

int n,m;
double v[22][22];
double dp[1<<16][22];

double dfs(int state,int num){
	
	if(dp[state][num] != -1)return dp[state][num];
	double ret = 0;
	
	REP(i,n){
		if(!(state & (1<<i))){
			double tmp = 0;
			double p = 1;
			for(int k = num;k < m;k++){
				tmp += p * (1 - v[i][k]) * dfs(state|(1<<i),k);
				p *= v[i][k];
			}
			ret = max(ret,tmp+p);
		}
	}
			
	return dp[state][num] = ret;
}

int main(){
	
	cin >> n >> m;
	
	REP(i,1<<16)REP(j,22)dp[i][j] = -1;
		
	REP(i,n){
		REP(j,m){
			cin >> v[i][j];
		}
	}
	
	cout << Decimal << dfs(0,0) << endl;
	
	return 0;
}

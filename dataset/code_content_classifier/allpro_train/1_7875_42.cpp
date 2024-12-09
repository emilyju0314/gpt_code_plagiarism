#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <map>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ROF(i,b,a) for(int i=(b-1);i>=(a);--i)
#define REP(i,n)  FOR(i,0,n)
#define INT(a) int((a)+1e-9)
#define SUPbl 1002
#define SUPrt 1002
#define SUPut 1002


int bl;
bool dp[SUPrt];	//dp[t] = rs no bubun syuugou no wa de t ga tukureru ka
int rs[SUPbl];
int us[SUPbl];
int sumr, sumu;
int maxr, maxu;
int T;

int solve(){
	sumr=0; sumu=0; maxr=0; maxu=0;
	REP(bi,bl){ sumr+=rs[bi]; sumu+=us[bi]; maxr=max(maxr,rs[bi]); maxu=max(maxu,us[bi]);}
	T=maxr*2-sumr;
	if(T<=0){
		return sumr+sumu;
	}else{
		FOR(t,0,T+1) dp[t]=false;
		dp[0]=true;
		FOR(bi,0,bl){
			if(rs[bi]==maxr) continue;
			ROF(t,T+1,0){
				if(t>=us[bi]) dp[t] = dp[t] || dp[t-us[bi]];
			}
		}
		int t=T;
		for(;t>=0;--t){
			if(dp[t]) break;
		}
		return sumr+sumu+(T-t);
	}

}

int main(){
	while(true){
		cin >> bl;			if(!bl) return 0;
		REP(bi,bl) cin>>rs[bi]>>us[bi];
		cout<<solve()<<endl;
	}
}
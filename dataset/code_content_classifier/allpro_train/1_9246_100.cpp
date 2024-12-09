#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_N=1e5,MAX_D=1e3;
int N,D;
int zip[MAX_D][MAX_D],psm[2][MAX_D*2+1][MAX_D*2+1];
bool C(int b){
	bool ans=false;
	REP(i,D){
		REP(j,D){
			if (psm[0][D+i][D+j]-psm[0][D+i][b+1+j]-psm[0][b+1+i][D+j]+psm[0][b+1+i][b+1+j]==0
			&& psm[1][D+i][b+1+j]-psm[1][D+i][j]-psm[1][b+1+i][b+1+j]+psm[1][b+1+i][j]==0
			&& psm[1][b+1+i][D+j]-psm[1][i][D+j]-psm[1][b+1+i][b+1+j]+psm[1][i][b+1+j]==0){
				ans=true;
			}
		}
	}
	return ans;
}
int main(){
	cin>>N>>D;
	REP(i,N){
		int x,y;
		cin>>x>>y;
		zip[x%D][y%D]++;
	}
	int a;
	{
		int mx=0;
		REP(i,D){
			REP(j,D){
				mx=max(mx,zip[i][j]);
			}
		}
		a=0;
		while(mx>(a+1)*(a+1)){
			a++;
		}
	}
	REP(i,D){
		REP(j,D){
			if (zip[i][j]>a*a){
				REP(s,2)REP(t,2){
					psm[0][i+1+D*s][j+1+D*t]++;
				}
			}
			if (zip[i][j]>a*(a+1)){
				REP(s,2)REP(t,2){
					psm[1][i+1+D*s][j+1+D*t]++;
				}
			}
		}
	}
	REP(i,D*2)REP(j,D*2){
		REP(k,2){
			psm[k][i+1][j+1]+=psm[k][i+1][j]+psm[k][i][j+1]-psm[k][i][j];
		}
	}
	int lb=-1,ub=D-1;
	while(ub-lb>1){
		int m=(lb+ub)/2;
		if (C(m)){
			ub=m;
		}else{
			lb=m;
		}
	}
	cout<<a*D+ub<<endl;
}
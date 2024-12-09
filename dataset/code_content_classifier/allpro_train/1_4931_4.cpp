#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <math.h>
#include <stack>
using namespace std;
typedef long long ll;

int n,m;
int a[14];
double p[14][3];
double dp[1<<14];
double pp[1<<13][6];
int ma[1<<13];

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cin >> n >> m; n--;
	for(int i=0;i<n;i++){
		cin >> a[i];
		cin >> p[i][0] >> p[i][1] >> p[i][2];
		p[i][0]/=100,p[i][1]/=100,p[i][2]/=100;
	}
	dp[0]=1;
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<3;j++){
			double res=1;
			for(int k=0;k<n;k++){
				if((1<<k)&i){
					res*=p[k][j];
				}
			}
			pp[i][j]=res;
		}
		for(int j=0;j<3;j++){
			double res=1;
			for(int k=0;k<n;k++){
				if((1<<k)&i){
					res*=(1-p[k][j]);
				}
			}
			pp[i][j+3]=res;
		}
	}
	for(int i=0;i<(1<<n);i++){
		int res=0;
		for(int j=0;j<n;j++){
			if((i>>j)&1){
				res=max(res,a[j]);
			}
		}
		ma[i]=res;
	}
	for(int s=1;s<(1<<n);s++){
		double rrr=0,sss=0,ppp=0;
		for(int t=0;t<s;t++){
			if((s&t)==t){
				double winr,wins,winp;
				winr=pp[s-t][2]*pp[t][0];
				winp=pp[s-t][0]*pp[t][1];
				wins=pp[s-t][1]*pp[t][2];
				rrr+=dp[t]*winr;
				sss+=dp[t]*wins;
				ppp+=dp[t]*winp;
			}
		}
		double drowr,drows,drowp;
		drowp=(1-(pp[s][5]+pp[s][3]-pp[s][1]*2));
		drows=(1-(pp[s][4]+pp[s][3]-pp[s][2]*2));
		drowr=(1-(pp[s][5]+pp[s][4]-pp[s][0]*2));
		if(ma[s]<m){
			rrr+=drowr;
			ppp+=drowp;
			sss+=drows;
		}
		dp[s]+=max({rrr,sss,ppp});
	}
	printf("%.9f\n",dp[(1<<n)-1] );
}

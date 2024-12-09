#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <iomanip>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

double dp[1<<15];

int main(){
	int n,m;
	double p;
	cin >> n >> m >> p;
	vector<pair<int,int> >g;
	p /=100.0;
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		g.PB(MP(a,b));
	}
	for(int i=0;i<n;i++){
		dp[1<<i]=1.0;
	}
	for(int i=1;i<(1<<n);i++){
		dp[i]=1.0;
		for(int S=(1<<n)-1;S>=0;S--){
			double tmp = 1.0;
			S &= i;
			int T = i-S;
			if(S<T)break;
			if(S==0||T==0)continue;
			for(int j=0;j<m;j++){
				if(S>>g[j].first&1&&T>>g[j].second&1){
					tmp*=p;
				}
				if(T>>g[j].first&1&&S>>g[j].second&1){
					tmp*=p;
				}
			}
			dp[i] -= dp[S]*tmp;
		}
	}
	cout << fixed << setprecision(20) << dp[(1<<n)-1] << endl;
	return 0;
}

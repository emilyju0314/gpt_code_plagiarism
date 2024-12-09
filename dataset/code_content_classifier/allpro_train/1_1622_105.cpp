#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=2e5+23;

int n;

int cnt[100][100];

int main(){
	cin>>n;
	ll ans=0;
	for(int i=0;i<n;i++){
		double xx;
		scanf("%lf",&xx);
		xx*=1e9;
		ll a=xx+0.5;
		int _2=0,_5=0;
		while(1){
			if(a%2==0){
				a/=2;
				_2++;
			}
			else if(a%5==0){
				a/=5;
				_5++;
			}
			else break;
		}
		int x=max(0,18-_2);
		int y=max(0,18-_5);
		ans+=cnt[x][y];
		for(int i=0;i<=_2;i++){
			for(int j=0;j<=_5;j++) cnt[i][j]++;
		}
		// printf("%.3f %d %d\n",xx,_2,_5);
	}
	printf("%lld",ans);
}
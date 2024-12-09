#include<bits/stdc++.h>
using namespace std;

int n;
long double prob[3002];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	prob[0] = 1;
	cin>>n;
	for(int i=1;i<=n;i++){
		long double p;
		cin>>p;
		for(int j=n;j>0;j--){
			prob[j] = prob[j]*(1-p) + prob[j-1]*p;
		}
		prob[0] *= (1-p);
	}
	long double ans = 0.0;
	for(int i=n/2+1;i<=n;i++){
		ans += prob[i];
	}
	cout<<setprecision(12);
	cout<<ans;
	return 0;
}

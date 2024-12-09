#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  ll long long
#define size 200020
using namespace std;
ll a[size],q[size];
ll dp[size];
double slope(int j,int k) {
	double y=dp[j]+a[j]*a[j]-dp[k]-a[k]*a[k];
	double x=a[j]-a[k];
	return y/x;
}
int main()
{
	int n;
	ll c;
	while(cin>>n>>c){
		for(int i=1;i<=n;i++)
			cin>>a[i];
		dp[0]=0;
		int head=1,tail=1;
		q[head]=1;
		for(int i=2;i<=n;i++){
			while(head<tail&&slope(q[head],q[head+1])<=2*a[i]) head++;
			int j=q[head];
			dp[i]=dp[j]+c+(a[i]-a[j])*(a[i]-a[j]);
			while(head<tail&&slope(q[tail-1],q[tail])>=slope(q[tail],i)) tail--;
			q[++tail]=i;
//			cout<<dp[i]<<endl;
		}
		cout<<dp[n]<<endl;
	}
}



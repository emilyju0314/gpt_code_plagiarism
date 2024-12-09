#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<string> 
using namespace std;
const int maxn=100007;
long long n,m,v,p,ans;
long long a[maxn],sum[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>v>>p;
	ans=p;
	for (long long i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (long long i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];
	for (long long i=1; i<=n-p; i++)  
		if (a[i]+m>=a[n-p+1]) 
		if ((i+p-1)*m+(a[i]+m)*(n-p+1-i)-(sum[n-p+1]-sum[i])>=v*m) ++ans;
	//	if ((i-1+p-1)*m+a[i]+m-a[n-p+1]>=v*m) ++ans;
	cout<<ans<<endl; 
	return 0;
} 
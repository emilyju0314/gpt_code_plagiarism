#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
int main() {
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+1+n,greater<int>());
	long long ans=a[1] ;
	for(int i=2; i<=n/2; i++)
		ans+=2*a[i] ;
	if (n%2)
		ans+=a[(n+1)/2];
	cout<<ans<<endl;
	return 0;
}
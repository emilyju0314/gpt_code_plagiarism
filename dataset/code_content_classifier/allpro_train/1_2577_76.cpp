#include <bits/stdc++.h>
using namespace std;
long long a[105],b[105];
int main()
{
	long long n,sum=1e9;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
		sum=min(sum,abs(b[i]-(b[n]-b[i])));
	cout<<sum;

	return 0;
}
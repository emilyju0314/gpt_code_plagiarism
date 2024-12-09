#include <bits/stdc++.h>
using namespace std;

long long f[55];
int n;

int main()
{
	f[0] = 2;
	cin>>n;
	for(int i=1;i<=n;++i)
		f[i] = f[i-1]*2+2;
	cout<<f[n]<<endl;
	return 0;
}
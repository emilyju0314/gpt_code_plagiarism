#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin>>n;
	if(n%2==0)
	{
		cout<<n*(n-2)/2<<endl;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(i+j!=n+1)
					cout<<i<<" "<<j<<endl;
	}
	else
	{
		cout<<(n-1)*(n-1)/2<<endl;
		for(int i=1;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(i+j!=n)
					cout<<i<<" "<<j<<endl;
		for(int i=1;i<n;i++)
			cout<<i<<" "<<n<<endl;
	}
	return 0;
}
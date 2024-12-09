#include<bits/stdc++.h>
using namespace std;
long long n,d,l1,l2,ans;
int main()
{
	cin>>n>>d;
	while(n--)
	{
		cin>>l1>>l2;
		if(sqrt(l1*l1+l2*l2)<=d)
		{
			ans++;
		}
	}	
	cout<<ans;
}
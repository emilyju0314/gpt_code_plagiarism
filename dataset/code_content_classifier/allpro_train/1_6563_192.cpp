#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const ll P=1e9+7;

ll n,m,ans=1;

int main()
{
	cin>>n>>m;
	if(m-n>1||n-m>1)
	{
		cout<<0;
		return 0;
	}
	for(ll i=1;i<=n;i++)ans=(i*ans)%P;
	for(ll i=1;i<=m;i++)
		ans=(i*ans)%P;
	if(m-n==0)
	cout<<ans*2ll%P;
	else
	cout<<ans;
}

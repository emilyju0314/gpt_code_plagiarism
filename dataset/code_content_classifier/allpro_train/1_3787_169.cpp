#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int N=600010,mod=1e9+7;
ll n,m,T,k,cnt,x,y,z,indx,t,ans,sum;
int main()
{
	scanf("%lld",&n);
	for (ll i=1;i<=n;i++) ans+=i*(n-i+1);
	for (int i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		if (x>y) swap(x,y);
		sum+=x*(n-y+1);
	}
	printf("%lld\n",ans-sum);
}
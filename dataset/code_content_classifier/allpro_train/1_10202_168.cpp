#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n,k,i,j;long long ans=0;
	scanf("%d%d",&n,&k);
	for(i=k+1;i<=n;++i)for(j=0;j<=n;j+=i)ans+=max(0,min(n+1,j+i)-j-k);
	printf("%lld",ans-(k?0:n));
}
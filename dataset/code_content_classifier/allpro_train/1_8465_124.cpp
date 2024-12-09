#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=25000002;
int n,i,las,f[N],a[4],b[4],j;
signed main(){
	scanf("%lld",&n);
	for (i=1;i<=3;i++) scanf("%lld",&a[i]);
	for (i=1;i<=3;i++) scanf("%lld",&b[i]);
	for (i=1;i<=3;i++) if (a[i]<b[i])
		for (j=0;j<=n;j++)
			if (j>=a[i]) f[j]=max(f[j],f[j-a[i]]+b[i]);
	las=0;
	for (i=1;i<=n;i++)
		if (f[i]>f[las]) las=i;
	n=n-las+f[las];
	memset(f,0,sizeof(f));
	for (i=1;i<=3;i++) if (b[i]<a[i])
		for (j=0;j<=n;j++)
			if (j>=b[i]) f[j]=max(f[j],f[j-b[i]]+a[i]);
	las=0;
	for (i=1;i<=n;i++)
		if (f[i]>f[las]) las=i;
	printf("%lld",n-las+f[las]);
}
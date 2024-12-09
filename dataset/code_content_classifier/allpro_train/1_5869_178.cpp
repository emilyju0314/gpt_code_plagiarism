#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,m,a[N],b[N]; char st[N];
int main()
{
	int i,x,l,r,mid,sum;
	scanf("%s",st+1);
	n = strlen(st+1);
	l=0,r=n;
	for(i=1;i<=n;i++) a[i]=st[i]-'0';
	for(i=1;i<=n/2;i++) swap(a[i],a[n-i+1]);
	for(i=1;i<=n;i++)
		x=a[i]*9+x/10,a[i]=x%10;
	if(x/10) a[++n]=x/10;
	while(r-l>1){
		mid=(l+r)>>1;
		for(i=1;i<=n;i++) b[i]=a[i];
		m=n,x=mid*90,sum=0;
		for(i=1;i<=m;i++)
			x=b[i]+x/10,b[i]=x%10;
		while(x/10) x/=10,b[++m]=x%10;
		for(i=1;i<=m;i++) sum+=b[i];
		if(sum<=9*mid) r=mid;
		else l=mid;
	  }
	cout<<r;
	return 0;
}

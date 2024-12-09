#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
int main(void)
{
	int i,j,p,n,m,a[1000],sum,mi,mx,p2;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)	scanf("%d",&a[i]);
	sum=0;
	p=0;
	while(1)	{
		mi=a[p];	mx=a[p];
		p=(p+1)%n;
		for(i=1;i<m;i++)	{
			mi=min(mi,a[p]);
			mx=max(mx,a[p]);
			p=(p+1)%n;
		}
		sum+=mx-mi;
		if(p==0)	break;
	}
	printf("%d\n",sum);
	return 0;
}

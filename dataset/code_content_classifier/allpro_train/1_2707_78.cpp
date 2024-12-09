#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define N  110000
using  namespace  std;
set<int>  fuck;
int  a[N];
int  T,n,k;
inline  bool  cmp(int  x,int  y){return  x<y;}
int  work()
{
	fuck.clear();
	scanf("%d%d",&n,&k);
	for(int  i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		fuck.insert(a[i]);
	}
	if(!k)return  n;
	sort(a+1,a+n+1,cmp);
	for(int  i=1;i<=n;i++)
	{
		if(a[i]!=i-1)
		{
			int  x=(a[n]+i)/2;
			if(fuck.count(x)==1)return  n;
			return  n+1;
		}
	}
	return  n+k;
}
int  main()
{
	scanf("%d",&T);
	while(T--)printf("%d\n",work());
	return  0;
}
#include<cstdio>

long long a[19]={9,90,900,(long long)9e3,(long long)9e4,(long long)9e5,(long long)9e6,(long long)9e7,(long long)9e8,(long long)9e9,(long long)9e10,(long long)9e11,(long long)9e12,(long long)9e13,(long long)9e14,(long long)9e15,(long long)9e16,(long long)9e17,(long long)9e18};
long long s;
long long dfs(int l,int e,int r,long long d,long long b)
{
	if(l==e&&!d)
		puts("");
	if(l--==e)return(d==0)*(e==r?10:1);
	if(d%a[r]!=0)return 0;
	long long c=0;
	for(int i=-9;i<=(r?9:8);i++)
		if(d-(long long)i*b==d-i*b)
			c+=(i<0?10+i:r?10-i:9-i)*dfs(l,e,r+1,d-i*b,b-a[l]-a[r]);
	return c;
}

int main()
{
	int d,i=1;scanf("%d",&d);
	for(long long b=9;i<20;b=b*10+9,i++)
		s+=dfs(i,i>>1,0,d,b);
	printf("%lld\n",s);
}
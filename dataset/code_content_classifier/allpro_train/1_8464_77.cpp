#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 100012
int n,ans=0,s[N];
struct sec{int l,r;}a[N],ri;
inline bool cmp(sec x,sec y){return (x.l<y.l);}
int main(){
	scanf("%d",&n);int i;for(i=1;i<=n;i++)scanf("%d%d",&a[i].l,&a[i].r);s[0]=1e9;
	sort(a+1,a+n+1,cmp);for(i=1;i<=n;i++)s[i]=min(s[i-1],a[i].r);ri=a[n];
	for(i=n-1;i>=1;i--)
	{
		ans=max(ans,max(max(min(s[i-1],a[i].r)-a[i].l+1,0)+max(ri.r-ri.l+1,0),a[i].r-a[i].l+1+max(min(s[i-1],ri.r)-ri.l+1,0)));
		ri.r=min(ri.r,a[i].r);ri.l=max(ri.l,a[i].l);
	}printf("%d",ans);return 0;
}
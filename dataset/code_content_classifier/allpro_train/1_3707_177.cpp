#include<bits/stdc++.h>
#define LL long long 
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=1005;
int n,m,a[N],op[N],vis[N],tot,cnt,fn=1;
void chkneg()
{
	int mx=-1e9,pos=0;
	for(int i=1;i<=n;i++)
	  if(a[i]>mx) mx=a[i],pos=i;
	printf("%d\n%d\n",mx,n-1);
	for(int i=n;i>pos;i--) printf("%d\n",i);
	for(int i=1;i<pos;i++) printf("%d\n",1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>0) fn=0;
	} 
	if(fn){chkneg();return 0;}
	LL s1=0,s2=0;
	for(int i=1;i<=n;i+=2)
	  if(a[i]>0) s1+=a[i];
	for(int i=2;i<=n;i+=2)
	  if(a[i]>0) s2+=a[i];
	printf("%lld\n",max(s1,s2));
	
	int b = s1>s2 ? 1 : 2;
	for(int i=b;i<=n;i+=2)
	  if(a[i]>0) vis[++cnt]=i;
	int l=vis[1],r=vis[cnt]; m=0;
	for(int i=n;i>r;i--) op[++tot]=i;
	for(int i=1;i<l;i++) op[++tot]=1;
	for(int i=l;i<=r;i++) a[++m]=a[i];
//	for(int i=1;i<=m;i++) cout<<a[i]<<' '; cout<<endl;
//	*.......*.....*...*.*
	for(int i=1;i<cnt;i++)
	{
		int x=(vis[i+1]-vis[i])>>1;
		for(int j=x+1;j>=2;j--)
		  op[++tot]=j;
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++)
	  printf("%d\n",op[i]);
	return 0;
}

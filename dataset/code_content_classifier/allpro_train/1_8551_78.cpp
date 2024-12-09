#include<cstdio>
#define N 1000001
#define p 1000000007
#define ll long long
int a[N],i,n,x;
int main()
{
	scanf("%d",&n),a[1]=x=1;
	for(i=2;i<=n;i++)a[i]=(ll)(p-p/i)*a[p%i]%p;
	for(i=1;i<=n;i++)a[i]=(ll)a[i]*a[n]%p;
	for(i=n;i;i--)x=333333336ll*x%p,a[i]=(ll)a[i]*x%p;
	for(i=1,x=0;i<=n;i++)x=(x+a[i])%p;
	return 0*printf("%d\n",x);
}
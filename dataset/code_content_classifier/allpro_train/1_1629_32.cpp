#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
double A[100010],B[100010],C[100010],nw;
int n,tree[300010],nd[100010],rk[100010];
inline void Add(int x)
{
	for(;x<=n;x+=x&-x)
		tree[x]++;
}
inline int Ask(int x)
{
	int ret=0; for(;x;x-=x&-x)
		ret+=tree[x]; return ret;
}
inline bool cmp(const int a,const int b)
{
	return (C[a]-A[a]*nw)/B[a]<(C[b]-A[b]*nw)/B[b];
}
inline double work()
{
	for(int i=1;i<=n;i++) rk[i]=i;
	nw=-1000000000; sort(rk+1,rk+1+n,cmp);
	for(int i=1;i<=n;i++) nd[rk[i]]=i;
	//for(int i=1;i<=n;i++) cout << nd[i] << " " ; cout << endl;
	double L=-1000000000,R=10000000000;
	for(int i=1;i<=100;i++)
	{
		nw=(L+R)/2;
		sort(rk+1,rk+1+n,cmp);
		ll tp=0;		
		memset(tree,0,sizeof tree);
		for(int i=1;i<=n;i++)
		{
			tp+=Ask(n)-Ask(nd[rk[i]]);
			Add(nd[rk[i]]);
		}
	//	cout << tp << endl;
		if(n*(n-1)%4)
		{
			if(tp>1ll*(n-1)*n/2/2) R=nw;
			else L=nw;
		}
		else 
		{
			if(tp>=1ll*(n-1)*n/2/2) R=nw;
			else L=nw;

		}
	}
	return L;
}
int main()
{
	// freopen("read.in","r",stdin);
	n=read(); for(int i=1;i<=n;i++)
	A[i]=read(), B[i]=read(), C[i]=read();
	double X=work(); 
	for(int i=1;i<=n;i++) swap(A[i],B[i]);
	double Y=work();
	printf("%.9lf %.9lf\n",X,Y);
	return 0;
}
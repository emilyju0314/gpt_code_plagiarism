#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
inline void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
inline void pr1(int x){write(x),putchar(' ');}
inline void pr2(int x){write(x),puts("");}
struct node
{
	int p,id;
}a[510];
bool cmp(node a,node b)
{
	if(a.p==b.p)return a.id>b.id;
	else return a.p<b.p;
}
int l[510],r[510],f[510][300];
int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n=read(),m=read();
    for(int i=0;i<2*n;i++)
    {
    	a[i].id=i;r[i]=min(2*n-1,(int)floor(sqrt(4*n*n-i*i)));
    	if(i>=n)l[i]=0,a[i].p=r[i];
    	else {l[i]=ceil(sqrt(n*n-i*i));a[i].p=l[i]-1;}
	}sort(a,a+2*n,cmp);
	int ans=0;
	for(int k=0;k<=n;k++)
	{
		int cnt=0;
		memset(f,0,sizeof(f));f[0][0]=1;
		for(int i=1;i<=2*n;i++)
		{
			if(a[i-1].id<n)cnt++;
			for(int j=0;j<=min(k,cnt);j++)
			{
				if(a[i-1].id<n)
				{
					f[i][j]=1LL*f[i-1][j]*(r[a[i-1].id]+1-(2*n-1-a[i-1].id+k-j))%m;
					if(j>0)(f[i][j]+=1LL*f[i-1][j-1]*(a[i-1].p+1-(i-1-(cnt-j)))%m)%=m;
				}
				else f[i][j]=1LL*f[i-1][j]*(a[i-1].p+1-(i-1-(cnt-j)))%m;
			}
		}
		if(k&1)(ans-=f[2*n][k]-m)%=m;
		else (ans+=f[2*n][k])%=m;
	}pr2(ans);
   	return 0;
}
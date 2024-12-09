#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<bitset>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=2005;
int n,ans;
bool a[N][N];
char s[N];
bitset <N> f[N],g[N];

int main()
{
	scanf("%d",&n);
	rep(i,2,n)
	{
		scanf("%s",s+1);
		rep(j,1,i-1)
		{
			int x=s[j]-'0';	
			a[i][j]=x,a[j][i]=x^1;
		}
	}
	rep(i,1,n)
	{
		f[i][i]=g[i][i]=1;
		rep(j,1,i-1)
			if(g[i-1][j] && a[i][j]) f[i]|=f[j];
		rep(j,1,i-1)
			if(f[i][j+1] && a[j][i]) g[i]|=g[j];
	}
	rep(i,1,n) if(f[i][1] && g[n][i]) ++ans;
	printf("%d\n",ans);
	return 0;
}
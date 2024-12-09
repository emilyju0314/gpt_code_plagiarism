#include<algorithm>
#include<cstring>
#include<cstdio>
#define mxn 1000010
using namespace std;
const int inf=1e9,mod=998244353;
int n,sl,fh,top,ans,s[mxn],stk[mxn],cnt[mxn];
char a[mxn];
int rd()
{
	sl=0;fh=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
	return sl*fh;
}
void upd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}
bool check(int x)
{
	for(int b=1,j=1,i=x+1;i<=n;++i,j=j%x+1,b^=(j==1))
		if(a[i]>(a[j]^b)) return 1;
		else if(a[i]<(a[j]^b)) return 0;
	return 1;
}
int main()
{
	n=rd();scanf("%s",a+1);
	for(int i=1;i<=n;++i) s[i]=(2ll*s[i-1]+(a[i]=='1'))%mod;
	for(int i=1;i<=n;++i)
		if(n%i==0&&((n/i)&1))
		{
			stk[++top]=i;
			upd(cnt[i],s[i]+check(i));
			for(int j=i+i;j<=n;j+=i)
				if(n%j==0&&((n/j)&1))
					upd(cnt[j],mod-cnt[i]);
		}
	for(int i=1;i<=top;++i) ans=(ans+2ll*stk[i]*cnt[stk[i]])%mod;
	printf("%d\n",ans);
	return 0;
}
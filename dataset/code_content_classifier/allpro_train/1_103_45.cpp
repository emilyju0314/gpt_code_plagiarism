#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 5005
int read(){
	int w=0,f=1;
	char c=' ';
	while(c<'0'||c>'9')c=getchar(),f=c=='-'?-1:f;
	while(c>='0'&&c<='9')w=w*10+c-48,c=getchar();
	return w*f;
}
int T,n,dp[N],tag[N],s[N],ans;
signed main(){
	T=read();
	while(T--){
		n=read(),ans=0;
		for(int i=1;i<=n;i++)
			tag[i]=read(),dp[i]=0;
		for(int i=1;i<=n;i++)
			s[i]=read();
		for(int i=1,tmp;i<=n;i++)
			for(int j=i-1;j>0;j--)
				if(tag[i]!=tag[j])tmp=dp[i],dp[i]=max(dp[i],dp[j]+abs(s[i]-s[j])),dp[j]=max(dp[j],tmp+abs(s[i]-s[j]));
		for(int i=1;i<=n;i++)
			ans=max(ans,dp[i]);
		printf("%lld\n",ans);
	}
	return 0;
}
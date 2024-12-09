// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
const int inf=1e9,mod=1e9+7;
typedef long long ll;
int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') f=(c=='-')?-1:1,c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
using namespace std;
int val[1000001],f[1000001],cnt[20],vis[1000001],js,x,y,z,ans,n,len=(1<<15);
int main() {
	n=read(),len=(1<<15);
	for(int i=1; i<n; i++)
		x=read(),y=read(),z=read(),val[x]^=z,val[y]^=z;
	for(int i=0; i<n; i++)
		cnt[val[i]]++;
	for(int i=1; i<=15; i++)
		ans+=cnt[i]/2,js|=(cnt[i]&1)<<(i-1);
	for(int i=1; i<len; i++)
		f[i]=f[i>>1]+(i&1);
	for(int i=1; i<len; i++)
		f[i]--;
	for(int i=1; i<len; i++)
		for(int j=0; j<15; j++)
			if((i>>j)&1)
				vis[i]^=(j+1);
	for(int i=1; i<len; i++) {
		if(vis[i]) continue;
		for(int k=(i-1)&i; k; k=(k-1)&i)
			if(!vis[k])
				f[i]=min(f[i],f[k]+f[i^k]);
	}
	printf("%d",ans+f[js]);
	return 0;
}//da
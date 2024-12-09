#include<cstdio>
const int MaxN=100010,mod=1000000007;
int N,a[MaxN];
struct edge{int to;edge*next;}E[MaxN],*fir[MaxN];
int C[MaxN],pos[MaxN],dep[MaxN],cnt[MaxN],ways[MaxN];
bool vis[MaxN];
int solve(){
	int res=1;
	for(int i=0;i<N;i++)if(!vis[i]){
		int len=0,tot=0,j=i,k;
		for(;!vis[j];j=a[j])vis[j]=1;
		for(k=i;vis[k];k=a[k])vis[k]=0;
		for(;!vis[j];j=a[j])vis[C[len++]=j]=1;
		for(j=0,k=len-1;j<k;j++,k--){
			int t=C[j];C[j]=C[k],C[k]=t;
		}
		for(j=0;j<len;j++){
			int x=C[j],d=0;
			for(;;){
				int c=0,t;
				for(edge*e=fir[x];e;e=e->next)if(!vis[e->to])c++,t=e->to;
				if(c>1)return 0;
				if(!c)break;
				vis[x=t]=1;d++;
			}
			if(d)pos[tot]=j,dep[tot++]=d;
		}
		if(tot){
			for(j=0;j<tot;j++){
				int d=(pos[(j+1)%tot]-pos[j])%len;
				if(d<=0)d+=len;
				if(d<dep[j])return 0;
				if(d>dep[j])res=res*2%mod;
			}
		}
		else cnt[len]++;
	}
	for(int i=1;i<=N;i++){
		ways[0]=1;
		for(int j=1;j<=cnt[i];j++){
			ways[j]=ways[j-1]*(i>1&&i%2?2:1)%mod;
			if(j>1)ways[j]=(ways[j]+(j-1ll)*ways[j-2]%mod*i)%mod;
		}
		res=1ll*res*ways[cnt[i]]%mod;
	}
	return res;
}
int main(){
	while(scanf("%d",&N)==1){
		for(int i=0;i<N;i++)scanf("%d",a+i),--a[i],fir[i]=0,vis[i]=0;
		for(int i=0;i<N;i++)E[i]=(edge){i,fir[a[i]]},fir[a[i]]=E+i;
		for(int i=N;i;i--)cnt[i]=0;
		printf("%d\n",solve());
	}
}
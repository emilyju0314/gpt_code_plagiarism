#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+999;

struct edge{
	int to,nxt,dis;
}e[maxn];
int head[maxn],tot;
void add(int x,int y,int z){
	e[++tot].to=y;
	e[tot].nxt=head[x];
	e[tot].dis=z;
	head[x]=tot;
}
int n,m,col[maxn],cnt0,cnt1,cnt2,cnt,fl;

void dfs(int x,int c){
	col[x]=c;
	if(c==0)cnt0++;
	if(c==1)cnt1++;
	if(c==2)cnt2++;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(e[i].dis>0)++cnt;
		if(col[y]==-1)dfs(y,(c+e[i].dis+3)%3);
		else if(col[y]!=(c+e[i].dis+3)%3)fl=1;
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y,1);add(y,x,-1);
	}
	long long ans=0;
	memset(col,-1,sizeof(col));
	for(int i=1;i<=n;++i){
		if(col[i]==-1){
			fl=cnt=cnt0=cnt1=cnt2=0;
			dfs(i,0);
			if(fl){//染色失败 完全图 
				ans+=1ll*(cnt0+cnt1+cnt2)*(cnt0+cnt1+cnt2);
			}
			else if(cnt0&&cnt1&&cnt2){
				ans+=1ll*cnt0*cnt1+1ll*cnt1*cnt2+1ll*cnt2*cnt0;
			}
			else ans+=cnt;
		}
	}
	cout<<ans;
}
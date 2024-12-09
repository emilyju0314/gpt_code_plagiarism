#include<bits/stdc++.h>
using namespace std;
const int maxn=1000100;
int n,k,a[maxn],lv[maxn],rv[maxn],suml[maxn],sumr[maxn],nxt[maxn],pre[maxn],tot,flag[maxn];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > Q;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",a+i),Q.push(make_pair(a[i],i));
	for(int i=1;i<=n;i++) nxt[i]=i+1,pre[i]=i-1,lv[i]=rv[i]=1;tot=n;nxt[n]=0;
	long long ans=0;
	while(Q.size())
	{
		int v=Q.top().second;Q.pop();
		if(flag[v]) continue;
		int l=v,r=v,cnt=1,lst=0;
		while(a[pre[l]]==a[v]) l=pre[l],cnt++;
		while(a[nxt[r]]==a[r]) r=nxt[r],cnt++;
		for(int i=l,j=1;;i=nxt[i],j++)
		{
			suml[j]=suml[j-1]+lv[i];sumr[j]=sumr[j-1]+rv[i];
			if(i<=n) lst=j;
			if(lst&&j>=k) ans+=1ll*suml[min(j-k+1,lst)]*rv[i];
			flag[i]=1;if(i==r) break;
		}
		if(cnt<k) {nxt[pre[l]]=pre[nxt[r]]=0;continue;}
		int stpos=tot+1;
		for(int i=1;i<=cnt/k;i++)
		{
			rv[++tot]=sumr[min(cnt,(i+1)*k-1)]-sumr[i*k-1];a[tot]=a[l]+1;
			lv[tot]=suml[cnt-(cnt/k-i+1)*k+1]-suml[max(0,cnt-(cnt/k-i+2)*k+1)];
		}
		nxt[pre[l]]=stpos;pre[stpos]=pre[l];
		pre[nxt[r]]=tot;nxt[tot]=nxt[r];
		for(int i=stpos;i<tot;i++) nxt[i]=i+1,pre[i+1]=i;
		Q.push(make_pair(a[stpos],stpos));
	}
	printf("%lld\n",ans+n);
}
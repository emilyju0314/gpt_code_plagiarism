#include<bits/stdc++.h>
using namespace std;
struct date{
	int c0,c1,id;
	bool operator <(date rhs) const{
		return (long long)c0*rhs.c1<(long long)c1*rhs.c0;
	}
};
priority_queue<date> q;
int p[300000],c0[300000],c1[300000],fa[300000];
int find(int x){
	if (fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
		scanf("%d",p+i);
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if (!x) c0[i]++;
		else c1[i]++;
	}
	for (int i=2;i<=n;i++)
		q.push((date){c0[i],c1[i],i});
	for (int i=1;i<=n;i++) fa[i]=i;
	long long ans=0;
	while (!q.empty()){
		date d=q.top();
		int u=d.id;
		q.pop();
		if (d.c0!=c0[u]||d.c1!=c1[u]) continue;
		int v=find(p[u]);
		ans+=(long long)c1[v]*c0[u];
		c0[v]+=c0[u];
		c1[v]+=c1[u];
		fa[u]=v;
		if (v!=1) q.push((date){c0[v],c1[v],v});
	}
	printf("%lld\n",ans);
	return 0;
}
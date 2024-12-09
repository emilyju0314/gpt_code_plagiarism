#include<bits/stdc++.h>
#define MN 2005
struct edge{
	int to,nxt;
}e[MN<<1];
char ok[MN];
int n,r[MN],l[MN],siz[MN],Ans=2147483647,h[MN];
void ins(int x,int y) {
	static int cnt=0;
	e[++cnt].nxt=h[x];h[x]=cnt;e[cnt].to=y;
}
void dfs(int x,int f)
{
	siz[x]=ok[x]=='1';l[x]=r[x]=0;
	for(int i=h[x];i;i=e[i].nxt)
	{
		if(e[i].to==f) continue;
		dfs(e[i].to,x);
//		if(x==3) printf("%d : %d\n",x,e[i].to);
		if(l[e[i].to]>r[x]) {
			l[x]=l[e[i].to]-r[x];
		} else if(r[e[i].to]<l[x]) {
			l[x]=l[x]-r[e[i].to];
		} else l[x]=(l[x]^l[e[i].to])&1;
		r[x]+=r[e[i].to];
//		if(x==3) printf("%d %d\n",l[x],r[x]);
		siz[x]+=siz[e[i].to];
	}
	l[x]+=siz[x];r[x]+=siz[x];
//	if(x==3) printf("%d : %d %d\n",x,l[x],r[x]);
}
int main()
{
	scanf("%d%s",&n,ok+1);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ins(x,y);
		ins(y,x);
	}
	for(int i=1;i<=n;i++)
	{
//		printf("I ; %d dddddddddddd\n",i);
		dfs(i,0);
//		printf("%d %d %d\n",siz[i],l[i],r[i]);
		if(l[i]==siz[i]) Ans=std::min(Ans,r[i]-siz[i]);
	}
	if(Ans==2147483647) puts("-1");
	else printf("%d\n",Ans/2);
}
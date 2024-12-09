#include<cstdio>
int n,m,i,j,k,k2,t,x,y,z,a[2505],v[2505],st[5005],en[5005],len[5005],last[2505],nxt[5005],st2[5005],en2[5005],last2[2505],nxt2[5005],find[10000005];
bool b[2505],f[2505];
void build(int x,int y,int z)
{
	k++,st[k]=x,en[k]=y,len[k]=z,nxt[k]=last[x],last[x]=k;
}
void build2(int x,int y)
{
	k2++,st2[k2]=x,en2[k2]=y,nxt2[k2]=last2[x],last2[x]=k2;
}
void go(int x)
{
	for (int i=last2[x];i;i=nxt2[i])
	if (!f[en2[i]])
	{
		f[en2[i]]=true;
		go(en2[i]);
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&t);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		build(x,y,z);
		build2(y,x);
	}
	f[n]=true;
	go(n);
	for (i=1;i<=n;i++)
	a[i]=-2e9;
	a[1]=0,x=y=find[1]=1,b[1]=true;
	while (x<=y)
	{
		b[find[x]]=false;
		for (i=last[find[x]];i;i=nxt[i])
		if (a[en[i]]<a[st[i]]+len[i]-t&&f[en[i]])
		{
			a[en[i]]=a[st[i]]+len[i]-t;
			if (!b[en[i]])
			b[en[i]]=true,y++,find[y]=en[i],v[en[i]]++;
			if (v[en[i]]>n)
			return printf("-1\n")&&0;
		}
		x++;
	}
	printf("%d\n",a[n]>0?a[n]:0);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> P;
#define X first
#define Y second
#define mid (l+r)/2
#define lc k<<1,l,mid
#define rc k<<1|1,mid+1,r
const int MAXN=3e5+10;
int n,m,k,seg[MAXN<<2],tag[MAXN<<2],res=0;
P dat[MAXN],st1[MAXN],st2[MAXN];

void pushdown(int k)
{
	if(!tag[k]) return;
	tag[k<<1]+=tag[k];seg[k<<1]+=tag[k];
	tag[k<<1|1]+=tag[k];seg[k<<1|1]+=tag[k];
	tag[k]=0;
}

void Update(int a,int b,int x,int k,int l,int r)
{
	if(a<=l&&r<=b){tag[k]+=x;seg[k]+=x;return;}
	pushdown(k);
	if(a<=mid) Update(a,b,x,lc);
	if(b>mid) Update(a,b,x,rc);
	seg[k]=max(seg[k<<1],seg[k<<1|1]);  
}

void solve()
{
	memset(seg,0,sizeof(seg));
	memset(tag,0,sizeof(tag));
	sort(dat+1,dat+k+1);
	
	int t1=0,t2=0;
	for(int i=1;i<=k;i++)
	{
		if(dat[i].Y<=m/2)
		{
			int lst=i-1;
			while(t1&&st1[t1].Y<dat[i].Y)
				Update(st1[t1].X,lst,st1[t1].Y-dat[i].Y,1,1,k),
				lst=st1[t1--].X-1;
			if(lst!=i-1) st1[++t1]=P(lst+1,dat[i].Y);
		}
		else
		{
			int lst=i-1;
			while(t2&&st2[t2].Y>dat[i].Y)
				Update(st2[t2].X,lst,dat[i].Y-st2[t2].Y,1,1,k),
				lst=st2[t2--].X-1;
			if(lst!=i-1) st2[++t2]=P(lst+1,dat[i].Y);			
		}
		
		st1[++t1]=P(i,0);st2[++t2]=P(i,m);
		Update(i,i,m-dat[i].X,1,1,k);
		res=max(res,seg[1]+dat[i+1].X);
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++) 
		scanf("%d%d",&dat[i].X,&dat[i].Y);
	dat[++k]=P(0,0);dat[++k]=P(n,m);
	solve();
	for(int i=1;i<=k;i++) 
		swap(dat[i].X,dat[i].Y);
	swap(n,m);
	solve();
	
	printf("%d",res*2);
	return 0;
}
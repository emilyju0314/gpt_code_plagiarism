#include<cstdio>
#include<iostream>
#define RI register int
#define CI const int&
using namespace std;
const int N=200005;
int n,p[N],pmx,q,pos[2],len[2],f[N][2]; bool tp[N];
class Segment_Tree
{
	private:
		int mx[N<<2];
	public:
		#define TN CI now=1,CI l=1,CI r=n
		#define LS now<<1,l,mid
		#define RS now<<1|1,mid+1,r
		inline void modify(CI pos,CI mv,TN)
		{
			if (l==r) return (void)(mx[now]=mv); int mid=l+r>>1;
			if (pos<=mid) modify(pos,mv,LS); else modify(pos,mv,RS);
			mx[now]=max(mx[now<<1],mx[now<<1|1]);
		}
		inline int query(CI beg,CI end,TN)
		{
			if (beg<=l&&r<=end) return mx[now]; int mid=l+r>>1,ret=0;
			if (beg<=mid) ret=max(ret,query(beg,end,LS));
			if (end>mid) ret=max(ret,query(beg,end,RS)); return ret;
		}
		#undef TN
		#undef LS
		#undef RS
}T0,T1;
inline bool check(CI x,CI lim)
{
	if (lim<0) return 0; if (lim&1) return T1.query(x,n)>=lim; else return T0.query(x,n)>=lim;
}
int main()
{
	RI i; for (scanf("%d",&n),i=1;i<=n;++i)
	if (scanf("%d",&p[i]),pmx=max(pmx,p[i]),p[i]==pmx) ++q,tp[i]=1;
	for (i=n;i;--i)
	{
		int c0=T0.query(p[i],n),c1=T1.query(p[i],n);
		f[i][(c0+tp[i]+1)&1]=max(f[i][(c0+tp[i]+1)&1],c0+tp[i]+1);
		f[i][(c1+tp[i]+1)&1]=max(f[i][(c1+tp[i]+1)&1],c1+tp[i]+1);
		T0.modify(p[i],f[i][0]); T1.modify(p[i],f[i][1]);
	}
	if (!check(1,q)) return puts("-1"),0;
	for (i=1;i<=n;++i)
	{
		T0.modify(p[i],0); T1.modify(p[i],0); q-=tp[i];
		int x=p[i]>p[pos[0]]?i:pos[0],y=len[0]+(x==i);
		if (check(p[x],len[1]-y+q)||check(p[pos[1]],y-len[1]+q))
		pos[0]=x,len[0]=y,putchar('0'); else
		pos[1]=(p[i]>p[pos[1]]?i:pos[1]),len[1]+=pos[1]==i,putchar('1');
	}
	return 0;
}
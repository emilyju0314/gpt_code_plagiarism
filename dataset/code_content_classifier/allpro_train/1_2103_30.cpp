#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
//#include<iostream>
#define  N  410000
using  namespace  std;
typedef  long  long  LL;
const  LL  mod=998244353;
template<class  T>
inline  void  zwap(T  &x,T  &y){x^=y^=x^=y;}
int  e[N];int  ecnt;
LL  v2[N];//2^i
LL  has=0;
 
struct  node
{
	int  y,next;
	bool  bk;
}a[N];int  len=1,last[N],du[N];
inline  void  ins(int  x,int  y){len++;a[len].y=y;a[len].next=last[x];last[x]=len;du[y]++;}
int  root[N],rcnt,lian[N][2];
LL  rval[N][2];
int  be[N];
inline  void  xiao(int  x){(has-=rval[x][0]-mod)%=mod;}
inline  void  tian(int  x){(has+=rval[x][0])%=mod;}
 
int  siz[N],val[N],key[N],son[N][2],cnt;
bool  lazy[N];
inline  void  pushlazy(int  x)
{
	zwap(son[x][0],son[x][1]);
	lazy[x]^=1;
}
inline  void  plazy(int  id)
{
	zwap(lian[id][0],lian[id][1]);
	zwap(rval[id][0],rval[id][1]);
	pushlazy(root[id]);
}
inline  void  pushup(int  x){siz[x]=siz[son[x][0]]+siz[son[x][1]]+1;}
inline  void  pushdown(int  x)
{
	if(lazy[x])lazy[x]=0,pushlazy(son[x][0]),pushlazy(son[x][1]);
}
inline  int  mer(int  A,int  B)
{
	if(!A   ||  !B)return  A+B;
	if(val[A]<=val[B])pushdown(A),son[A][1]=mer(son[A][1],B),pushup(A);
	else  pushdown(B),son[B][0]=mer(A,son[B][0]),pushup(B),zwap(A,B);
	return  A;
}
inline  void  add(int  k,int  to,int  type)
{
	if(type==1)
	{
		if(siz[root[to]]&1)(rval[to][1]+=v2[k])%=mod;
		else  (rval[to][0]+=v2[k])%=mod,(has+=v2[k])%=mod;
	}
	else
	{
		xiao(to);zwap(rval[to][0],rval[to][1]);
		(rval[to][0]+=v2[k])%=mod;tian(to);
	}
	cnt++;siz[cnt]=1;val[cnt]=rand();key[cnt]=k;
	if(!type)root[to]=mer(cnt,root[to]);
	else  root[to]=mer(root[to],cnt);
}
inline  void  he(int  x,int  y,int  t1,int  t2,int  k)
{
	if(t1==0)
	{
		if(!(siz[root[x]]&1))zwap(rval[x][0],rval[x][1]),(has+=rval[x][0]-rval[x][1]+mod)%=mod;
		zwap(lian[x][0],lian[x][1]);
		pushlazy(root[x]);
	}
	add(k,x,1);
	if(t2==1)
	{
		if(!(siz[root[y]]&1))zwap(rval[y][0],rval[y][1]),(has+=rval[y][0]-rval[y][1]+mod)%=mod;
		zwap(lian[y][0],lian[y][1]);
		pushlazy(root[y]);
	}
	xiao(x);xiao(y);
	be[lian[x][1]]=be[lian[y][0]]=0;be[lian[y][1]]=x;
	lian[x][1]=lian[y][1];
	if(siz[root[x]]&1)(rval[x][0]+=rval[y][1])%=mod,(rval[x][1]+=rval[y][0])%=mod;
	else  (rval[x][0]+=rval[y][0])%=mod,(rval[x][1]+=rval[y][1])%=mod;
	root[x]=mer(root[x],root[y]);
	tian(x);
}
 
inline  void  dfs1(int  x,int  id,int  co)
{
	if(du[x]&1)
	{
		lian[id][1]=x;du[x]--;
		be[x]=id;
		return  ;
	}
	for(int  &k=last[x];k;)
	{
		if(a[k].bk==0)
		{
			a[k].bk=1,a[k^1].bk=1;
			int  y=a[k].y;
			add(k/2,id,1);
			k=a[k].next;
			dfs1(y,id,co^1);
			return  ;
		}
		k=a[k].next;
	}
}
bool  shi[N];
inline  void  dfs2(int  x,int  co)
{
	shi[x]=1;
	for(int  &k=last[x];k;)
	{
		int  y=a[k].y;
		if(a[k].bk==0)
		{
			a[k].bk=a[k^1].bk=1;e[k/2]=co;
			if(co==0)(has+=v2[k/2])%=mod;
			k=a[k].next;
			dfs2(y,co^1);
		}
		else  k=a[k].next;
	}
}
int  sta[N],top;
inline  void  dfs3(int  x)
{
	if(!x)return  ;
	pushdown(x);
	dfs3(son[x][0]);
	sta[++top]=key[x];
	dfs3(son[x][1]);
}
inline  void  fu(int  x)
{
	top=0;dfs3(root[x]);
	for(int  i=1;i<=top;i++)e[sta[i]]=!(i&1);
}
inline  void  mie(int  x)
{
	fu(x);
	be[lian[x][0]]=be[lian[x][1]]=0;
}
int  n1,n2,m,n;
int  main()
{
//	freopen("std.in","r",stdin);
//	freopen("vio.out","w",stdout);
//	srand(time(0));
	scanf("%d%d%d",&n1,&n2,&m);n=n1+n2;ecnt=m;
	v2[0]=1;for(int  i=1;i<=400000;i++)v2[i]=(v2[i-1]*2)%mod;
	for(int  i=1;i<=m;i++)
	{
		int  x,y;scanf("%d%d",&x,&y);y+=n1;
		ins(x,y);ins(y,x);
		
	}
	
	for(int  i=1;i<=n;i++)
	{
		if(du[i]&1)
		{
			du[i]--;be[i]=++rcnt;
			lian[rcnt][0]=i;
			dfs1(i,rcnt,0);
		}
	}
	for(int  i=1;i<=n;i++)
	{
		if(!shi[i])dfs2(i,0);
	}
	int  q;scanf("%d",&q);
	for(int  i=1;i<=q;i++)
	{
		int  type;scanf("%d",&type);
		if(type==1)
		{
			int  x,y;scanf("%d%d",&x,&y);y+=n1;
			++ecnt;
			
			if(be[x]  &&  be[y])
			{
				if(be[x]==be[y])
				{
					mie(be[x]),e[ecnt]=1;
				}
				else  he(be[x],be[y],lian[be[x]][1]==x,lian[be[y]][1]==y,ecnt);
			}
			else  if(be[x]+be[y]>0)
			{
				int  rt=be[x]+be[y],pi=be[x]?x:y;
				if(lian[rt][0]==pi)
				{
					add(ecnt,rt,0);
					be[lian[rt][0]]=0;be[lian[rt][0]=pi^x^y]=rt;
				}
				else
				{
					add(ecnt,rt,1);
					be[lian[rt][1]]=0;be[lian[rt][1]=pi^x^y]=rt;
				}
			}
			else
			{
				be[x]=be[y]=++rcnt;lian[rcnt][0]=x;lian[rcnt][1]=y;
				add(ecnt,rcnt,1);
			}
			printf("%lld\n",has);
			fflush(stdout);
		}
		else
		{
			int  rans=0;
			for(int  i=1;i<=n;i++)
			{
				if(be[i]  &&  lian[be[i]][0]==i)fu(be[i]);
			}
			for(int  i=1;i<=ecnt;i++)
			{
				if(e[i]==0)rans++;
			} 
			printf("%d ",rans);
			for(int  i=1;i<=ecnt;i++)
			{
				if(e[i]==0)printf("%d ",i);
			} 
			printf("\n");
			fflush(stdout);
		}
	}
//	printf("1\n");
	return  0;
}

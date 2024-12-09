#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<random>
#include<ctime>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
#include<unordered_map>
#include<map>
#include<bitset>
#include<stack>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=4e5+5,M=7e2+5;
const ll INF=1e18+5;
inline ll read()
{
	ll sum=0,fh=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')fh=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum*fh;
}
inline int read2()
{
	char c=getchar();
	while(c!='+'&&c!='-')c=getchar();
	return c=='+'?0:1;
}
inline int read3()
{
	char c=getchar();
	while(c<'a'||c>'z')
	{
		c=getchar();
	}
	return c-'a';
}
inline void write(ll x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
 
 
/*namespace INPUT_SPACE{
    const int BS=(1<<24)+5;char Buffer[BS],*HD,*TL;
    char gc() { if(HD==TL) TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);return (HD==TL)?EOF:*HD++; }
    inline int read()
    {
        int x,ch;while(((ch=gc())<'0'||ch>'9'));
        x=ch^'0';
        while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');
        return x;
    }
}using INPUT_SPACE::read;
char sws[30000011],tt[21];int ssl,ttl;
inline int write(int x)
{
    if(!x) sws[++ssl]='0';for(ttl=0;x;x/=10) tt[++ttl]=char(x%10+'0');
    for(;ttl;ttl--) sws[++ssl]=tt[ttl];return sws[++ssl]='\n';
}*/
 
inline int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
inline ll ab(ll x)
{
	return x<0?-x:x;
}
inline ll fpow(ll qwe,ll asd,ll zxc)
{
	if(asd<0)return 0;
	ll a=qwe,b=1,c=asd;
	while(c)
	{
		if(c&1)b=b*a%zxc;
		a=a*a%zxc;
		c>>=1;
	}
	return b;
}
 
#define pi pair<ll,ll>
/*struct miaow
{
	int f,t,l;
	ll c;
	miaow(int f=0,int t=0,ll c=0,int l=0):f(f),t(t),c(c),l(l){}
}imap[N*2+5];
int str[N*2+5]={0},cou=2;
inline void jb(int f,int t,ll c=0)
{
	//cout<<f<<" "<<t<<" "<<c<<endl;
	imap[cou]=miaow(f,t,c,str[f]);str[f]=cou++;
	imap[cou]=miaow(t,f,c,str[t]);str[t]=cou++;
}*/
//ll a[N];
 
/*struct miaow
{
	int l,r;
	meow imx;
}t[N*4+5];
#define l(x) t[x].l
#define r(x) t[x].r
#define imx(x) t[x].imx
#define ls(x) (x*2)
#define rs(x) (x*2+1)
inline void csh(int l,int r,int o)
{
	l(o)=l,r(o)=r;
	if(l==r)
	{
		imx(o)=meow(dep[dfn[l]],l,r);
		return;
	}
	int mid=(l+r)>>1;
	csh(l,mid,ls(o)),csh(mid+1,r,rs(o));
	imx(o)=meg(imx(lss(o)),imx(rss(o)));
}
inline meow cx(int l,int r,int o)
{
	//cout<<l<<" "<<r<<" "<<o<<endl;
	if(l<=l(o)&&r>=r(o))return imx(o);
	meow qwe(1e9,0,0),asd(1e9,0,0);
	int mid=(l(o)+r(o))>>1;
	if(l<=mid)qwe=cx(l,min(mid,r),ls(o));
	if(r>mid)asd=cx(max(mid+1,l),r,rs(o));
	return meg(qwe,asd);
}*/
/*inline void xg(int l,int r,int o,int x)
{
	if(l>r)return;
	if(l<=l(o)&&r>=r(o))
	{
		bj(o)+=x;
		imx(o)+=x;
		return;
	}
	int mid=(l(o)+r(o))>>1;
	if(l<=mid)xg(l,min(mid,r),ls(o),x);
	if(r>mid)xg(max(l,mid+1),r,rs(o),x);
	if(imx(ls(o))>imx(rs(o)))imx(o)=imx(ls(o))+bj(o),sum(o)=sum(ls(o));
	else if(imx(ls(o))<imx(rs(o)))imx(o)=imx(rs(o))+bj(o),sum(o)=sum(rs(o));
	else imx(o)=imx(ls(o))+bj(o),sum(o)=sum(ls(o))+sum(rs(o));
}*/
/*inline void xg(int k,int o,int x)
{
	//if(l>r)return;
	if(l(o)==r(o))
	{
		mat(o,0,0)=0;
		mat(o,0,1)=x;
		mat(o,1,0)=-x;
		mat(o,1,1)=0;
		return;
		return;
	}
	int mid=(l(o)+r(o))>>1;
	if(k<=mid)xg(k,ls(o),x);
	else xg(k,rs(o),x);
	upd(o);
}*/
/*inline int cx(int k,int o)
{
	if(l(o)==r(o))return imx(o);
	int x=imx(o),mid=(l(o)+r(o))>>1;
	if(k<=mid)return min(x,cx(k,ls(o)));
	else return min(x,cx(k,rs(o)));
}*/
int n,m,n2,zks;
int kw[N],a[N],b[N],kl[M],kr[M],bj[M];
inline void kcsh(int x)
{
	if(bj[x]>n2)return;
	for(int i=kl[x];i<=kr[x];++i)
	{
		b[i]=a[i]-bj[x];
		if(b[i]>=kl[x])b[i]=b[b[i]];
		//cout<<b[i]<<endl;
	}
}
inline int cx(int x,int y)
{
	while(x!=y)
	{
		if(x>y)swap(x,y);
		if(kw[x]==kw[y])
		{
			int z=kw[x];
			int x1,y1;
			if(bj[z]>n2)x1=a[x]-bj[z],y1=a[y]-bj[z];
			else x1=b[x],y1=b[y];
			//cout<<x1<<" "<<y1<<endl;
			if(x1==y1)
			{
				while(x!=y)
				{
					if(x<y)y=a[y]-bj[z];
					else x=a[x]-bj[z];
					if(x<=1||y<=1)return 1;
				}
				return x;
			}
			else
			{
				x=x1,y=y1;
			}
		}
		else
		{
			if(bj[kw[y]]>n2)y=a[y]-bj[kw[y]];
			else y=b[y];
		}
		if(x<=1||y<=1)return 1;
	}
	return x;
}
inline void cz(int l,int r,int x)
{
	int l1=kw[l],r1=kw[r];
	if(l1==r1)
	{
		for(int i=l;i<=r;++i)
		{
			a[i]=max(1,a[i]-x);
		}
		kcsh(l1);
	}
	else
	{
		for(int i=l;i<=kr[l1];++i)
		{
			a[i]=max(1,a[i]-x);
		}
		kcsh(l1);
		for(int i=kl[r1];i<=r;++i)
		{
			a[i]=max(1,a[i]-x);
		}
		kcsh(r1);
		for(int i=l1+1;i<r1;++i)
		{
			if(bj[i]<n)bj[i]+=x;
			kcsh(i);
		}
	}
}
int main()
{
	//freopen("qwq.txt","r",stdin);
	//freopen("qaq.txt","w",stdout);
	n=read(),m=read();
	n2=330;
	a[1]=0;
	for(int i=2;i<=n;++i)
	{
		a[i]=read();
		kw[i]=i/n2;
		if(!kl[kw[i]])kl[kw[i]]=i;
		kr[kw[i]]=i;
	}
	kl[0]=1;
	for(int i=0;i<=kw[n];++i)kcsh(i);
	int las=0;
	for(int i=1;i<=m;++i)
	{
		int o=read(),x=read(),y=read(),z;
		if(o==1)
		{
			z=read();
			cz(x^las,y^las,z^las);
		}
		else
		{
			int ans=cx(x^las,y^las);
			//las=ans;
			write(ans),putchar('\n');
		}
	}
	//fwrite(sws+1,sizeof(char),ssl,stdout);
}

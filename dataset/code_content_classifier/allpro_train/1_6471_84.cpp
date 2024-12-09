// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

typedef vector<int> vi;
const int maxn=100111;

int n,k;
vi operator *(const vi&a,const vi&b)
{
	vi ret(n);
	for(int i=0;i<n;i++)ret[i]=a[b[i]];
	return ret;
}
vi neg(const vi&a)
{
	vi ret(n);
	for(int i=0;i<n;i++)ret[a[i]]=i;
	return ret;
}
bool vis[maxn];
int seq[maxn];
vi qpow(const vi&a,int k)
{
	vi ret(n);
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++)if(!vis[i])
	{
		int tot=0,tmp=i;
		while(!vis[tmp])
		{
			seq[tot++]=tmp;vis[tmp]=1;
			tmp=a[tmp];
		}
		for(int j=0;j<tot;j++)ret[seq[j]]=seq[(j+k)%tot];
	}
	return ret;
}
vi conj(const vi&a,const vi&b){return a*b*neg(a);}


int main()
{
	get2(n,k);
	vi p,q;
	for(int i=0,x;i<n;i++)
	{
		get1(x);x--;
		p.pb(x);
	}
	for(int i=0,x;i<n;i++)
	{
		get1(x);x--;
		q.pb(x);
	}
	vi comm=q*neg(p)*neg(q)*p;comm=qpow(comm,(k-1)/6);
	p=conj(comm,p);q=conj(comm,q);
	for(int i=(k-1)/6*6+1;i<k;i++)
	{
		vi nv=q*neg(p);
		p=q;
		q=nv;
	}
	for(int i=0;i<n;i++)printf("%d ",p[i]+1);puts("");
	return 0;
}
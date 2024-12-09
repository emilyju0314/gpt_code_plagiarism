//12252024832524
#include <cstdio>
#include <cstring>
#include <algorithm>
#define TT template<typename T>
using namespace std;

typedef long long LL;
const int MAXN = 14;
const int MAXM = 105;
const int MAXS = 1<<MAXN;
const int INF = 0x3f3f3f3f;
int n,m,S,ans = 1;

LL Read()
{
	LL x = 0,f = 1;char c = getchar();
	while(c > '9' || c < '0'){if(c == '-')f = -1;c = getchar();}
	while(c >= '0' && c <= '9'){x = (x*10) + (c^48);c = getchar();}
	return x * f;
}
TT void Put1(T x)
{
	if(x > 9) Put1(x/10);
	putchar(x%10^48);
}
TT void Put(T x,char c = -1)
{
	if(x < 0) putchar('-'),x = -x;
	Put1(x); if(c >= 0) putchar(c);
}
TT T Max(T x,T y){return x > y ? x : y;}
TT T Min(T x,T y){return x < y ? x : y;}
TT T Abs(T x){return x < 0 ? -x : x;}

int f[MAXS][MAXM],g[MAXS][MAXM];
//portal set & the number of tasks completed : minimal time
//portal set & assassination position : maximal number of tasks completed
int as[MAXS][MAXM],po[MAXS][MAXN];//assassination & portal

struct node
{
	int x,y,t;
	bool operator < (const node &px)const{
		return t < px.t;
	}
}a[MAXN],b[MAXM];
int dis(node A,node B){return Abs(A.x-B.x)+Abs(A.y-B.y);}

int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n = Read(); m = Read();
	S = (1<<n); 
	for(int i = 0;i < n;++ i) a[i].x = Read(),a[i].y = Read();
	for(int i = 1;i <= m;++ i) b[i].x = Read(),b[i].y = Read(),b[i].t = Read();
	sort(b+1,b+m+1);
	for(int s = 0;s < S;++ s)
	{
		f[s][0] = INF;
		for(int i = 1;i <= m;++ i)//to assassination position
		{
			as[s][i] = f[s][i] = INF; g[s][i] = -INF;
			for(int j = 0;j < n;++ j)
				if((s>>j) & 1) as[s][i] = Min(as[s][i],dis(a[j],b[i]));
		}
		for(int i = 0;i < n;++ i)//to portal
		{
			po[s][i] = INF; 
			for(int j = 0;j < n;++ j)
				if((s>>j) & 1) po[s][i] = Min(po[s][i],dis(a[j],a[i]));
		}
	}
	for(int i = 0;i < n;++ i) f[1<<i][0] = 0;
	for(int i = 1;i <= m;++ i) g[0][i] = 1;
	for(int s = 0;s < S;++ s)
	{
		for(int i = 0;i <= m;++ i)
		{
			if(f[s][i] == INF) continue;
			for(int j = 0;j < n;++ j)
				if(!((s>>j) & 1)) 
					f[s|(1<<j)][i] = Min(f[s|(1<<j)][i],f[s][i]+po[s][j]);
			for(int j = 1;j <= m;++ j)
			{
				if(f[s][i] + as[s][j] > b[j].t) continue;
				g[s][j] = Max(g[s][j],i+1);
				ans = Max(ans,i+1);
			}
		}
		
		for(int i = 1;i <= m;++ i)
		{
			if(g[s][i] == -INF) continue;
			for(int j = 0;j < n;++ j)
			{
				if(b[i].t + Min(po[s][j],dis(b[i],a[j])) >= f[s|(1<<j)][g[s][i]]) continue;
				f[s|(1<<j)][g[s][i]] = b[i].t + Min(po[s][j],dis(b[i],a[j]));
			}
			for(int j = i+1;j <= m;++ j)
			{
				if(b[i].t + Min(as[s][j],dis(b[i],b[j])) > b[j].t) continue;
				g[s][j] = Max(g[s][j],g[s][i]+1);
				ans = Max(ans,g[s][j]);
			}
		}
	}
	Put(ans);
	return 0;
}
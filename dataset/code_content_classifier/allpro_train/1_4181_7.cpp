//12252024832524
#include <cstdio>
#include <cstring>
#include <algorithm>
#define TT template<typename T>
using namespace std;

typedef long long LL;
const int MAXN = 100005;
const int MAXK = 45;
int n,k;

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

int head[MAXN],tot;
struct edge
{
	int v,nxt;
}e[MAXN << 1];
void Add_Edge(int x,int y)
{
	e[++tot].v = y;
	e[tot].nxt = head[x];
	head[x] = tot;
}
void Add_Double_Edge(int x,int y)
{
	Add_Edge(x,y);
	Add_Edge(y,x);
}

int dp[MAXN][MAXK],tmp[MAXN][MAXK];
void dfs1(int x,int fa)
{
	for(int i = head[x]; i ;i = e[i].nxt)
	{
		int v = e[i].v;
		if(v == fa) continue;
		dfs1(v,x);
		for(int j = 0;j < k;++ j)
			dp[x][(j+1)%k] ^= dp[v][j];
	}
}
int ans[MAXN];
void dfs2(int x,int fa)
{
	for(int i = k>>1;i < k;++ i) ans[x] ^= dp[x][i]; 
	for(int i = 0;i < k;++ i) tmp[x][i] = dp[x][i];
	for(int i = head[x]; i ;i = e[i].nxt)
	{
		int v = e[i].v;
		if(v == fa) continue;
		for(int j = 0;j < k;++ j) dp[x][(j+1)%k] = tmp[x][(j+1)%k] ^ dp[v][j];
		for(int j = 0;j < k;++ j) dp[v][(j+1)%k] ^= dp[x][j]; 
		dfs2(v,x);
	}
}

int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n = Read(); k = Read() << 1;
	for(int i = 1;i < n;++ i) Add_Double_Edge(Read(),Read());
	for(int i = 1;i <= n;++ i) dp[i][0] = Read();
	dfs1(1,0);
	dfs2(1,0);
	for(int i = 1;i <= n;++ i)
		if(ans[i]) Put(1,' ');
		else Put(0,' ');
	return 0;
}

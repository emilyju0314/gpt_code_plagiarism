#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<ctime>
#include<map>
#include<bitset>
#include<set>
#include<assert.h>
#include<chrono>
#include<random>
#define LL long long
#define mp(x,y) make_pair(x,y)
#define pll pair<long long,long long>
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline LL read()
{
	LL f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int stack[20];
template<typename T>inline void write(T x)
{
	if(x<0){putchar('-');x=-x;}
    if(!x){putchar('0');return;}
    int top=0;
    while(x)stack[++top]=x%10,x/=10;
    while(top)putchar(stack[top--]+'0');
}
template<typename T>inline void pr1(T x){write(x);putchar(' ');}
template<typename T>inline void pr2(T x){write(x);putchar('\n');}
template<typename T>inline void chkmin(T &x,T y){x=x<y?x:y;}
template<typename T>inline void chkmax(T &x,T y){x=x>y?x:y;}
const int MAXN=100005;
int a[MAXN],n,b[MAXN];
vector<int> C;
bool check(int mod)
{
	for(int i=0;i<=n;i++)b[i]=(a[i]%mod+mod)%mod;
	for(int i=n;i>=mod;i--)if(b[i])
	{
		int h=b[i];b[i]=0;
		b[i-(mod-1)]+=h;if(b[i-(mod-1)]>=mod)b[i-(mod-1)]-=mod;
	}
	for(int i=min(n,mod-1);i>=0;i--)if(b[i])return false;
	return true;
}
int gcd(int a,int b){return a==0?b:gcd(b%a,a);}
bool is[MAXN];
int main()
{
//	freopen("a.in","r",stdin);
	int t=0;
	n=read();for(int i=n;i>=0;i--)a[i]=read(),t=gcd(t,a[i]);t=abs(t);
	for(int i=2;1LL*i*i<=t;i++)if(!(t%i))
	{
		C.emplace_back(i);
		while(!(t%i))t/=i;
	}if(t>1)C.emplace_back(t);
	for(int i=2;i<=n;i++)if(!is[i])
	{
		C.emplace_back(i);
		for(int j=2;i*j<=n;j++)is[i*j]=1;
	}
	sort(C.begin(),C.end());
	C.erase(unique(C.begin(),C.end()),C.end());
	for(auto p:C)if(check(p))
		pr2(p);
	return 0;
}


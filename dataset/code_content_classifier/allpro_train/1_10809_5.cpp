// by ξ
// program sky  :)

#include <vector>
#include <bitset>
#include <complex>
#include <stdio.h>
#include <cassert>
#include <algorithm>

#define Rin register int
#define oo (c=getchar())
#define For(i,l,r) for(int _r=r,i=l;i<=_r;++i)
#define rep(i,l,r) for(int _r=r,i=l;i<_r;++i)
#define dto(i,r,l) for(int _l=l,i=r;i>=_l;--i)
#define ALL(V) V.begin(),V.end()
#define SZ(A) (int(A.size()))
#define pb push_back
#define mk make_pair
#define x first
#define y second

using namespace std;

typedef double db;
typedef long long LL;
typedef pair<int ,int> PII;
typedef complex<db> cpx;
typedef vector<int> VI;
typedef vector<PII> VII;

inline int IN(){
	char c;Rin x=0;
	for(;oo<48 && c^'-' || c>57;);bool f=c=='-';if(f)oo;
	for(;c>47 && c<58;oo)x=(x<<3)+(x<<1)+c-48;if(f)x=-x;return x;
}

inline void hello(){
	freopen("ha.in","r",stdin);
//	freopen("ha.out","w",stdout);
}

const int mo=1e9+7;

int ans,n,r,pw[333*333],dp[333][333];

typedef bitset<333> vec;
vec base[333];

inline void inc(int &x,int y){
	if((x+=y)>=mo)x-=mo;
}

inline int Pow(int x,int y){
	int z=1;
	for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)z=1ll*z*x%mo;
	return z;
}

int main(){
// say hello
	//hello();
	n=IN();
	rep(i,0,n){
		vec v(0);
		rep(j,0,n)v[j]=IN();
		dto(k,n-1,0)if(v[k]){
			if(base[k][k])v^=base[k];else{
				base[k]=v;++r;
				break;
			}
		}
	}
	*pw=1;
	For(i,1,n*n)pw[i]=pw[i-1]*2%mo;
	**dp=1;
	rep(i,0,n)For(j,0,i)if(dp[i][j]){
		inc(dp[i+1][j],pw[j]*1ll*dp[i][j]%mo);
		inc(dp[i+1][j+1],(pw[n]-pw[j]+mo)*1ll*dp[i][j]%mo);
	}
	For(i,r,n){
		inc(ans,1ll*dp[n][i]*pw[n*(n-i)]%mo*dp[i][r]%mo);
	}
	printf("%d\n",1ll*ans*Pow(dp[n][r],mo-2)%mo);
// never say goodbye
}
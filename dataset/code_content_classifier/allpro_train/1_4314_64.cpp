#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int s,t;
ll comb[2010][2010],prec[2010][2010],prec2[2010][2010],ret=1;
ll choose(int len,int rem) {
	if (rem==0||rem==len) return 1;
	else {
		ll w=0;
		int emp=len-rem;
		int d=min(emp,rem-1);
//		rep(j,0,d+1) w=(w+(comb[rem-1][j])*(emp+1-j))%mod;
		w=(emp+1)*prec[rem-1][d]-prec2[rem-1][d];
		return w%mod;
	}
}
int main() {
	scanf("%d%d",&s,&t);
	comb[0][0]=1;
	prec[0][0]=1;
	prec2[0][0]=0;
	rep(i,1,t+1) {
		comb[i][0]=comb[i][i]=1;
		rep(j,1,i) {
			comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
			if (comb[i][j]>=mod) comb[i][j]-=mod;
		}
		prec[i][0]=1,prec2[i][0]=0;
		rep(j,1,i+1) {
			prec[i][j]=(prec[i][j-1]+comb[i][j])%mod;
			prec2[i][j]=(prec2[i][j-1]+comb[i][j]*j)%mod;
		}
	}
	rep(i,0,s) rep(j,1,t+1) {
		int len=(s-i),rem=(t-j);
		if (rem>len) continue;
//		printf("%d %d %d %d %lld\n",i,j,len,rem,choose(len,rem));
		ret=(ret+comb[t-1][j-1]*choose(len,rem))%mod;
	}
	if (ret<0) ret+=mod;
	printf("%lld\n",ret);
}

#include<cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

typedef long long ll;

ll gcd(ll a,ll b){ return b?gcd(b,a%b):a; }
ll lcm(ll a,ll b){ return a/gcd(a,b)*b; }

int main(){
	for(int n,m;scanf("%d%d",&n,&m),n;){
		int p[20];
		rep(i,m) scanf("%d",p+i);

		ll sum=0,tot=0;
		rep(S,1<<m){
			ll L=1,pc=0;
			rep(i,m) if(S&(1<<i)) L=lcm(L,p[i]), pc++;

			if(L<=n){
				if(pc%2==1) sum-=(L+n)*(n/L)/2, tot-=n/L;
				else        sum+=(L+n)*(n/L)/2, tot+=n/L;
			}
		}
		printf("%.9f\n",tot==0?0:(double)sum/tot);
	}

	return 0;
}
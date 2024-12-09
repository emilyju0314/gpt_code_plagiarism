#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=50+5,M=1e6+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a) memset(a,0,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first 
#define se second
ll x;
ll fun(ll b){
	ll sum=0;
	while(x>=b){
		sum+=x%b;
		x/=b;
	}
	sum+=x;
	return sum;
}
int main(){
	ll n,s;
	cin>>n>>s;
	if(s==n) printf("%lld\n",n+1),exit(0);
	if(s>n) return puts("-1"),0;
	for(ll i=2;i*i<=n;i++){
		x=n;
		if(fun(i)==s){
			printf("%lld\n",i);
			return 0;
		}
	}
	for(ll i=sqrt(n-s);i>=1;i--){
		x=n;
		 if((n-s)%i==0){
		 	ll b=(n-s)/i+1;
		 	if(b>=2&&fun(b)==s) {
			 printf("%lld\n", b);
			 return 0;
			}
		 }
	}
	puts("-1");
	return 0;
}
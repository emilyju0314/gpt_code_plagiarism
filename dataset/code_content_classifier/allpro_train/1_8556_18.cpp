#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int ans;
int fastpow(int x,int a){
	int ret=1;
	while(a){
		if(a&1) ret=ret*1LL*x%mod;
		x=x*1LL*x%mod;a>>=1;
	}
	return ret;
}
 
int ys[50005],yscnt;
int xs[50005];
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			ys[++yscnt]=i;
			if(i*i!=n) ys[++yscnt]=n/i;
		}
	}
	sort(ys+1,ys+yscnt+1);
	for(int i=1;i<=yscnt;i++){
		if(n%2==0&&ys[i]%2!=0) continue;
		ans=(ans + fastpow(k,ys[i]%2==0? n/ys[i]:(n/ys[i]+1)/2)*1LL*(n/ys[i])%mod*(1-xs[i]) )%mod;
		for(int j=i+1;j<=yscnt;j++) if(ys[j]%ys[i]==0) xs[j]=(xs[j]+ (1-xs[i])*1LL*(ys[j]/ys[i]))%mod;
	}
	cout<<(ans+mod)%mod<<endl;
	return 0;
}
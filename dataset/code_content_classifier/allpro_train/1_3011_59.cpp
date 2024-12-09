#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1000000+10,P=1000000007;
ll f[N*2];
int main(){
	ll n,sum=0,ans=0;
	cin>>n;
    f[1]=1;
	for(ll i=1;i<=n;i++){
        f[i]=(f[i]+f[i-1])%P;
        if(i>=3) f[i]=((f[i]+sum-f[i-1]-f[i-2])%P+P)%P;
		if(i<n) ans=(ans+f[i]*(n-1)%P*(n-1)%P)%P;
		if(i<n-1) ans=(ans+f[i]*(i+1)%P)%P;
		else ans=(ans+f[i]*i%P)%P;
		sum=(sum+f[i])%P;
    }
	cout<<ans<<endl;
}


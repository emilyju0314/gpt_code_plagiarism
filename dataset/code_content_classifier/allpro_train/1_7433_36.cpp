#include <bits/stdc++.h>
using namespace std;
const int N=200007;
int n,q,l,r;
long long a[N],v,up,down,ans=0,dif[N];
int main(){
	scanf("%d %d %lld %lld",&n,&q,&up,&down);
	scanf("%lld",&a[0]);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=0;i<n;i++){
		if(a[i]<a[i+1]) ans-=up*abs(a[i]-a[i+1]);
		else ans+=down*abs(a[i]-a[i+1]);
	}
	for(int i=0;i<n;i++){
		dif[i]=a[i]-a[i+1];
	}
	while(q--){
		scanf("%d %d %lld",&l,&r,&v);
		long long old=dif[l-1];
		dif[l-1]-=v;
		if(old<0) ans+=up*(-old);
		else ans-=down*old;
		if(dif[l-1]<0) ans-=up*(-dif[l-1]);
		else ans+=down*dif[l-1];
		if(r<n){
			old=dif[r];
			dif[r]+=v;
			if(old<0) ans+=up*(-old);
			else ans-=down*old;
			if(dif[r]<0) ans-=up*(-dif[r]);
			else ans+=down*dif[r];
		}
		printf("%lld\n",ans);
	}
}
#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
    char c=getchar();bool f=0;x=0;
    while(!isdigit(c)) f|=c=='-',c=getchar();
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
    if(f) x=-x;return x;
}
template<class t> inline void write(t x){
    if(x<0) putchar('-'),write(-x);
    else{if(x>9) write(x/10);putchar('0'+x%10);}
}

#define int long long

const int N=2e5+5,mod=998244353;
int A[N],B[N],S[N],a[N],ans,n;

bool ok(int o,int x,int i){
	if(o==0) return B[x]+S[i]-S[x]-A[i]>0;
	if(o==1) return B[x]+S[i]-S[x]-A[i]+2*a[0]>0;
	if(o==2) return B[x]+S[i]-S[x]-A[i]-2*a[n-1]>0;
	if(o==3) return B[x]+S[i]-S[x]-A[i]+2ll*(a[0]-a[n-1])>0;
}

int calc(int L,int R,int o){
	int l=0,r=R-L>>1,ans=-1;
	while(l<=r){
		int mid=l+r>>1;
		if(ok(o,L+mid*2,L)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	return ans+1;
}

void doit(){
	read(n);
	ans=0;
	for(int i=0;i<n;i++) read(a[i]);
	A[0]=B[n]=S[0]=0;
	for(int i=0;i<n;i++) A[i+1]=A[i]+a[i];
	for(int i=n-1;~i;i--) B[i]=B[i+1]+a[i];
	for(int i=0;i<n;i++) S[i+1]=a[i]-S[i];
	for(int i=0;i<=n;i++) ans+=calc(i,n,0);
	for(int i=3;i<=n;i++) ans+=calc(i,n,1);
	for(int i=0;i<=n-3;i++) ans+=calc(i,n-3,2);
	for(int i=3;i<=n-3;i++) ans+=calc(i,n-3,3);
	for(int i=2;i<=n-2;i++) ans+=A[i]>B[i];
	write(ans%mod);puts("");
}

signed main(){
	int t;
	read(t);
	while(t--) doit();
}
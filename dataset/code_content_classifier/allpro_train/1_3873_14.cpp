#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int mo=1000000007;
const int N=1<<19|5;
int n,p[N],w[N],s[N],ans;
void insert(int p,int v){
	for (;p!=1;p>>=1)
		v=1ll*v*p%mo,s[p]=(s[p]+v)%mo;
}
void update(int p,int v){
	for (;p!=1;p>>=1){
		v=1ll*v*p%mo;
		ans=(ans+1ll*v*s[p^1]%mo*(p>>1))%mo;
	}
}
void solve(int k,int l,int r){
	if (l!=r){
		int mid=(l+r)/2;
		solve(k*2,l,mid);
		solve(k*2+1,mid+1,r);
		For(i,l,mid) insert(p[i]+(1<<(n-1))-1,w[i]);
		For(i,mid+1,r) update(p[i]+(1<<(n-1))-1,1ll*w[i]*k%mo);
		For(i,l,mid) insert(p[i]+(1<<(n-1))-1,mo-w[i]);
	}
	For(i,l,r)
		w[i]=1ll*w[i]*k%mo;
}
int main(){
	scanf("%d",&n);
	For(i,0,(1<<(n-1))-1) scanf("%d",&p[i]);
	For(i,0,(1<<(n-1))-1) w[i]=1;
	solve(1,0,(1<<(n-1))-1);
	cout<<ans<<endl;
}
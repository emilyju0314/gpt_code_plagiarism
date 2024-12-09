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
const int N=200005;
int n,b[N],B[N];
ll a[N],A[N],c[N];
double res[N];
pll q[N];
bool cmp(pll a,pll b,pll c){
	c.fi-=a.fi; c.se-=a.se;
	b.fi-=a.fi; b.se-=a.se;
	return 1ll*c.fi*b.se<=1ll*b.fi*c.se;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&A[i]);
	For(i,1,n) scanf("%d",&B[i]);
	int p=max_element(A+1,A+n+1)-A;
	For(i,0,n) a[i]=A[(i+p-1)%n+1];
	For(i,0,n) b[i]=B[(i+p-1)%n+1];
	c[0]=c[1]=0;
	For(i,1,n-1) c[i+1]=2*c[i]+2*b[i]-c[i-1];
	int t=0;
	For(i,0,n){
		for (;t>1&&cmp(q[t-1],q[t],pll(i,a[i]-c[i]));--t);
		q[++t]=pll(i,a[i]-c[i]);
	}
	//For(i,1,t) cout<<q[i].fi<<' '<<q[i].se<<endl;
	For(i,1,t-1)
		For(j,q[i].fi,q[i+1].fi)
			res[j]=q[i].se+(q[i+1].se-q[i].se)/1.0/(q[i+1].fi-q[i].fi)*(j-q[i].fi);
	double sum=0;
	For(i,1,n){
		sum+=res[i]+c[i];
		//cout<<res[i]+c[i]<<' '<<b[i]<<' '<<a[i]<<endl;
	}
	printf("%.10lf\n",sum/n);
}
/*
c[i-1]-c[i]
*/
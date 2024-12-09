#include<bits/stdc++.h>
 
using namespace std;
#define ll long long
 
const int N = 5005, P = 1000000007;
int n, m, cnt, ans, c[N], a[N], f[N], siz[N], g[N][N];
bool b[N];
int find(int x){ return f[x]==x?x:f[x]=find(f[x]);}
int Pow(ll x, int y=P-2){
	int ans=1;
	for(; y; y>>=1, x=x*x%P) if(y&1) ans=ans*x%P;
	return ans;
}
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) f[i]=i;
	for(int i=1; i<=n; ++i){
		scanf("%d", a+i);
		if(~a[i]) f[find(i)]=find(a[i]);
	}
	for(int i=1; i<=n; ++i) ++siz[find(i)], b[find(i)]|=a[i]==-1;
	for(int i=1; i<=n; ++i) if(find(i)==i){
		if(b[i]) c[++m]=siz[i];
		else ++cnt;
	}
	g[0][0]=1;
	for(int i=1; i<=m; ++i) for(int j=0; j<=i; ++j){
		g[i][j]=(ll)g[i-1][j]*(n-1)%P;
		if(j>1) g[i][j]=(g[i][j]+(j-1ll)*c[i]%P*g[i-1][j-1])%P;
		if(j==1) g[i][j]=(g[i][j]+(ll)g[i-1][j-1]*c[i])%P;
	}
	for(int i=2; i<=m; ++i) (ans+=g[m][i])%=P;
	for(int i=1; i<=m; ++i) ans=(ans+(ll)(c[i]-1)*Pow(n-1, m-1))%P;
	printf("%lld\n", ((ll)Pow(n-1, m)*(n-cnt)+P-ans)%P);
	return 0;
}
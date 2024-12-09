#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
template <class T>
inline void rd(T &x) {
	x=0; char c=getchar(); int f=1;
	while(!isdigit(c)) { if(c=='-') f=-1; c=getchar(); }
	while(isdigit(c)) x=x*10-'0'+c,c=getchar(); x*=f;
}
const int N=610,mod=1e9+7;
inline void Add(int &x,int y) { x+=y; if(x>=mod) x-=mod; }
inline void Dec(int &x,int y) { x-=y; if(x<0) x+=mod; }
int f[N][N],g[N][N],h[N][N],fac[N];
int A[N],B[N];
int n,m;
bool In(int x,int l,int r) { return x>=l&&x<=r; }
int main() {
	rd(n),rd(m);
	for(int i=1;i<=m;++i) rd(A[i]),rd(B[i]);
	fac[0]=1;
	for(int i=2;i<=2*n;i+=2) fac[i]=fac[i-2]*(ll)(i-1)%mod;
	for(int i=1;i<=2*n;++i)
		for(int j=i+1;j<=2*n;j+=2) {
			int tot=0,flg=1;
			for(int k=1;k<=m;++k) {
				flg&=In(A[k],i,j)==In(B[k],i,j);
				tot+=In(A[k],i,j)+In(B[k],i,j);
			}
			if(!flg) continue;
			g[i][j]=fac[j-i+1-tot];
			h[i][j]=fac[2*n-m*2-(j-i+1-tot)];
//			cout<<2*n-m*2-(j-i+1-tot)<<' '<<g[i][j]<<' '<<g[j][i]<<endl;
		}
	int ans=0;
	for(int len=2;len<=2*n;len+=2)
		for(int i=1;i+len-1<=2*n;++i) {
			int j=i+len-1;
			f[i][j]=g[i][j];
			for(int k=i+1;k<j;k+=2)
				Dec(f[i][j],f[i][k]*(ll)g[k+1][j]%mod);
			Add(ans,f[i][j]*(ll)h[i][j]%mod);
		}
	printf("%d",ans);
	return 0;
}
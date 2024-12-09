#include<bits/stdc++.h>
using namespace std;
template<typename T>inline T read(){
	T f=0,x=0;char c=getchar();
	while(!isdigit(c)) f=c=='-',c=getchar();
	while(isdigit(c)) x=x*10+c-48,c=getchar();
	return f?-x:x;
}
namespace run{
	const int N=59,mod=1e9+7;
	inline int add(int x,int y){return x+y>=mod?x-mod+y:x+y;}
	inline void addto(int &x,int y){x=x+y>=mod?x-mod+y:x+y;}
	inline int sub(int x,int y){return x>=y?x-y:x+mod-y;}
	inline int qpow(int x,int y){
		int ret=1;
		while(y){
			if(y&1) ret=1LL*x*ret%mod;
			x=1LL*x*x%mod,y>>=1;
		}
		return ret;
	}

	int C[N][N],n,f[N][N];
	int main(){
		n=read<int>();
		C[0][0]=1;
		for(int i=1;i<=n;i++){
			C[i][0]=1;
			for(int j=1;j<=i;j++)
				C[i][j]=add(C[i-1][j],C[i-1][j-1]);
		}

		f[1][0]=f[1][1]=n;
		for(int i=1;i<n;i++)
			for(int j=0;j<=i;j++)
				for(int k=max(j,1);k<=n-i;k++) if(~(k-j)&1){
					int d=(k-j)/2;
					for(int x=0;x<=k;x++)
						addto(f[i+k][abs(x-d)],1LL*f[i][j]*C[n-i][k]%mod*C[k][x]%mod);
				}
		printf("%d\n",f[n][0]);
		return 0;
	}
}
int main(){
#ifdef my
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	return run::main();
}
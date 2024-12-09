#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3005,p=1000000007,inv2=(p+1)/2,inf=0x3f3f3f3f;
int read(){
	int f=1,g=0;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;
	for (;isdigit(ch);ch=getchar()) g=g*10+ch-'0';
	return f*g;
}
int qpow(int x,int k){
	int t=1;
	for (;k;k>>=1){
		if (k&1) t=(ll)t*x%p;
		x=(ll)x*x%p;
	}
	return t;
}
int n,m,ans,a[N],f[N][N];
void check(int &x,int y){if ((x+=y)>=p) x-=p;}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) f[i][j]=(a[i]>a[j]);
	for (int k=1;k<=m;k++){
		int x=read(),y=read();
		f[x][y]=f[y][x]=(ll)(f[x][y]+f[y][x])*inv2%p;
		for (int i=1;i<=n;i++)
		if ((i!=x)&&(i!=y)){
			f[x][i]=f[y][i]=(ll)(f[x][i]+f[y][i])*inv2%p;
			f[i][x]=f[i][y]=(ll)(f[i][x]+f[i][y])*inv2%p;
		}
	}
	ans=0;
	for (int i=1;i<=n;i++)
	for (int j=i+1;j<=n;j++) check(ans,f[i][j]);
	ans=(ll)ans*qpow(2,m)%p;
	printf("%d\n",ans);
	return 0;
}
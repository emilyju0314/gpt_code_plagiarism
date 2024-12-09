#include<bits/stdc++.h>
using namespace std;
const int N=200;
typedef long long LL;
LL f[N][N];
int r[N],s[N],v[N];
int main(){
	int n,a,b;
	cin>>n>>a>>b;
	for(int i=1;i<=n;++i){
		cin>>r[i]>>s[i];
		v[i]=v[i-1]+s[i];
	}
	memset(f,63,sizeof f);
	for(int i=n;i;--i){
		int d=v[n]-v[i-1];
		for(int j=0;j<=d;++j)
			f[i][j]=min(
			-f[i+1][d-j+1]-r[i]+1,
			max(f[i+1][j]+r[i]+1,1ll));
	}
	int ans=0;
	for(int i=0;i<=v[n];++i)
		if(f[1][i]<=a-b)
			ans=i;
	cout<<ans<<" "<<v[n]-ans<<endl;
}
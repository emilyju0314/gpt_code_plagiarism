#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll a[405],sum[405];
ll f[405][405];
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int len=2;len<=n;++len){
		for(int L=1;L<=n-len+1;++L){
			int R=L+len-1;
			f[L][R]=(1ll<<60);
			for(int k=L;k<R;++k){
				f[L][R]=min(f[L][R],f[L][k]+f[k+1][R]+sum[R]-sum[L-1]);
			}
		} 
	}
	cout<<f[1][n]<<'\n';
	return 0;
}
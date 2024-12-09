#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define add(a,b) a=(a+b)%mod;
#define lol(i,n) for(ll i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;

using namespace std;
#define N 3010
ll f[N][N],g[N][N],n,m;
int main(){
    lol(i,N)lol(j,N)f[i][j]=g[i][j]=0;
    cin>>n>>m;
    if(n==1){
	ll ans=2;
	lol(i,m)ans=ans*2%mod;
	cout<<ans<<endl;
	return 0;
    }
    for(ll i=1;i<=n;i++)f[0][i]=1; g[0][0]=1;
    for(ll i=0;i<m;i++){
	for(ll j=0;j<=n;j++){
	    for(ll k=j-1;k<=j+1;k++){
		if(k<0||k>n)continue;
		ll vf=((k==j&&j!=1&&j!=n)?2:1);
		ll vg=((k==j&&j!=0&&j!=n)?2:1);
		if(k>=1)add(f[i+1][k],f[i][j]*vf);
		if(k==0){
		    add(g[i+1][0],f[i][j]);
		    add(g[i+1][1],f[i][j]);
		}
		add(g[i+1][k],g[i][j]*vg);
	    }
	}
    }
    ll ans=0;
    for(ll i=0;i<=n;i++)add(ans,g[m][i]);
    cout<<ans<<endl;
    return 0;
}

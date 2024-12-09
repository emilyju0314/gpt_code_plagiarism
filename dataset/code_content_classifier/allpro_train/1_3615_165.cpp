#include<bits/stdc++.h>
typedef long long ll;
const int N=45;
ll f[N][N][N],ans;
int n,i,j,k,l,r,p,q,l2,r2;
char c[N][N];
int main(){
	scanf("%d",&n);for(i=1;i<=n*2;++i)scanf("%s",c[i]+1),f[i][i][i]=1;
	for(i=2;i<n*2;i+=2)for(j=1;j+i<=n*2;++j){
		l=j;r=j+i;
		for(l2=l;l2+1<r;++l2)for(r2=l2+2;r2<=r;++r2){
			ll s=0;
			for(p=l;p<=l2;++p)for(q=r2;q<=r;++q)if(c[p][q]=='1')s+=f[l][l2][p]*f[r2][r][q];
			for(p=l2+1;p<r2;++p)f[l][r][p]+=s*f[l2+1][r2-1][p];
		}
	}
	for(k=2;k<=n*2;++k)if(c[1][k]=='1')ans+=f[2][n*2][k];
	printf("%lld\n",ans);
}
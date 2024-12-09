using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define N 20005
#define K 30
#define INF 1000000000
int n,Q;
int a[N];
typedef pair<int,int> info;
int f[15][K+1][N];
info h[15][N];
void inith(){
	for (int j=1;1<<j<=n;++j)
		for (int i=1;i+(1<<j)-1<=n;++i)
			h[j][i]=max(h[j-1][i],h[j-1][i+(1<<j-1)]);
}
int lg[N];
int qryh(int l,int r){
	int m=lg[r-l+1];
	return max(h[m][l],h[m][r-(1<<m)+1]).se;
}
int g[K+1],d[K+1];
int main(){
	scanf("%d%d",&n,&Q);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	lg[1]=0;
	for (int i=2;i<=n;++i)
		lg[i]=lg[i>>1]+1;
	for (int i=1;i<=n;++i)
		h[0][i]=mp(min(i+a[i],n),i);
	inith();
	for (int k=0;k<=K;++k)
		for (int i=1;i<=n;++i)
			f[0][k][i]=min(i+a[i]+k,n);
	for (int j=1;j<=14;++j)
		for (int k=0;k<=K;++k)
			for (int i=1;i<=n;++i){
				int tmp=i;
				for (int t=0;t<=k;++t)
					tmp=max(tmp,f[j-1][k-t][qryh(i,f[j-1][t][i])]);
				f[j][k][i]=tmp;
			}
	while (Q--){
		int l,r,c;
		scanf("%d%d%d",&l,&r,&c);
		if (l==r){
			printf("0\n");
			continue;
		}
		if (l+a[l]+c>=r){
			printf("1\n");
			continue;
		}
		for (int k=0;k<=c;++k)
			g[k]=l+a[l]+k;
		int ans=0; 
		for (int j=14;j>=0;--j){
			bool bz=0;
			for (int k=0;k<=c && !bz;++k){
				d[k]=g[k];
				for (int t=0;t<=k;++t)
					d[k]=max(d[k],f[j][k-t][qryh(l,g[t])]);
				bz|=(d[k]>=r);
			}
			if (bz) continue;
			ans+=1<<j;
			memcpy(g,d,sizeof(int)*(c+1)); 
		}
		printf("%d\n",ans+2);
	}
	return 0;
}








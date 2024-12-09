#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
const int N=1505;
int b[N][N],S[N],n,u[N][N],l[N],r[N];
char A[N][N];
bool flag[N][N];
int main(){
	scanf("%d",&n);
	for (register int i=1;i<=n;++i)scanf("%s",A[i]+1);
	for (register int i=1;i<=n;++i)
		for (register int j=1;j<=n;++j)flag[i][j]=A[i][j]>='0'&&A[i][j]<='9',b[i][j]=A[i][j]-'0';
	for (register int i=0;i<=n;++i)
		for (register int j=0;j<=n;++j)u[i][j]=flag[i][j]?min(i,min(u[i-1][j],u[i][j-1])):1<<30;
	long long ans=0;
	for (register int x=1;x<=n;++x){
		for (register int j=1;j<=n;++j)S[j]=S[j-1]+(u[x][j]<=x?b[x][j]:0);
		for (register int j=n+1;j;--j){
			if (flag[x][j]){
				l[j]=j-1;
				r[j]=max(r[j+1],j);
				ans+=b[x][j]*(S[r[j]]-S[l[j]]-b[x][j]);
			}
			else l[j]=1e9,r[j]=-1;
		}
		for (register int i=x-1;i;--i){
			for (register int j=1;j<=n;++j)S[j]=S[j-1]+(u[x][j]<=i?b[x][j]:0);
			for (register int j=n+1;j;--j){
				if (flag[i][j]){
					l[j]=min(l[j+1],l[j]);
					r[j]=max(r[j+1],r[j]);
					if (l[j]<=r[j])ans+=b[i][j]*(S[r[j]]-S[l[j]]);
				}
				else l[j]=1e9,r[j]=-1;
			}
		}
	}
	printf("%lld\n",ans);
}

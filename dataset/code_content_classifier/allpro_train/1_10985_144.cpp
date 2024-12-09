// awesome imos method!!!

#include<cstdio>
#include<cstdlib>
#include<cstring>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	int *nail[5002];
	rep(i,n+2){
		nail[i]=(int *)malloc((i+3)*sizeof(int));
		memset(nail[i],0,sizeof nail[i]);
	}

	rep(i,m){
		int a,b,x; scanf("%d%d%d",&a,&b,&x); a--; b--;
		nail[a][b]++;
		nail[a][b+1]--;
		nail[a+x+1][b]--;
		nail[a+x+2][b+1]++;
		nail[a+x+1][b+x+2]++;
		nail[a+x+2][b+x+2]--;
	}
	rep(i,n+2) rep(j,i+1) nail[ i ][j+1]+=nail[i][j];
	rep(i,n+1) rep(j,i+1) nail[i+1][ j ]+=nail[i][j];
	rep(i,n+1) rep(j,i+1) nail[i+1][j+1]+=nail[i][j];

	int ans=0;
	rep(i,n) rep(j,i+1) if(nail[i][j]>0) ans++;
	printf("%d\n",ans);

	return 0;
}
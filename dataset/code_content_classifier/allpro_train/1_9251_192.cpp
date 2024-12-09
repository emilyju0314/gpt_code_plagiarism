#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define calc(xl,xr,yl,yr) (sum[xr][yr]-sum[xl-1][yr]-sum[xr][yl-1]+sum[xl-1][yl-1])
const int N=105;
int n,m,ex,ey,ans,sum[N][N],f[2][N][N][N];
char s[N][N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++){
			sum[i][j]=sum[i][j-1];
			if(s[i][j]=='E'){
				ex=i;
				ey=j;
			}else if(s[i][j]=='o'){
				sum[i][j]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			sum[i][j]+=sum[i-1][j];
		}
	}
	int sta=0;
	for(int i=1;i<=n;i++,sta^=1){
		for(int j=n;j>=i;j--){
			for(int k=1;k<=m;k++){
				for(int l=m;l>=k;l--){
					if(i-1>=1&&((i-1<=ex&&j+ex-(i-1)<=n)||(i-1>=ex&&j-((i-1)-ex)>=1))){
						f[sta][j][k][l]=max(f[sta][j][k][l],f[sta^1][j][k][l]+calc(i-1,i-1,max(k,ey-(m-l)),min(l,ey+k-1)));
					}
					if(j+1<=n&&((j+1<=ex&&i+ex-(j+1)<=n)||(j+1>=ex&&i-((j+1)-ex)>=1))){
						f[sta][j][k][l]=max(f[sta][j][k][l],f[sta][j+1][k][l]+calc(j+1,j+1,max(k,ey-(m-l)),min(l,ey+k-1)));
					}
					if(k-1>=1&&((k-1<=ey&&l+ey-(k-1)<=m)||(k-1>=ey&&l-((k-1)-ey)>=1))){
						f[sta][j][k][l]=max(f[sta][j][k][l],f[sta][j][k-1][l]+calc(max(i,ex-(n-j)),min(j,ex+i-1),k-1,k-1));
					}
					if(l+1<=m&&((l+1<=ey&&k+ey-(l+1)<=m)||(l+1>=ey&&k-((l+1)-ey)>=1))){
						f[sta][j][k][l]=max(f[sta][j][k][l],f[sta][j][k][l+1]+calc(max(i,ex-(n-j)),min(j,ex+i-1),l+1,l+1));
					}
					if(i==j&&k==l){
						ans=max(ans,f[sta][j][k][l]+(s[i][k]=='o'));
					}
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
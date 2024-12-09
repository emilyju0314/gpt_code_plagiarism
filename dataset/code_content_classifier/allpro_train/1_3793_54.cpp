#include<cstdio>
const int inf=1<<30,N=100;
int A,B,d[11][11],f[11][11],c[111][111];
void cmax(int&a,int b){b>a?a=b:1;}
void cmin(int&a,int b){b<a?a=b:1;}
int main(){
	scanf("%d%d",&A,&B);
	for(int i=1;i<=A;i++)
		for(int j=1;j<=B;j++)scanf("%d",d[i]+j),f[i][j]=inf;
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			for(int x=1;x<=A;x++)
				for(int y=1;y<=B;y++)cmax(c[i][j],d[x][y]-i*x-j*y);
			for(int x=1;x<=A;x++)
				for(int y=1;y<=B;y++)cmin(f[x][y],i*x+j*y+c[i][j]);
		}
	}
	for(int x=1;x<=A;x++)
		for(int y=1;y<=B;y++)if(f[x][y]!=d[x][y])return puts("Impossible"),0;
	puts("Possible");
	printf("%d %d\n",N+1<<1,(N+1)*(N+1)+N*2);
	for(int i=1;i<=N;i++)printf("%d %d X\n",i,i+1);
	for(int i=N;i>=1;i--)printf("%d %d Y\n",i+N+2,i+N+1);
	for(int i=0;i<=N;i++)
		for(int j=0;j<=N;j++)printf("%d %d %d\n",i+1,j+N+2,c[i][j]);
	printf("%d %d\n",1,N+2);
}
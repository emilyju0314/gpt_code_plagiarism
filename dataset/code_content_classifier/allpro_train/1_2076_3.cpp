#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int p[610];
short dp[2][610][180010];
short rev[2][610][180010];
int dist[180100];
int main(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int i=0;i<a;i++)scanf("%d",p+i);
	for(int i=0;i<2;i++)for(int j=0;j<=a;j++)for(int k=0;k<180010;k++)
		dp[i][j][k]=999;
	int tmp=0;
	for(int i=0;i<b;i++)tmp+=p[i];
	dp[0][b][tmp]=0;
	for(int i=b;i<=a;i++){
		for(int j=1;j>=0;j--){
			for(int k=180000;k>=0;k--){
				if(dp[j][i][k]>900)continue;
				if(a==i&&j==0)continue;
				if(j==0){
					if(dp[0][i+1][k]>dp[j][i][k]){
						dp[0][i+1][k]=dp[j][i][k];
						rev[0][i+1][k]=-1;
					}
					if(dp[1][i+1][k+p[i]]>dp[j][i][k]){
						dp[1][i+1][k+p[i]]=dp[j][i][k];
						rev[1][i+1][k+p[i]]=-2;
					}
				}else{
					for(int l=dp[1][i][k];l<=min(b-1,(int)dp[1][i-1][k]);l++){
						if(dp[0][i][k-p[l]]>l+1){
						//	printf("%d %d %d: %d\n",0,i,k-p[l],l+1);
							dp[0][i][k-p[l]]=l+1;
							rev[0][i][k-p[l]]=l;
						}
					}
				}
			}
		}
	}
	for(int i=0;i<180010;i++)dist[i]=999999999;
	for(int i=0;i<=180000;i++)if(dp[0][a][i]<=b)dist[i]=0;
	for(int i=1;i<=180000;i++)dist[i]=min(dist[i],dist[i-1]+1);
	for(int i=179999;i>=0;i--)dist[i]=min(dist[i],dist[i+1]+1);
	int ret=c;
	int ans=0;
	for(int i=c;i<=d;i++){
		if(dist[i]>ans){
			ans=dist[i];ret=i;
		}
	}
	printf("%d\n",ret);
	vector<int>ind;
	
	int A=0;
	int B=a;
	int C=ret;
	if(ret-ans>=0&&dp[0][a][ret-ans]<=b)C=ret-ans;
	else C=ret+ans;
	
	for(int i=dp[0][a][C];i<b;i++)ind.push_back(i+1);
	while(A!=0||B!=b||C!=tmp){
	
	//	printf("%d %d %d\n",A,B,C);
	//	if(C>180000)break;
		if(rev[A][B][C]==-1)B--;
		else if(rev[A][B][C]==-2){
			ind.push_back(B);
			B--;
			A=0;
			C-=p[B];
		}else{
			int to=dp[A][B][C];
			A=1;
			C+=p[to-1];
			for(int i=dp[A][B][C];i<to-1;i++)ind.push_back(i+1);
		}
	}
	std::sort(ind.begin(),ind.end());
	for(int i=0;i<ind.size();i++){
		if(i)printf(" ");
		printf("%d",ind[i]);
	}
	printf("\n");
}
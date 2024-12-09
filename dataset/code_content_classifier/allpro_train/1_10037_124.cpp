#include<iostream>
using namespace std;
int main(){
	int x,y,dp[18][300];
	for(int i=0;i<18;i++)for(int j=0;j<300;j++)dp[i][j]=0;
	for(int i=1;i<=300;i++){
		dp[1][i]=1;
	}
	for(int i=2;i<=17;i++){
		x=i*i;
		
		for(int j=1;j<=300;j++){
			if(j<x)dp[i][j]=dp[i-1][j];
			else if(j==x)dp[i][j]=dp[i-1][j]+1;
			else dp[i][j]=dp[i-1][j]+dp[i][j-x];
		}
	}
	while(cin>>y&&y>0){
		cout<<dp[17][y]<<endl;
	}
	return 0;
}
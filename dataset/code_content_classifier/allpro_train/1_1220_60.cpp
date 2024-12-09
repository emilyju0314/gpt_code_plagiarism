#include<bits/stdc++.h>
using namespace std;
int h,w;
int mp[1410][1410];
int dp[14010][1410];
int main(){
	cin>>h>>w;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>mp[i][j];
		}
	}
	int Max=0;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			dp[i][j]=(mp[i][j]+1)%2;
			Max|=dp[i][j];
		}
	}
	for(int i=1;i<h;i++){
		for(int j=1;j<w;j++){
			if(mp[i][j]==1){
				dp[i][j]=0;
			}
			else{
				dp[i][j]=min(min(dp[i-1][j],dp[i-1][j-1]),dp[i][j-1])+1;
			    if(dp[i][j]>Max){
			    	Max=dp[i][j];
				}
			}
		}
	}
	cout<<Max*Max<<endl;
	
	
	return 0;
} 


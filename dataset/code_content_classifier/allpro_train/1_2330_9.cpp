#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(){

	bool dp[1000001];
	int a,b,n;
	while(cin>>n>>a>>b&&!(n==0&&a==0&&b==0)){
		memset(dp,0,sizeof(dp));
		dp[0]=dp[a]=dp[b]=true;
		int cnt=0;
		for(int i = 1; i <= n; i++){
			if(i==a||i==b){
				cnt++;
				continue;
			}
			if(i-a>=0){
				dp[i]=dp[i-a];
				if(dp[i])
					cnt++;
			}
			if(!dp[i]&&i-b>=0){
				dp[i]=dp[i-b];
				if(dp[i])
					cnt++;
			}
		}
		cout<<n-cnt<<endl;
	}

	return 0;
}
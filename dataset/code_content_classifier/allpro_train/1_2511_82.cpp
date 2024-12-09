#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MOD=1e9+7;

int main()
{
	for(int n,t;cin>>n>>t;){
		vector<int> ds(n);
		for(int i=0;i<n;i++) cin>>ds[i];
		
		sort(begin(ds),end(ds));
		
		vector<int> dp(n);
		dp[0]=1;
		for(int i=1;i<n;i++){
			int j=lower_bound(begin(ds),end(ds),ds[i]-t)-begin(ds);
			dp[i]=((long long)dp[i-1]*(i-j+1))%MOD;
		}
		cout<<dp[n-1]<<endl;
	}
}
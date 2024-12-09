#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
map<string,int>dp;
int DP(string s){
	if(s.empty())return 1;
	if(dp.count(s))return dp[s];
	int res=1LL*(1+(s[0]=='1'))*DP(s.substr(1))%mod;
	for(int i=1;i<s.size();++i){
		for(int j=i*2;j<=s.size();j+=i){
			string t(i,'1');
			for(int k=0;k<j;k+=i){
				for(int l=k;l<k+i;++l){
					t[l-k]=min(t[l-k],s[l]);
				}
			}
			res=(res+1LL*DP(t)*DP(s.substr(j))%mod)%mod;
		}
	}
	return dp[s]=res;
}
int main(){
	string s;cin>>s;
	cout<<DP(s)<<endl;
	return 0;
}
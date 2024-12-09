#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)

void amax(int& x,int y){if(x<y)x=y;}

signed main(){
int n,m;cin>>n>>m;
vector<int>a(m);
for(auto&& u:a)cin>>u;
sort(begin(a),end(a),greater<int>());

vector<int>dp(n+15,-1);
dp[0]=0;

vector<int> digit={0,2,5,5,4,5,6,3,7,6};
rep(i,n){
if(dp[i]<0)continue;
for(auto&& u:a){
amax(dp[i+digit[u]],dp[i]+1);
}
}
//rep(i,30)cerr<<dp[i]<<" ";
//cerr<<endl;
int num=dp[n];
int cnt=n;
//cerr<<num;
rep(i,num){
for(auto&& u:a){
if(cnt-digit[u]>=0&&dp[cnt]==dp[cnt-digit[u]]+1){
	cout<<u;cnt-=digit[u];break;
}
}
}
cout<<endl;	
}


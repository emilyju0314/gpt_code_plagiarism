#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> P;
const ll mod=1e9+7;
const ll inf=1<<29;

const int M=10000;

int n,c;

int main(){
	cin>>n>>c;
	vvi dp(c+1,vi(M+1,-inf));
	dp[0][0]=0;
	for(int i=0;i<n;i++){
		int A,B,C;
		cin>>A>>B>>C;
		vvi DP=dp;
		for(int j=0;j<=c-C;j++) for(int k=0;k<=M;k++){
			int tmp=dp[j][k];
			if(max(tmp+A,k+B)<=M) DP[j+C][max(tmp+A,k+B)]=max(DP[j+C][max(tmp+A,k+B)],min(tmp+A,k+B));
			if(max(tmp+B,k+A)<=M) DP[j+C][max(tmp+B,k+A)]=max(DP[j+C][max(tmp+B,k+A)],min(tmp+B,k+A));
		}
		dp=DP;
	}
	int res=0;
	for(int i=0;i<=c;i++) for(int j=0;j<M;j++) res=max(res,dp[i][j]);
	cout<<res<<endl;
}
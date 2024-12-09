#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)


string str;

bool input(){
	cin>>str;
	return str!="0";
}

const int N = 88888;
const int T = 11;

int dp[N][T];
int solve(){
	rep(i,N)rep(j,T)dp[i][j]=0;
	
	int ans = 0;
	rep(i,str.size()){
		int a = str[i]-'0';
		if(a!=0)dp[i][a]++;
		
		if(i!=0){
			rep(j,T){
				int num = j*10 + a;
				dp[i][num%11] += dp[i-1][j];
			}
		}
		
		ans += dp[i][0];
	}
	/*
	reps(i,-1,str.size()){
		rep(j,T){
			printf("%2d ", i==-1 ? j : dp[i][j]);
		}puts("");
	}*/
	
	return ans;
}

void c_solve(){
	cout<<solve()<<endl;
}

int main(){
	while(input())c_solve();
}
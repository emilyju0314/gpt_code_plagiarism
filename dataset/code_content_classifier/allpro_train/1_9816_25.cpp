#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000000 + 10;
const int mod = 998244353;

long long dp[maxn], sum1[maxn], sum2[maxn];
int main(){
	int n;
	cin >> n;
	n *= 2;
	dp[0] = 1;
	sum1[0] = 1;
	dp[2] = 1;
	sum1[2] = 2;
	for(int i = 2; i <= 2000000; i++){
		int len = (i - 2) + i;
		for(int j = len + len; j <= 2000000; j += len){
			sum2[j] += 1;
		}
	}
	for(int i = 4; i <= 2000000; i++){
		dp[i] = (sum1[i - 2] + sum2[i]) % mod;
		sum1[i] = (sum1[i - 2] + dp[i]) % mod;
	}
//	for(int i = 2; i <= 10 ; i+= 2){
//		printf("dp[%d] = %d\n", i, dp[i]);
//	}
	cout << dp[n] << endl;
	return 0;
}
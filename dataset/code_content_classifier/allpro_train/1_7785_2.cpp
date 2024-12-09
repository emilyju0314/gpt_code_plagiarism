#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <time.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


int a[100],b[100],c[100],d[100];
int dp[101][901][901];


int main(){

	int N;
	scanf("%d",&N);

	int first_a,first_b;
	scanf("%d %d",&first_a,&first_b);

	for(int i = 0; i < N; i++){
		scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
	}

	for(int i = 0; i <= N; i++){
		for(int k = 0; k <= 900; k++){
			for(int p = 0; p <= 900; p++)dp[i][k][p] = -1;
		}
	}

	int BASE = 300;

	dp[0][BASE+first_a][BASE+first_b] = 0;

	for(int i = 0; i < N; i++){
		for(int k = 0; k <= 900; k++){
			for(int p = 0; p <= 900; p++){
				if(dp[i][k][p] == -1)continue;

				dp[i+1][k][p] = max(dp[i+1][k][p],dp[i][k][p]);

				if(k >= a[i]){
					dp[i+1][k-a[i]][p+b[i]] = max(dp[i+1][k-a[i]][p+b[i]],dp[i][k][p]);
				}

				if(p >= c[i]){
					dp[i+1][k][p-c[i]] = max(dp[i+1][k][p-c[i]],dp[i][k][p]+d[i]);
				}
			}
		}
	}

	int ans = 0;
	for(int k = BASE; k <= 900; k++){
		for(int p = BASE; p <= 900; p++)ans = max(ans,dp[N][k][p]);
	}

	printf("%d\n",ans);

	return 0;
}


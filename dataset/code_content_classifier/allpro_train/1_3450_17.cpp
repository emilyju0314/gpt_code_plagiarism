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


ll N,M,T;
ll POW[21],dp[21][1000],table[1000][2];


int main(){
	for(int i = 0; i < 21; i++)POW[i] = pow(2,i);

	for(int i = 0; i < 21; i++){
		for(int k = 0; k < 1000; k++)dp[i][k] = -1;
	}

	scanf("%lld %lld %lld",&N,&M,&T);

	ll tmp;
	dp[0][0] = 0;
	for(int loop = 0; loop < N; loop++){
		scanf("%lld",&tmp);
		dp[0][tmp%T] = max(dp[0][tmp%T],tmp); //余り毎に最大値を求める
	}

	//ダブリング
	for(int i = 0; POW[i+1] <= M;i++){
		for(int a = 0; a < T; a++){
			if(dp[i][a] == -1)continue;
			for(int b = 0; b < T; b++){
				if(dp[i][b] == -1)continue;
				dp[i+1][(a+b)%T] = max(dp[i+1][(a+b)%T],dp[i][a]+dp[i][b]);
			}
		}
	}

	int CURRENT = 0,NEXT = 1;
	for(int i = 0; i < T; i++)table[i][CURRENT] = -1;
	ll rest = M;

	bool FIRST = true;
	//
	for(int i = 20; i >= 0; i--){
		if(rest < POW[i])continue;
		rest -= POW[i];

		if(FIRST){ //初めての場合
			for(int b = 0; b < T; b++){ //dpのループ
				if(dp[i][b] == -1)continue;

				table[b][CURRENT] = dp[i][b];
			}
			FIRST = false;
			continue;
		}

		for(int k = 0; k < T; k++){
			table[k][NEXT] = -1;
		}

		for(int a = 0; a < T; a++){
			if(table[a][CURRENT] == -1)continue;
			for(int b = 0; b < T; b++){
				if(dp[i][b] == -1)continue;

				table[(a+b)%T][NEXT] = max(table[(a+b)%T][NEXT],table[a][CURRENT]+dp[i][b]);
			}
		}
		swap(CURRENT,NEXT);
	}

	//右から左に情報を伝える
	for(int i = T-2; i >= 0; i--){
		table[i][CURRENT] = max(table[i+1][CURRENT],table[i][CURRENT]);
	}

	int Q;
	scanf("%d",&Q);

	ll A,B;

	for(int loop = 0; loop < Q; loop++){
		scanf("%lld %lld",&A,&B);

		if(table[A][CURRENT] != -1 && table[A][CURRENT]/T >= B){
			printf("yes\n");
		}else{
			printf("no\n");
		}
	}

	return 0;
}


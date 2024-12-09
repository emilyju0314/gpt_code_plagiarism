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


ll dp[51][51];
int E;
ll N;

void func(){
	scanf("%lld %d",&N,&E);

	for(int num = 0; num <= 50; num++){
		if(dp[E][num] >= N){
			printf("%d\n",num);
			return;
		}
	}
}

void makeDP(){

	for(int i = 0; i <= 50; i++){
		for(int k = 0; k <= 50; k++)dp[i][k] = 0;
	}

	for(int i = 1; i <= 50; i++){
		for(int k = 1; k <= 50; k++){
			dp[i][k] = dp[i-1][k-1]+dp[i][k-1]+1;
		}
	}
}

int main(){

	makeDP();

	int test_case;
	scanf("%d",&test_case);

	for(int loop = 0; loop < test_case; loop++){
		func();
	}

	return 0;
}


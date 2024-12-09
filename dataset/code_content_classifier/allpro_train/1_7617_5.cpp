#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


ll N,M;
long double dp[21][121];

long double POW(long double x,ll count){

	if(count == 0){
		return 1.0;
	}else if(count % 2 == 0){
		return POW(x*x,count/2);
	}else{
		return x*POW(x,count-1);
	}
}

void func(){

	long double E = 0.0,next_E,A,P,POW_P;
	ll index = 0,next_index;
	ll left,right,mid;

	while(index < M){

		A = 0;
		P = 0;

		for(ll i = N; i <= 6*N; i++){

			if(i <= E){

				P += dp[N][i];

			}else{

				A += i*dp[N][i];
			}
		}

		if(P == 1.0){
			printf("%.10Lf\n",E);
			return;
		}

		left = index+1,right = M,mid = (left+right)/2;
		next_index = M;

		while(left <= right){

			POW_P = POW(P,mid-index);
			next_E = (A*(1.0-POW_P))/(1.0-P)+POW_P*E;

			if(floor(next_E) > floor(E)){

				next_index = mid;
				right = mid-1;

			}else{
				left = mid+1;
			}
			mid = (left+right)/2;
		}

		POW_P = POW(P,next_index-index);
		next_E = (A*(1.0-POW_P))/(1.0-P)+POW_P*E;

		E = next_E;
		index = next_index;
	}
	printf("%.10Lf\n",E);
}

void calcDP(){

	for(int num = 0; num <= 20; num++){
		for(int value = 0; value <= 120; value++){
			dp[num][value] = 0;
		}
	}

	dp[0][0] = 1.0;
	for(int num = 0; num <= 19; num++){
		for(int value = 0; value <= 114; value++){
			for(int dice = 1; dice <= 6; dice++){
				dp[num+1][value+dice] += dp[num][value]/6.0;
			}
		}
	}
}

int main(){

	calcDP();

	while(true){
		scanf("%lld %lld",&N,&M);
		if(N == 0 && M == 0)break;

		func();
	}

	return 0;
}


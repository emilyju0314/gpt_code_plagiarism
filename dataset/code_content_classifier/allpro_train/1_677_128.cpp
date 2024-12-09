#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

const int MAX_N=100001;


int main(){

	double ret[MAX_N];
	fill(ret,ret+MAX_N,0.0);

	// iツ嘉アツ姪堋づ泳ツ古つ連ツ堕アツつオツづ偲ヲツづェツづゥツ確ツ猟ヲツづーツ格ツ納
	vector<vector<double> > dp;
	vector<double> v(51,0.0);
	for(int i = 0; i < MAX_N; i++){
		dp.push_back(v);
	}
	//double dp[MAX_N][51];
	//for(int i = 0; i < MAX_N; i++)
	//	fill(dp[i],dp[i]+51,0.0);
	dp[1][1]=1.0;
	ret[1]=1.0;
	for(int i = 2; i < MAX_N; i++){
		double ss=0;
		// iツ嘉アツ姪堋づ泳ツ古つ連ツ堕アツつオツづ偲ヲツづェツづゥツ確ツ猟ヲツづーツ計ツ算
		for(int j = 0; j <= min(i,50); j++){
			// ツ債。ツ嘉アツミツス
			if(j==0){
				for(int k = 1; k <= min(i-1,50); k++){
					dp[i][j]+=dp[i-1][k]*(1-pow(0.5,k));
				}
			}
			// ツ連ツ堕アツ偲ヲツ督セ
			else{
				dp[i][j]=dp[i-1][j-1]*(pow(0.5,j-1));
				ss+=dp[i][j];
			}
		}
		ret[i]=ss+ret[i-1];
	}

	int n;
	while(cin>>n&&n!=0){
		//cout<<ret[n]<<endl;
		printf("%.3lf\n",ret[n]);
	}

	return 0;
}
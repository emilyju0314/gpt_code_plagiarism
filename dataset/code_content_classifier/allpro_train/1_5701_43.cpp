#include<iostream>
#include<algorithm>
#include<vector>

const int MAX_N = 15, INF = 1 << 24;
const double EPS = 1e-10;
int ns[16], d[16], cost[16][16], w[16], weight[1<<MAX_N];
int n, next[1<<MAX_N][16];
double dp[1<<MAX_N][16];

double rec(int S, int v){
	if(dp[S][v] > -EPS){
		return dp[S][v];
	}

	if(S == (1 << n) - 1){
		return 0;
	}

	double min_res = INF;
	for(int i=0;i<n;i++){
		if(!(S >> i & 1)){
			double res = (70.0 + weight[S]) * cost[v][i] / 2000.0 + rec(S | (1 << i), i);
			if(res < min_res + EPS){
				min_res = res;
				next[S][v] = i;
			}
		}
	}

	return dp[S][v] = min_res;
}

int main(){
	std::cin >> n;

	for(int i=0;i<n;i++){
		std::cin >> ns[i] >> d[i] >> w[i];
	}

	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if(i >> j & 1){
				weight[i] += w[j];
			}
		}
		weight[i] *= 20;
		std::fill(dp[i], dp[i]+16, -1);
	}

	for(int i=0;i<n;i++){
		cost[n][i] = cost[i][n] = 0;
		for(int j=i+1;j<n;j++){
			cost[i][j] = cost[j][i] = abs(d[i]-d[j]);
		}
	}

	rec(0, n);

	std::vector<int> route;
	int S = 0, u = n;
	while(S != (1 << n) - 1){
		int v = next[S][u];
		S |= (1 << v);
		u = v;
		route.push_back(ns[u]);
	}

	std::cout << route[0];
	for(int i=1;i<route.size();i++){
		std::cout << " " << route[i];
	}
	std::cout << std::endl;
}
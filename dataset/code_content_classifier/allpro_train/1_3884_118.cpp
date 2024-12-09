#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 1e9

int d[101][101];
int n;

void init(){
	for(int i = 0; i < 101; i++){
		for(int j = 0; j < 101; j++)	d[i][j] = INF;
	}
}

void solve(){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++)	d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		}
	}
}

int main(void){
	int np;
	init();
	cin >> n;
	for(int i = 0; i < n; i++){
		int v, e;
		cin >> v >> e;
		for(int j = 0; j < e; j++){
			int t;
			cin >> t;
			d[v][t] = 1;
		}
	}
	solve();
	cin >> np;
	for(int i = 0; i < np; i++){
		int s, g, ttl;
		cin >> s >> g >> ttl;
		if(d[s][g] != INF && d[s][g] + 1 <= ttl){
			printf("%d\n", d[s][g] + 1);
		}else{
			printf("NA\n");
		}
	}
  return 0;
}
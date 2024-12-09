#define _USE_MATH_DEFINES

#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

int N, M;
int data[1001][1001];
int check[1001];

int grp = 1;

int back(int cur) {
	int cnt = 1;
	for (int i = 1; i <= N; ++i) {
		if (data[cur][i] == -1) {
			if (!check[i]) {
				check[i] = true;
				data[cur][i] = data[i][cur] = grp;
				cnt += back(i);
			}
			data[cur][i] = data[i][cur] = grp;
		}
	}
	return cnt;
}

int main(){
	int a, b;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i){
		scanf("%d%d", &a, &b);
		data[a][b] = data[b][a] = -1;
	}
	int shi = 0;
	for (int i = 1; i <= N; ++i) {
		if (check[i]) continue;
		check[i] = 1;
		int res = back(i);
		if (res > 1) {
			grp++;
			shi += res;
		}
	}
	grp--;
	printf("%d\n", abs((N - shi) - grp));
	return 0;
}
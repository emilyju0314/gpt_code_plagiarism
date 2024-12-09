#include<bits/stdc++.h>

using namespace std;

int g1[81][81];
int g2[81][81];
bool dp[81][81][6480];


int main() {
	int H, W;
	cin>>H>>W;
	for (int i = 0;i < H;++i) {
		for (int j = 0;j < W;++j) {
			cin>>g1[i][j];
		}
	}
	
	for (int i = 0;i < H;++i) {
		for (int j = 0;j < W;++j) {
			cin>>g2[i][j];
		}
	}
	
	dp[0][0][abs(g1[0][0] - g2[0][0])] = true;

	for (int i = 0;i < H;++i) {
		for (int j = 0;j < W;++j) {
			for (int k = 0;k < 6399;++k) {
				if (dp[i][j][k]) {
					dp[i][j+1][abs(k - abs(g1[i][j+1] - g2[i][j+1]))] = true;
					dp[i][j+1][abs(k + abs(g1[i][j+1] - g2[i][j+1]))] = true;
					dp[i+1][j][abs(k - abs(g1[i+1][j] - g2[i+1][j]))] = true;
					dp[i+1][j][abs(k + abs(g1[i+1][j] - g2[i+1][j]))] = true;
				}
			}
		}
	}
	
	for (int i = 0;i < 6399;++i) {
		if (dp[H-1][W-1][i]) {
			cout<<i<<endl;
			break;
		}
	}
	
	return 0;
}

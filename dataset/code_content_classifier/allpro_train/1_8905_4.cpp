#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int N, M;
char field[3005][3005];
ll ans;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0;i < N;i++){
		for (int j = 0;j < M;j++){
			cin >> field[i][j];
		}
	}

	ans = 0;

	for (int si = 1;si <= N+M-3;si++){
		int i,j;
		if(si <= N-1){
			i = si; j = 0;
		} else {
			i = N-1; j = si-(N-1);
		}

		ll dp[3005][2][2]; memset(dp, 0, sizeof(dp));
		int idx = 0;

		while(i >= 0 && j < M){
			for (int k = 0;k < 2;k++){
				for (int l = 0;l < 2;l++){
					if(idx == 0 && !(k == 0 && l == 0)) continue;
					if(l == 1 && k == 1) continue;
					dp[idx+1][0][0] = max(dp[idx+1][0][0], dp[idx][k][l]);
					if(field[i][j] != 'G') continue;
					if(i-1 >= 0 && i+1 < N && field[i-1][j] == 'R' && field[i+1][j] == 'W' && l == 0){
						dp[idx+1][1][0] = max(dp[idx+1][1][0], dp[idx][k][l] + 1);
					}
					if(j-1 >= 0 && j+1 < M && field[i][j-1] == 'R' && field[i][j+1] == 'W' && k == 0){
						dp[idx+1][0][1] = max(dp[idx+1][0][1], dp[idx][k][l] + 1);
					}
				}
			}
			i--; j++;
			idx++;
		}

		ll MAX = -1;;
		for (int k = 0;k < 2;k++){
			for (int l = 0;l < 2;l++){
				MAX = max(MAX, dp[idx][k][l]);
			}
		}

		ans += MAX;
	}

	cout << ans << endl;

	return 0;

}


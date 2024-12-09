//品質管理

#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<algorithm>
#include<deque>
#include<queue>
#include<set>
#include<map>

using namespace std;
#define LL long long

int C, N, p[1003][1003], ans = 0, mir;

int main() {
	cin >> C >> N;
	mir = 0;
	for (int i = 0; i < N; i++) {
		string tmp; cin >> tmp;
		for (int j = 0; j < N; j++) p[i][j] = tmp[j]-'0';
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i < N / 2)//縦
				if (p[i][j] == p[N - 1 - i][j])mir++;
			if (j < N / 2)//横
				if (p[i][j] == p[i][N - 1 - j])mir++;;
		}
	}
	if (mir == N * N)ans++;
	for (int i = 1; i < C; i++) {
		int D;
		cin >> D;
		for (int j = 0; j < D; j++) {
			int _i, _j;
			cin >> _i >> _j; _i--; _j--;
			bool t = (p[_i][_j] == p[N - 1 - _i][_j]),
				y = (p[_i][_j] == p[_i][N - 1 - _j]);
			mir += (t ? -1 : 1) + (y ? -1 : 1);
			p[_i][_j] = p[_i][_j] ? 0 : 1;
		}
		if (mir == N * N)ans++;
	}
	cout << ans << endl;
	return 0;
}


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> input_matrix(int h, int w) {
	vector<vector<int>> res(h, vector<int>(w));
	for(int i = 0; i < h; ++i) {
		for(int j = 0; j < w; ++j) {
			cin >> res[i][j];
		}
	}
	return res;
}

int main() {
	int H, W;
	cin >> H >> W;

	const auto a = input_matrix(H, W);
	const auto b = input_matrix(H, W);

	int h, w;
	cin >> h >> w;
	const auto c = input_matrix(h, w);

	int ans = INT_MIN;
	for(int i = 0; i < H - h + 1; ++i) {
		for(int j = 0; j < W - w + 1; ++j) {
			int sum = 0;
			for(int k = 0; k < h; ++k) {
				for(int l = 0; l < w; ++l) {
					if(b[i + k][j + l] != c[k][l]) goto unmatch;
					sum += a[i + k][j + l];
				}
			}
			ans = max(ans, sum);

		unmatch:;
		}
	}

	if(ans == INT_MIN) puts("NA");
	else cout << ans << endl;

	return 0;
}

#include<iostream>
using namespace std;
int Island[52][52];
void solve(int y,int x) {
	Island[y][x] = 0;
	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			if (Island[y + i][x + j]) solve(y + i, x + j);
		}
	}
}
int main() {
	int w,h;
	while (cin >> w >> h&&w&&h) {
		int cnt = 0;
		for (int i = 0; i < h + 2; ++i) {
			for (int j = 0; j < w + 2; ++j) {
				if (i == 0 || j == 0 || i == h + 1 || j == w + 1) Island[i][j] = 0;
				else cin >> Island[i][j];
			}
		}
		for (int i = 1; i < h + 1; ++i) {
			for (int j = 1; j < w + 1; ++j) {
				if (Island[i][j]) {
					solve(i, j);
					++cnt;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}

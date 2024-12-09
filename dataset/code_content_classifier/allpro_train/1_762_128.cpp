#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int sq[1000][1000];
string b[1000];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	while (cin >> n , n) {
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sq[i][j] = b[i][j] == '.' ? 1 : 0;
			}
		}

		int ans = 0;
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < n; j++) {
				if (b[i][j] == '*') continue;
				int m = min(sq[i - 1][j - 1], sq[i - 1][j]);
				m = min(m, sq[i][j - 1]);
				sq[i][j] = m + 1;
				ans = max(ans, sq[i][j]);
			}
		}

		cout << ans << endl;
	}
}
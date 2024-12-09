#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
bool a[10000][721];
int main() {
	int N, M, r, q;
	while (cin >> N >> M&&N != 0 && M != 0) {
		cin >> r;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j <= 720; j++) {
				a[i][j] = false;
			}
		}
		int b[1000][2];
		for (int z = 0; z < r; z++) {
			int t,n, m, s;
			cin >> t >> n >> m >> s;
			m--;
			t -= 540;
			if (s == 1) {
				b[n][0] = t;
				b[n][1] = m;
			}
			else {
				for (int i = b[n][0]; i < t; i++) {
					a[m][i] = true;
				}
			}
		}
		cin >> q;
		for (int z = 0; z < q; z++) {
			int ts, te, m;
			cin >> ts >> te >> m;
			int sum = 0;
			ts -= 540;
			te -= 540;
			m--;
			for (int i = ts; i < te; i++) {
				if (a[m][i]) sum++;
			}
			cout << sum << endl;
		}
	}
} 
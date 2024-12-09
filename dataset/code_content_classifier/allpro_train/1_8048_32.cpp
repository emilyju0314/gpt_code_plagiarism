#include<iostream>
#include<algorithm>
using namespace std;

int n;
int X, Y;
int p[2000], q[2000], x[2000], y[2000];
char c, d; int e;

int main() {
	cin >> n >> X;
	int cnt = 0;
	for (int i = 0; i < X; i++) {
		cin >> c >> e;
		if (c == 'D') {
			p[cnt] = e;
			cnt++;
		}
	}
	cnt = 0;
	cin >> Y;
	for (int i = 0; i < Y; i++) {
		cin >> c >> d >> e;
		if (c == 'D' && d == 'D') {
			q[cnt] = e;
			cnt++;
		}
	}
	sort(p, p + X);
	sort(q, q + Y);
	cnt = 0;
	for (int i = X - 1; i >= 0; i--) {
		cnt++;
		x[cnt] = x[cnt - 1] + p[i];
	}
	cnt = 0;
	for (int i = Y - 1; i >= 0; i--) {
		cnt++;
		y[cnt] = y[cnt - 1] + q[i];
	}
	int maxn = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i + 2 * j <= n) {
				maxn = max(maxn, x[i] + y[j]);
			}
		}
	}
	cout << maxn << endl;
	return 0;
}
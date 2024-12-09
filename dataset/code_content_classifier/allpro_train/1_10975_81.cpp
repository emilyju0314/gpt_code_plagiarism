#include <bits/stdc++.h>
using namespace std;

long c[22];
int main() {
	long L, a, b, M;
	cin >> L >> a >> b >> M;
	for (long i = 0, j = 1; i < 18; i++, j *= 10) {
		long l = -1, r = L;
		while (l + 1 < r) {
			long m = (l + r) / 2;
			if (a + b * m < j) l = m;
			else r = m;
		}
		if (a + b * r < j * 10)
			c[i] = r;
		else if (i) c[i] = c[i - 1];
	}
	c[18] = L;
	long t = 1, S = 0, T = a;
	for (int e = 0; e < 18; e++) {
		(t *= 10) %= M;
		long A[4][3][3] = {};
		for (int i = 0; i < 3; i++)
			A[2][i][i] = 1;
		A[0][0][1] = A[0][1][1] = A[0][2][2] = 1;
		A[0][1][2] = b;
		A[0][0][0] = t;
		int x = 0, y = 2;
		auto f = [&](int &z) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					A[z ^ 1][i][j] = 0;
					for (int k = 0; k < 3; k++)
						(A[z ^ 1][i][j] += A[x][i][k] * A[z][k][j]) %= M;
				}
			}
			z ^= 1;
		};
		for (long k = c[e + 1] - c[e];;) {
			if (k & 1) f(y);
			k >>= 1;
			if (!k) break;
			f(x);
		}
		S = (S*A[y][0][0] + T * A[y][0][1] + A[y][0][2]) % M;
		(T += A[y][1][2]) %= M;
	}
	cout << S << endl;
	return 0;
}

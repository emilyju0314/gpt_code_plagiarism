#include <bits/stdc++.h>
using namespace std;
int n;
int x[107], y[107], h[107];
int X, Y, H;
 
int main() {
	scanf("%d", &n);
	int dd;
	for(int i = 1; i <= n; i++) {
		scanf("%d %d %d", &x[i], &y[i], &h[i]);
		if(h[i]) dd = i;
	}
	for(int i = 0; i <= 100; i++) {
		for(int j = 0; j <= 100; j++) {
			X = i, Y = j;
			H = h[dd] + abs(x[dd] - X) + abs(y[dd] - Y);
			for(int k = 1; k <= n; k++) {
				int t1 = abs(x[k] - X), t2 = abs(y[k] - Y);
				if(h[k] != max(H - t1 - t2, 0)) break;
				if(k == n) {
					printf("%d %d %d\n", X, Y, H);
					return 0;
				}
			}
		}
	}
}
#include "bits/stdc++.h"
using namespace std;

int main() {
	int n; int m; int d;
	while (~scanf("%d%d%d", &n, &m, &d)) {
		double ans = (d == 0 ? n : (n - d) * 2) / ((double)n * n);
		ans *= m - 1;
		printf("%.10f\n", ans);
	}
}

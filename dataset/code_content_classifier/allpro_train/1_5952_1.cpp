#include <bits/stdc++.h>
using namespace std;
int n;
int a[10005], b[10005];
long long ta, tb;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		a[i] -= b[i];
		if (a[i] > 0) ta += a[i];
		else tb += (-a[i]) / 2;
	}
	if (ta > tb) printf("No\n");
	else printf("Yes\n");
	return 0;
}
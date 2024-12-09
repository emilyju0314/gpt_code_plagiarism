#include <bits/stdc++.h>
using namespace std;
int T;
int n, a[500005], ans;
int gcd (int x, int y){
	if (y == 0) return x;
	return gcd (y, x % y);
}
int main ( ){
	scanf ("%d", &T);
	while (T --){
		scanf ("%d", &n);
		for (int i = 1;i <= n;++ i){
			scanf ("%d", &a[i]);
			a[i + n] = a[i];
		}
		ans = 0;
		for (int i = 1;i <= n;++ i){
			int j = i + 1;
			int x = a[i], y = a[j];
			int tot = 0 ;
			while (x != y){
				x = gcd (x, a[j]);
				y = gcd (y, a[j + 1]);
				++ tot;
				++ j;
				//printf ("%d %d\n", x, y);
			}
			ans = max (tot, ans);
			//printf ("\n");
		}
		printf ("%d\n", ans);
	}
	return 0;
}
#include <cstdio>
using namespace std;
int n, ans;
int main() {
	scanf("%d", &n);
	for ( int i = 1, a; i <= n; i ++) {
		scanf("%d", &a);
		while ( !(a & 1)) ans ++, a >>= 1;
	}
	printf("%d\n", ans);
}
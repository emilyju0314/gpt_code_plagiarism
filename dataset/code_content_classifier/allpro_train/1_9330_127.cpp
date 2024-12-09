#include <stdio.h>
long long n, i, a, s=1, d=1e18;
double t=1;
int main(){
	scanf("%lld", &n);
	for(i=1; i<=n; i++){
		scanf("%lld", &a);
		s = s * a;
		t = t * a;
	}
	if(s > d || t > d) printf("-1\n");
	else printf("%lld\n", s);
	return 0;
}
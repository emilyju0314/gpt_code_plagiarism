#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i, s, t) for(i = s; i <= t; ++i)

using namespace std;

typedef long long LL;
LL A, B, C, D, g, mx;

LL gcd(LL a, LL b) {return b? gcd(b, a % b): a;}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
		if(A < B) {puts("No"); continue;}
		if(D < B) {puts("No"); continue;}
		if(C >= B) {puts("Yes"); continue;}
		g = gcd(B, D);
		mx = (B - A%B - 1) / g * g + A%B;
		if(mx > C) puts("No"); else puts("Yes");
	}
	return 0;
} 
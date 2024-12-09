#include <cstdio>

int N, P; char S[200200]; long long cnt[10010];

int inv(int x)
{
	if (x <= 1) return x;
	return (P - P / x) * inv(P % x) % P;
}

int main()
{
	scanf ("%d %d", &N, &P);
	scanf ("%s", S);

	long long ans = 0;
	if (P == 2 || P == 5){
		for (int i = 0; S[i]; i++){
			if ((S[i] - '0') % P == 0) ans += i + 1;
		}
	}
	else{
		cnt[0]++;
		long long s = 0, it = inv(10 % P), g = 1;
		for (int i = 0; S[i]; i++){
			g = g * it % P;
			s = s + (S[i] - '0') * g;
			s %= P;
			ans += cnt[s]++;
		}
	}

	printf ("%lld\n", ans);

	return 0;
}
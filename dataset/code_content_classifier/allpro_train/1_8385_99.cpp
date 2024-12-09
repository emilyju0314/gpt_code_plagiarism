#include <bits/stdc++.h>

using namespace std;

int A[200010], B[200010];

int main()
{
	int n;
	scanf("%d", &n);
	int w = 1, t = n;
	for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
	for(int i = n, b = 0; i >= 1; i--, b ^= 1)
		if(!b) B[w++] = A[i]; else B[t--] = A[i];
	for(int i = 1; i <= n; i++) printf("%d ", B[i]);//rintf("%d ", A[t--]); else printf("%d ", A[w++]);
	return putchar('\n'), 0;
}
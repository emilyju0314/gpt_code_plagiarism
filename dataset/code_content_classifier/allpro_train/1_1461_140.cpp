#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

const int MAXN = 1e3 + 10;
int N;
int A[MAXN];
int ap[MAXN];

int main() {
	register int i;
	scanf("%d", &N);
	for(i = 1; i <= N; ++i)
		scanf("%d", A + i), ++ap[A[i]];
	sort(A + 1, A + N + 1);
	for(i = A[1] + 1; i <= A[N]; ++i)
		if(ap[i] < 2)
			return puts("Impossible"), 0;
	if(ap[A[1]] > 2) return puts("Impossible"), 0;
	if(!(A[N] & 1) && (A[1] == A[2])) return puts("Impossible"), 0;
	if((A[N] & 1) && (A[1] != A[2])) return puts("Impossible"), 0;
	puts("Possible");
	return 0;
}
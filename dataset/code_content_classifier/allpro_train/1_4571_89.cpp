#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

LL N, A;
LL safe_mul(LL x, LL y) {
    if (x == 0 || y == 0) return 0;
    if (N / y < x) return N;
    return x*y;
}

bool ok(LL mid, LL s) {
    LL q = mid / s;
    LL r = mid % s;
    LL m = 1;
    REP (i, s) {
	if (i < r) m = safe_mul(m, q+1);
	else m = safe_mul(m, q);
    }
    return m >= N;
}

void MAIN() {
    scanf("%lld%lld", &N, &A);

    LL ans = N;

    REP (i, 60) {
	if (ans <= A*i) break;
	LL lo = 0;
	LL hi = ans - A*i;
	if (!ok(hi, i+1)) continue;
	while (hi - lo > 1) {
	    LL mid = (hi + lo) / 2;
	    (ok(mid, i+1)? hi: lo) = mid;
	}

	amin(ans, hi + A*i);
    }
    
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}


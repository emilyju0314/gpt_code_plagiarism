#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)

int const N = 200000;
int n;
ll dpl[N + 2], dpr[N + 2], x[N + 1];

struct S{
	ll l, r, fr;
	S(ll x):l(x), r(x), fr(1) {}
	ll operator +=(S const &o){
		ll t = o.l, an = 0, nr = o.r;
		while (r > t)t <<= 2, nr <<= 2, an += o.fr << 1;
		fr += o.fr;
		r = nr;
		return an;
	}
};

void go(ll dp[]){
	ll an = 0;
	deque<S> dq;
	f(i, 1, n + 1){
		S c(x[i]);
		while (!dq.empty() && dq.front().l < c.r)an += (c += dq.front()), dq.pop_front();
		dq.push_front(c);
		dp[i] = an;
	}
}

int main(){
	scanf("%d", &n);
	f(i, 1, n + 1)scanf("%lld", x + i);
	reverse(x + 1, x + n + 1);
	go(dpr);
	reverse(dpr + 1, dpr + n + 1);
	reverse(x + 1, x + n + 1);
	f(i, 1, n + 1)x[i] <<= 1;
	go(dpl);
	f(i, 1, n + 1)dpl[i] += i;
	ll an = 1e18;
	f(i, 0, n + 1)an = min(an, dpl[i] + dpr[i + 1]);
	printf("%lld\n", an);
}
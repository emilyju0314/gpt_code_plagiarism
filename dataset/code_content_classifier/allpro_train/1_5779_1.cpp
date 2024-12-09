#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <map>
using namespace std;

typedef long long ll;
const int MAXN = 36 + 10;
int N;
char S[MAXN];
map<pair<string, string>, ll> mp;
ll ans;

int main() {
	register int s, i;
	scanf("%d%s", &N, S);
	for(s = 0; s < (1 << N); ++s) {
		string s1, s2;
		for(i = 0; i < N; ++i)
			if(s >> i & 1)
				s1.push_back(S[i]);
			else
				s2.push_back(S[i]);
		++mp[make_pair(s1, s2)];
	}
	for(s = 0; s < (1 << N); ++s) {
		string s1, s2;
		for(i = N - 1; ~i; --i)
			if(s >> i & 1)
				s2.push_back(S[N + i]);
			else
				s1.push_back(S[N + i]);
		ans += mp[make_pair(s1, s2)];
	}
	printf("%lld\n", ans);
	return 0;
}
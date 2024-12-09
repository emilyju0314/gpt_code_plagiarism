#include<bits/stdc++.h>
using namespace std;
#define rep1(i,n) for(int i = 1; i < n; i++)
const int md = 1e9+7;
const int mx = 100005;
int n, k, comp[mx], r = 1;
long long dp[mx];
int main(){
	scanf("%d%d", &n, &k);
	for(; r*r <= n; r++) comp[r] = n/r - n/(r+1);
	fill(comp+r,comp+r+n/r, 1);
	r += n/r;
	reverse(comp+1, comp+r);
	for(int i = 0; i < k; i++){
		int temp[mx] = {};
		rep1(j,r) temp[j] = ((i ? dp[r-j] : 1) * comp[j]) % md;
		rep1(j,r) dp[j] = (dp[j-1] + temp[j]) % md;
	}
	printf("%lld\n", dp[r-1]);
}
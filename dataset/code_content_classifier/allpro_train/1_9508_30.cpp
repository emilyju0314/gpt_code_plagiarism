#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;
const lint mod = 1e9 + 7;

int s[210];
lint dp[210][100010];

lint solve(int i, int j){
    if(dp[i][j] >= 0) return dp[i][j];
    return dp[i][j] = ((lint)(i-1)*solve(i-1, j) + solve(i-1, j%s[i-1])) % mod;
}

int main(){
    int n, x;
    scanf("%d%d", &n, &x);
    rep(i, n) scanf("%d", &s[i]);
    sort(s, s+n);
    rep(i, n+1)rep(j, x+1) dp[i][j] = -1;
    rep(j, x+1) dp[0][j] = j;
    printf("%lld\n", solve(n, x));
}
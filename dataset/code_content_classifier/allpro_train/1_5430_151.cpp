#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define PRIM 3
#define INF (1 << 29)
#define LINF (1LL << 60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
typedef long long Int;
typedef pair<Int, Int> P;
typedef long double Real;
typedef complex<Real> CP;

Int dp[5005][5005];
Int dpxsum[5005][5005];
Int dpysum[5005][5005];
Int pow2[5005];
Int ans;
int main() {
    Int n, a, b;
    cin >> n >> a >> b;
    if (a < b)
        swap(a, b);

    pow2[0] = 1;
    for (int i = 1; i <= n; i++)
        pow2[i] = pow2[i - 1] * 2 % MOD;
    if (a == 1 && b == 1) {
        cout << pow2[n] << endl;
        return 0;
    }
    ans = 1;
    for (int i = 1; i <= n; i++) {
        if (i - 1 < b)
            dp[i][i] = 1;
        else
            dp[i][i] = 0;
        for (Int jlen = 1; jlen < b; jlen++) {
            if (i - jlen - 1 < 1)
                continue;
            Int oklen_max = min(i - jlen, a);
            dp[i][i] += dpxsum[i - jlen - 1][i - jlen - 1] -
                        dpxsum[i - jlen - oklen_max][i - jlen - 1];
            dp[i][i] %= MOD;
            /*            for (Int oklen = 1; oklen < min(i - jlen, a); oklen++)
               { dp[i][i] += dp[i - jlen - oklen][i - jlen - 1];
                            }*/
        }

        (dpxsum[i][i] = dpxsum[i - 1][i] + dp[i][i]) %= MOD;
        (dpysum[i][i] = dpysum[i][i - 1] + dp[i][i]) %= MOD;
        for (int j = i + 1; j <= n; j++) {
            if (i == 1 && j - i >= b)
                dp[i][j]++;
            dp[i][j] += dp[i][j - 1];
            Int jlen_min = b, jlen_max = j - i;
            if (jlen_min < jlen_max)
                dp[i][j] +=
                    dpysum[i][j - jlen_min - 1] - dpysum[i][j - jlen_max - 1];
            /*            for (int jlen = b; j - jlen - 1 >= i; jlen++) {
                            dp[i][j] += dp[i][j - jlen - 1];
                            }*/
            dp[i][j] %= MOD;
            if (j - i + 1 >= a) {
                ans += dp[i][j] * pow2[n - j];
                ans %= MOD;
                //                cout << i << " " << j << " " << dp[i][j] <<
                //                endl;
                dp[i][j] = 0;
            }
            (dpxsum[i][j] = dpxsum[i - 1][j] + dp[i][j]) %= MOD;
            (dpysum[i][j] = dpysum[i][j - 1] + dp[i][j]) %= MOD;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (n - i + 1 >= a && n - j >= b) {
                (ans += dp[i][j]) %= MOD;
                //                cout << i << " " << j << " " << dp[i][j] <<
                //                endl;
            }
            //            cout << dp[i][j] << " ";
        }
        //        cout << endl;
    }
    if (ans < 0)
        ans += MOD;
    cout << ans << endl;

    return 0;
}
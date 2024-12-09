#include <bits/stdc++.h>
using namespace std;

int n, sum[128][128], f[128][128];

int solve()
{
        int ans = f[0][0];
        for (int si = 0; si < n; si++) {
                for (int ti = si+1; ti <= n; ti++) {
                        int l = 0, r = 0, s = 0;
                        while(l < n) {
                                if(s < 0) {
                                        l = r;
                                        s = 0;
                                }
                                else if(r < n) {
                                        s += sum[ti][r]-sum[si][r];
                                        r++;
                                        ans = max(ans, s);
                                }
                                else break;
                        }
                }
        }
        return ans;
}

void input()
{
        cin >> n;
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        cin >> f[i][j];
                        sum[i+1][j] = sum[i][j]+f[i][j];
                }
        }
}

int main()
{
        input();
        cout << solve() << endl;
        return 0;
}
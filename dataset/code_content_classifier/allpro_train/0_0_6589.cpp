#include <iostream>
#include <vector>
#include <cstring>

#define MOD 998244353
#define MAX_N 1005

using namespace std;

int n;
char s[MAX_N];
int nxt[MAX_N][2][2][2];
int dp[MAX_N][2][2];

int add(int a, int b) {
    return (a + b) % MOD;
}

void update(int &a, int b) {
    a = add(a, b);
}

int solve() {
    n = strlen(s);
    
    memset(nxt, -1, sizeof(nxt));
    for (int a = 0; a < 2; ++a) {
        for (int b = 0; b < 2; ++b) {
            nxt[0][a][b][0] = add(a, b);
            nxt[0][a][b][1] = add(a, b);
        }
    }
    
    for (int i = 1; i < n - 1; ++i) {
        for (int a = 0; a < 2; ++a) {
            for (int b = 0; b < 2; ++b) {
                for (int p = 0; p < 2; ++p) {
                    for (int q = 0; q < 2; ++q) {
                        if (nxt[i - 1][p][q][0] != -1 && (s[i] == '?' || s[i] == '0' + (nxt[i - 1][p][q][0] >> i & 1))
                            && (s[i + 1] == '?' || s[i + 1] == '0' + (nxt[i - 1][p][q][1] >> i & 1))) {
                            nxt[i][a][b][0] = add(nxt[i][a][b][0], a << i | nxt[i - 1][p][q][0]);
                            nxt[i][a][b][1] = add(nxt[i][a][b][1], b << i | nxt[i - 1][p][q][1]);
                        }
                    }
                }
            }
        }
    }
    
    memset(dp, 0, sizeof(dp));
    dp[0][1][1] = 1;
    for (int i = 0; i < n - 2; ++i) {
        for (int a = 0; a < 2; ++a) {
            for (int b = 0; b < 2; ++b) {
                for (int p = 0; p < 2; ++p) {
                    for (int q = 0; q < 2; ++q) {
                        if (nxt[i][a][b][0] != -1 && (s[i + 1] == '?' || s[i + 1] == '0' + (nxt[i][a][b][0] >> (i + 1) & 1))
                            && (s[i + 2] == '?' || s[i + 2] == '0' + (nxt[i][a][b][1] >> (i + 1) & 1))) {
                            update(dp[i + 1][p][q], dp[i][a][b]);
                        }
                    }
                }
            }
        }
    }
    
    int ans = 0;
    for (int a = 0; a < 2; ++a) {
        for (int p = 0; p < 2; ++p) {
            if (nxt[n - 2][a][a][0] != -1 && (s[n - 1] == '?' || s[n - 1] == '0' + (nxt[n - 2][a][a][0] >> (n - 1) & 1))
                && (s[n] == '?' || s[n] == '0' + (nxt[n - 2][a][a][1] >> (n - 1) & 1))) {
                update(ans, dp[n - 2][p][p]);
            }
        }
    }
    
    return ans;
}

int main() {
    cin >> s;
    cout << solve() << endl;
    return 0;
}
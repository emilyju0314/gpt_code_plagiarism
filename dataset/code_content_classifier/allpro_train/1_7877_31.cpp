#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <complex>
#include <cstring>

using namespace std;

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define X real()
#define Y imag()

// #define DEBUG

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

typedef complex<int> Pos;

int dp[2][2][2001][2001];

int N, K;
string S;

const int INF = 1e9;

/*
void dfs(int n, int k, int pos, bool dir_x, bool plus)
{
    cerr << n << " " << k << " " <<  pos << endl;

    if (~dp[dir_x][plus][n][k]) return dp[dir_x][plus][n][k];
    if (n == N) return dp[dir_x][plus][n][k] = pos;

    int diff;
    if (dir_x) {
        if (S[n] == 'L' || S[n] == 'R') {
            diff = (S[n] == 'R' ? 1 : -1);
        } else {
            diff = 0;
        }
    } else {
        if (S[n] == 'D' || S[n] == 'U') {
            diff = (S[n] == 'U' ? 1 : -1);
        } else {
            diff = 0;
        }
    }

    int mirror = (k%2 == 0 ? 1 : -1);
    int res = dfs(n+1, k, pos + (mirror * diff), dir_x, plus);
    if (k < K) {
        if (plus) res = max(res, dfs(n+1, k+1, pos + (mirror * diff * -1), dir_x, plus));
        else      res = min(res, dfs(n+1, k+1, pos + (mirror * diff * -1), dir_x, plus));
    }

    return dp[dir_x][plus][n][k] = res;
}
*/

int get_diff(char dir, bool dir_x)
{
    int diff;
    if (dir_x) {
        if (dir == 'L' || dir == 'R') {
            diff = (dir == 'R' ? 1 : -1);
        } else {
            diff = 0;
        }
    } else {
        if (dir == 'D' || dir == 'U') {
            diff = (dir == 'U' ? 1 : -1);
        } else {
            diff = 0;
        }
    }
    return diff;
}


int main()
{
    cin >> S >> K;    
    N = S.size();

    rep(dir_x, 2) rep(n, N+1) rep(k, K+1) dp[dir_x][0][n][k] = INF;
    rep(dir_x, 2) rep(n, N+1) rep(k, K+1) dp[dir_x][1][n][k] = -INF;
    rep(dir_x, 2) rep(plus, 2) rep(k, K+1) dp[dir_x][plus][0][k] = 0;
    

    rep(dir_x, 2) rep(plus, 2) {
        rep(n, N) rep(k, K+1) {
            int diff = get_diff(S[n], dir_x);
            int mirror = (k%2 == 0 ? 1 : -1);
            {
                int npos = dp[dir_x][plus][n][k] + mirror * diff;

                if (plus) chmax(dp[dir_x][plus][n+1][k], npos);
                else      chmin(dp[dir_x][plus][n+1][k], npos);
            }
            if (k < K) {
                int npos = dp[dir_x][plus][n][k] + mirror * diff * -1;
                if (plus) chmax(dp[dir_x][plus][n+1][k+1], npos);
                else      chmin(dp[dir_x][plus][n+1][k+1], npos);
            }
        }
    }

    int dp_abs[2][2001] = {};
    rep(k, K+1) {
        rep(dir_x, 2) {
            int mx = max(abs(dp[dir_x][0][N][k]), abs(dp[dir_x][1][N][k]));
            dp_abs[dir_x][k] = max(dp_abs[dir_x][k], mx);
        }
    }

    int ans = 0;
    rep(kx, K+1) {
        rep(ky, K+1) {
            if (kx + ky <= K) {
                ans = max(ans, dp_abs[0][ky] + dp_abs[1][kx]);
            }
        }
    }

    cout << ans << endl;
}
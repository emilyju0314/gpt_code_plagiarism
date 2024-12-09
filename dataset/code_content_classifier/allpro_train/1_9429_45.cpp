#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P,P> PP;
const ll MOD = 1000000007;
const int IINF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = int(2e5 + 5);
const double EPS = 1e-10;
const int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define ALL(v) (v).begin(), (v).end()

int w, h, a[1005][1005], dp[1005][1005];

int rec(bool turn, int i, int j){
    if(i==h && j==w) return 0;
    if(dp[i][j] != -IINF) return dp[i][j];

    int res = IINF*(turn?-1:1);
    if(i<h){
        int tmp = rec(!turn, i+1, j), sum = a[i+1][w] - a[i+1][j] - a[i][w] + a[i][j];
        if(turn) res = max(res, tmp+sum);
        else res = min(res, tmp+sum);
    }
    if(j<w){
        int tmp = rec(!turn, i, j+1), sum = a[h][j+1] - a[h][j] - a[i][j+1] + a[i][j];
        if(turn) res = max(res, tmp-sum);
        else res = min(res, tmp-sum);
    }
    return dp[i][j] = res;
}


int main() {
    cin >> w >> h;
    REP(i,h)REP(j,w) cin >> a[i+1][j+1];
    REP(i,h){
        REP(j,w){
            a[i+1][j+1] += a[i+1][j] + a[i][j+1] - a[i][j];
        }
    }
    
    REP(i,h+1) fill(dp[i],dp[i]+w+1,-IINF);
    cout << abs(rec(true,0,0)) << endl;
    return 0;
}


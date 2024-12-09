#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
using namespace std;

#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)
#define int long long int

template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}

typedef pair<int, int> pii;
typedef long long ll;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
constexpr ll INF = 1001001001001001LL;
constexpr ll MOD = 1000000007LL;

int N, M, board[110][10010];

signed main() {
    cin >> N >> M;
    rep(i,0,M) rep(j,0,N) {
        char c; cin >> c;
        if(c == 'W') board[i+1][j+1] = -1;
        else board[i+1][j+1] = 1;
    }

    rep(i,0,M) rep(j,0,N) board[i+1][j+1] += board[i+1][j];
    rep(j,0,N) rep(i,0,M) board[i+1][j+1] += board[i][j+1];


    int sum = board[M][N], val = -INF, ans;
    repq(i,0,N) {
        int va = board[M][i], vb = sum - va;
        if(val < vb - va) {
            val = vb - va;
            ans = i;
        }
    }
    printf("%lld %lld\n", ans, ans+1);
    return 0;
}
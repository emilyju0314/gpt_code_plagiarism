#include <bits/stdc++.h>
using namespace std;
const int inf = 1e8;
const size_t SIZE = 1010;
int dp[SIZE], dp_buf[SIZE];
int A[SIZE], B[SIZE];

void chmin(int &a, int b) { a = min(a, b); }
void chmax(int &a, int b) { a = max(a, b); }

bool solve() {
    int N, M;
    cin >> N >> M;
    if(N + M == 0) return false;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    
    auto to_push = [&](int i) { return ((M - A[i]) + B[i]) % M; };

    dp[0] = to_push(0);
    for(int i = 1; i <= N; i++) dp[i] = dp[0] + i * M;
    for(int i = 1; i < N; i++) {
        fill(dp_buf, dp_buf + SIZE, inf);
        for(int j = 0; j <= N; j++) {
            int pushed = to_push(i - 1) + j * M;
            for(int diff = -1; diff <= 1; diff++) {
                int want = (j + diff) * M + to_push(i);
                if(want < 0) continue;
                chmin(dp_buf[j + diff], dp[j] + max(want - pushed, 0));
            }
        }
        copy(dp_buf, dp_buf + SIZE, dp);
    }

    int ans = inf;
    for(int i = 0; i <= N; i++) chmin(ans, dp[i]);
    cout << ans << endl;
    return true;
}

int main() {
    while(solve());
    return 0;
}


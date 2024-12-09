#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
const int mod = 1e9 + 7;

int N;
vector<int> a;
vector<int> cnt;

int dp[100005][3];

int main() {
    cin >> N;
    a.resize(N);
    cnt.resize(N+1, 0);
    
    for(int i=0; i<N; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    
    memset(dp, 0, sizeof(dp));
    
    dp[0][0] = 1;
    dp[0][1] = 0;
    
    for(int i=1; i<=N; i++) {
        dp[i][0] = (1LL * dp[i-1][0] * max(0, cnt[i] - 1) + 1LL * dp[i-1][1] * cnt[i]) % mod;
        dp[i][1] = 1LL * dp[i-1][0] * cnt[i] % mod;
    }
    
    cout << (dp[N][0] + dp[N][1]) % mod << endl;
    
    return 0;
}
#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<bool> broken(N+1, false);
    for(int i = 0; i < M; i++) {
        int a;
        cin >> a;
        broken[a] = true;
    }
    
    vector<int> dp(N+1, 0);
    dp[0] = 1;
    
    for(int i = 1; i <= N; i++) {
        if(!broken[i]) {
            if(i - 1 >= 0) dp[i] = (dp[i] + dp[i-1]) % MOD;
            if(i - 2 >= 0) dp[i] = (dp[i] + dp[i-2]) % MOD;
        }
    }
    
    cout << dp[N] << endl;
    
    return 0;
}
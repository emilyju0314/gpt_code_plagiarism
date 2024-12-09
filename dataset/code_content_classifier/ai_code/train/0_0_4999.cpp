#include <iostream>
#include <vector>
#include <map>
#define mod 1000000007

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> colors(N);
    for(int i = 0; i < N; i++) {
        cin >> colors[i];
    }
    
    map<int, int> last_seen;
    vector<long long> dp(N+1, 0);
    dp[0] = 1;
    
    for(int i = 1; i <= N; i++) {
        if(last_seen.find(colors[i-1]) != last_seen.end() && last_seen[colors[i-1]] != 0) {
            dp[i] = (dp[i-1] + dp[last_seen[colors[i-1]]]) % mod;
        } else {
            dp[i] = dp[i-1];
        }
        last_seen[colors[i-1]] = i;
    }
    
    cout << dp[N] << endl;
    
    return 0;
}
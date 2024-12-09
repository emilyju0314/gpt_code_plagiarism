#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long N;
    cin >> N;
    
    vector<long long> banknotes;
    long long value = 1;
    for (int i = 0; i <= 100; i++) {
        banknotes.push_back(value);
        value *= 10;
    }
    
    vector<long long> dp(N + 1, N + 1);
    dp[0] = 0;
    
    for (long long i = 1; i <= N; i++) {
        for (int j = 0; j < 11; j++) {
            if (i - banknotes[j] >= 0) {
                dp[i] = min(dp[i], dp[i - banknotes[j]] + 1);
            }
        }
    }
    
    cout << dp[N] << endl;

    return 0;
}
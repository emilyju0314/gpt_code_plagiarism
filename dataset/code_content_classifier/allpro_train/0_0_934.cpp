#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    long long C;
    cin >> N >> C;
    
    vector<pair<long long, long long>> sushi(N);
    for (int i = 0; i < N; i++) {
        cin >> sushi[i].first >> sushi[i].second;
    }
    
    // Calculate the maximum nutrition taken in minus the total energy consumed
    long long ans = 0;
    long long sum1 = 0, sum2 = 0;
    vector<long long> dp1(N), dp2(N);
    
    // From left to right
    for (int i = 0; i < N; i++) {
        sum1 += sushi[i].second;
        dp1[i] = max(dp1[i], sum1 - sushi[i].first);
        if (i > 0) dp1[i] = max(dp1[i], dp1[i-1]);
    }
    
    // From right to left
    for (int i = N-1; i >= 0; i--) {
        sum2 += sushi[i].second;
        dp2[i] = max(dp2[i], sum2 - (C - sushi[i].first));
        if (i < N-1) dp2[i] = max(dp2[i], dp2[i+1]);
    }
    
    ans = max(ans, max(dp1[N-1], dp2[0]));
    
    // Check all possible combinations where Nakahashi can eat sushi
    sum1 = sum2 = 0;
    for (int i = 0; i < N; i++) {
        sum1 += sushi[i].second;
        ans = max(ans, sum1 - 2 * sushi[i].first + dp2[i+1]);
    }
    for (int i = N-1; i >= 0; i--) {
        sum2 += sushi[i].second;
        ans = max(ans, sum2 - 2 * (C - sushi[i].first) + dp1[i-1]);
    }
    
    cout << ans << endl;
    
    return 0;
}
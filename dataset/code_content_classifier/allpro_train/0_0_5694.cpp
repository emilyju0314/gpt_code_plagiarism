#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int L;
    cin >> L;

    vector<int> A(L);
    for(int i = 0; i < L; i++) {
        cin >> A[i];
    }

    vector<int> dp(L+1, 0);
    for(int i = 0; i < L; i++) {
        dp[i+1] = max(dp[i+1], dp[i] + A[i]);
        dp[(i+1)%4] = max(dp[(i+1)%4], dp[i]);
    }

    int ans = max({dp[L], dp[L-1], dp[L-2], dp[L-3]});
    cout << L - ans << endl;
    
    return 0;
}
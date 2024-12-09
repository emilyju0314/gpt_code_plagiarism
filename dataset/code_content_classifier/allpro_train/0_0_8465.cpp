#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> dp(N + 1, 0);

    int gA, sA, bA, gB, sB, bB;
    cin >> gA >> sA >> bA >> gB >> sB >> bB;

    for (int i = 0; i <= N; i++) {
        if (i - gA >= 0) {
            dp[i] = max(dp[i], dp[i - gA] + 1);
        }
        if (i - sA >= 0) {
            dp[i] = max(dp[i], dp[i - sA] + 1);
        }
        if (i - bA >= 0) {
            dp[i] = max(dp[i], dp[i - bA] + 1);
        }
    }

    for (int i = 0; i <= N; i++) {
        if (i - gB >= 0) {
            dp[i] = max(dp[i], dp[i - gB] + 1);
        }
        if (i - sB >= 0) {
            dp[i] = max(dp[i], dp[i - sB] + 1);
        }
        if (i - bB >= 0) {
            dp[i] = max(dp[i], dp[i - bB] + 1);
        }
    }

    cout << dp[N] << endl;

    return 0;
}
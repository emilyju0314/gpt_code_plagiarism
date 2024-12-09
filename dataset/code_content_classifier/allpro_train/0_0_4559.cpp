#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> sequence(n);
    for(int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    int maxLength = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            vector<int> newSequence = sequence;
            reverse(newSequence.begin() + i, newSequence.begin() + j + 1);

            vector<int> dp(n, 1);
            for(int k = 0; k < j; k++) {
                if(newSequence[k] <= newSequence[j]) {
                    dp[j] = max(dp[j], dp[k] + 1);
                }
            }

            maxLength = max(maxLength, dp[j]);
        }
    }

    cout << maxLength;

    return 0;
}
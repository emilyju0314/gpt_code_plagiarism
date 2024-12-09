#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> dp(N, 1);

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (abs(A[i] - A[j]) <= K) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int max_length = *max_element(dp.begin(), dp.end());

    cout << max_length << endl;

    return 0;
}
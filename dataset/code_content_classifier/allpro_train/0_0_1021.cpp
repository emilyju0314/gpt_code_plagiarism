#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<bool> dp(K+1, false);
    for(int i = 1; i <= K; i++) {
        for(int j = 0; j < N; j++) {
            if(i - A[j] >= 0 && !dp[i - A[j]]) {
                dp[i] = true;
            }
        }
    }

    if(dp[K]) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

    return 0;
}
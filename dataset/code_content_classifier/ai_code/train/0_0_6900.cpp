#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int H, N;
    cin >> H >> N;

    vector<int> moves(N);
    for(int i = 0; i < N; i++) {
        cin >> moves[i];
    }

    vector<bool> dp(H + 1, false);
    dp[0] = true;

    for(int i = 0; i < N; i++) {
        for(int j = 1; j <= H; j++) {
            if(j - moves[i] >= 0 && dp[j - moves[i]]) {
                dp[j] = true;
            }
        }
    }

    if(dp[H]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
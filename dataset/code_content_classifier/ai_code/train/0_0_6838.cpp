#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, D;
    cin >> N >> D;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<bool> dp(D + 1, false);
    dp[0] = true;

    for (int i = 1; i <= D; i++) {
        for (int j = 0; j < N; j++) {
            if (i - a[j] >= 0 && !dp[i - a[j]]) {
                dp[i] = true;
            }
        }
    }

    if (dp[D]) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

    return 0;
}
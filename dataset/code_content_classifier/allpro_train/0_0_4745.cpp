#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> balls(2*N);
    for (int i = 0; i < 2*N; i++) {
        cin >> balls[i].first >> balls[i].second;
    }

    sort(balls.begin(), balls.end());

    map<int, int> dp;
    dp[0] = 1;

    int total_ways = 1;
    int x_count = 0;
    int y_count = 0;

    for (int i = 0; i < 2*N; i++) {
        if (balls[i].first == balls[i].second) {
            total_ways = (total_ways * (2*N - i)) % MOD;
            if (balls[i].first == i + 1) {
                x_count++;
                y_count++;
            } else if (balls[i].first < i + 1) {
                x_count--;
            } else {
                y_count--;
            }
        } else if (balls[i].first == i + 1) {
            x_count++;
        } else {
            y_count++;
        }

        if (x_count - y_count == 0) {
            dp[i + 1] = (dp[i] * 2) % MOD;
        } else {
            dp[i + 1] = dp[i];
        }
    }

    cout << (total_ways * dp[2*N]) % MOD << endl;

    return 0;
}
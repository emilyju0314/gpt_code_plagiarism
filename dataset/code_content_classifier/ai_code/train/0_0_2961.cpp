#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, r1, r2, r3, d;
    cin >> n >> r1 >> r2 >> r3 >> d;

    vector<int> monsters(n);
    for (int i = 0; i < n; i++) {
        cin >> monsters[i];
    }

    // Initialize dp table to store minimum time to finish the game
    vector<long long> dp(n, 0);

    // Calculate minimum time to finish the game
    for (int i = 1; i < n; i++) {
        long long min_time = dp[i-1] + d;

        long long normal_monsters = monsters[i];
        long long boss = 1;

        // Using pistol and AWP to kill monsters and boss
        long long time = min_time + (normal_monsters - 1) * min(r1, r2) + r3;
        dp[i] = max(time, min_time + normal_monsters * min(r1, r2));
        dp[i] = max(dp[i], time + boss*min(r1, r2));
    }

    cout << dp[n-1] << endl;

    return 0;
}
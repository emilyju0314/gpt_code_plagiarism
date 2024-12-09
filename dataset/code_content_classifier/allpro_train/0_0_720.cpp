#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, double>> plants;
    for(int i = 0; i < n; i++) {
        int species;
        double position;
        cin >> species >> position;
        plants.push_back(make_pair(species, position));
    }

    vector<int> lastPlantPos(m+1, 0);
    vector<int> dp(n+1, 0);

    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i-1];
        if(lastPlantPos[plants[i-1].first] != 0) {
            dp[i] = max(dp[i], dp[lastPlantPos[plants[i-1].first]] + 1);
        }
        lastPlantPos[plants[i-1].first] = i;
    }

    int ans = m - dp[n];
    cout << ans << endl;

    return 0;
}
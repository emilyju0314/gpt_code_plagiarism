#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cities(n);
    for(int i = 0; i < n; i++) {
        cin >> cities[i];
    }

    map<int, int> lastIndex;
    map<int, int> dp;
    dp[-1] = 0;

    for(int i = 0; i < n; i++) {
        dp[i] = dp[i - 1] ^ cities[i];
        if(lastIndex.find(cities[i]) != lastIndex.end()) {
            dp[i] = max(dp[i], dp[lastIndex[cities[i] - 1]] ^ dp[lastIndex[cities[i]]]);
        }
        lastIndex[cities[i]] = i;
    }

    cout << dp[n - 1] << endl;

    return 0;
}
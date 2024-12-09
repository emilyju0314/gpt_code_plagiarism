#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int mod = 12345;

int main() {
    int n, c;
    cin >> n >> c;

    unordered_map<char, int> crimes;
    vector<pair<char, int>> conditions;

    for (int i = 0; i < c; i++) {
        char type;
        int multiplicity;
        cin >> type >> multiplicity;
        crimes[type] = multiplicity;
        conditions.push_back({type, multiplicity});
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (auto& condition : conditions) {
            char type = condition.first;
            int multiplicity = condition.second;

            if (i >= multiplicity) {
                if (dp[i - multiplicity]) {
                    dp[i] = (dp[i] + dp[i - multiplicity]) % mod;
                }
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}
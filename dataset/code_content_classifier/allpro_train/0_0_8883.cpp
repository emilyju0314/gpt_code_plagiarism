#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            graph[i][j] = s[j] - '0';
        }
    }

    vector<int> powers(n, 0);
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        string golds;
        cin >> golds;
        for (char c : golds) {
            if (c == '1') {
                powers[i]++;
            }
        }
    }

    vector<pair<int, int>> gang_powers;
    for (int i = 0; i < n; i++) {
        gang_powers.push_back({powers[i], i});
    }

    sort(gang_powers.begin(), gang_powers.end(), greater<pair<int, int>>());

    int ans = 0;
    for (int i = 0; i < b; i++) {
        ans += gang_powers[i].first;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
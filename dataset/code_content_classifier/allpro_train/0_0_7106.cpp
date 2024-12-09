#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> heights(n);
    vector<vector<int>> costs(n);

    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++) {
            int height;
            cin >> height;
            heights[i].push_back(height);
        }
        for(int j = 0; j < k; j++) {
            int cost;
            cin >> cost;
            costs[i].push_back(cost);
        }
    }

    vector<pair<int, int>> sequence;
    int total_cost = 0;

    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int id, mul;
        cin >> id >> mul;
        id--;
        total_cost += costs[id][0] * mul;
        for(int j = 1; j < heights[id].size(); j++) {
            sequence.push_back(make_pair(heights[id][j], costs[id][j] * mul));
        }
    }

    sort(sequence.begin(), sequence.end(), greater<>());

    long long result = total_cost;
    long long cur_cost = total_cost;
    map<int, long long> dp;

    for(auto& p : sequence) {
        int height = p.first;
        int cost = p.second;

        cur_cost -= cost;
        dp[height] += cost;
        result = min(result, dp.begin()->second + cur_cost);
    }

    cout << result << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> stocks(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> stocks[i].first >> stocks[i].second;
    }

    int earliestTime = -1, minExchanges = 2 * n;

    // Iterate through possible times
    for (int time = 1; time <= 1000000; time++) {
        vector<int> costs;
        
        // Calculate the cost for each stock at the current time
        for (int i = 0; i < 2 * n; i++) {
            costs.push_back(stocks[i].first * max(time, 1) + stocks[i].second);
        }

        // Sort the costs
        sort(costs.begin(), costs.end());

        // Check if Bob can achieve his goal at the current time
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (costs[i] >= costs[i + n]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            int exchanges = 0;
            for (int i = 0; i < n; i++) {
                exchanges += costs[i];
            }

            if (time < earliestTime || earliestTime == -1 || (time == earliestTime && exchanges < minExchanges)) {
                earliestTime = time;
                minExchanges = exchanges;
            }
        }
    }

    if (earliestTime == -1) {
        cout << -1 << endl;
    } else {
        cout << earliestTime << " " << minExchanges << endl;
    }

    return 0;
}
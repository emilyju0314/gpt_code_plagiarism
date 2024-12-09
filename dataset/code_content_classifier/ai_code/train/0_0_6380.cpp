#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> power(n);
    vector<int> processors(n);

    for (int i = 0; i < n; i++) {
        cin >> power[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> processors[i];
    }

    vector<pair<int, int>> tasks;
    for (int i = 0; i < n; i++) {
        tasks.push_back({power[i], processors[i]});
    }

    sort(tasks.begin(), tasks.end());

    double minThreshold = 1e18;
    for (int i = 0; i < n; i++) {
        double sumPower = tasks[i].first;
        double sumProcessors = tasks[i].second;

        for (int j = i+1; j < n; j++) {
            sumPower += tasks[j].first;
            sumProcessors += tasks[j].second;

            double threshold = ceil((sumPower / sumProcessors) * 1000.0);
            minThreshold = min(minThreshold, threshold);
        }
    }

    cout << minThreshold << endl;

    return 0;
}
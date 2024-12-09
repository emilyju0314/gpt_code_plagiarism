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

    for(int i = 0; i < n; i++) {
        cin >> power[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> processors[i];
    }

    vector<pair<int, int>> tasks;
    for(int i = 0; i < n; i++) {
        tasks.push_back({power[i], processors[i]});
    }

    sort(tasks.begin(), tasks.end());

    int total_power = 0, total_processors = 0;
    double threshold = 1e9;

    for(int i = 0; i < n; i++) {
        total_power += tasks[i].first;
        total_processors += tasks[i].second;

        double average_power = static_cast<double>(total_power) / total_processors;
        double current_threshold = static_cast<double>(total_power * 1000) / total_processors;

        if(i != n-1) {
            threshold = min(threshold, ceil(current_threshold));
        }
    }

    cout << static_cast<int>(threshold) << endl;

    return 0;
}
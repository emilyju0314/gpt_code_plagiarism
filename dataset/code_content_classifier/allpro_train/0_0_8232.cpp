#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> jobs(n);
    for (int i = 0; i < n; i++) {
        cin >> jobs[i];
    }

    vector<int> persuade_time(n);
    for (int i = 0; i < n; i++) {
        cin >> persuade_time[i];
    }

    vector<pair<int, int>> idlers;
    for (int i = 1; i <= k; i++) {
        idlers.push_back({0, i});
    }

    for (int i = 0; i < n; i++) {
        idlers[jobs[i] - 1].first += persuade_time[i];
    }

    sort(idlers.begin(), idlers.end());

    int total_time = 0;
    for (int i = 0; i < n - k; i++) {
        total_time += idlers[i].first;
    }

    cout << total_time << endl;

    return 0;
}
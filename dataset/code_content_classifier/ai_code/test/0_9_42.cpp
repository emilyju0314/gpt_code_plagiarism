#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    sort(tasks.begin(), tasks.end());

    int t;
    cin >> t;

    vector<int> s(t);
    for (int i = 0; i < t; i++) {
        cin >> s[i];
    }

    vector<int> timeTravels(n, 0);
    int totalTimeTravels = 0;
    int completedTasks = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (find(s.begin(), s.end(), i + 1) != s.end()) {
            completedTasks++;
        }

        if (tasks[i].first < tasks[i].second) {
            timeTravels[i] = 1 + totalTimeTravels + (completedTasks < t ? 1 : 0);
            totalTimeTravels = (totalTimeTravels + timeTravels[i]) % MOD;
        }

    }

    cout << totalTimeTravels << endl;

    return 0;
}
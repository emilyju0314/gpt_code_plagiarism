#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

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

    vector<int> funnyTasks(t);
    for (int i = 0; i < t; i++) {
        cin >> funnyTasks[i];
    }

    int numTimes = 0;
    int numComplete = 0;
    int timeTravel = 0;
    int result = 0;

    for (int i = 0; i < n; i++) {
        if (numComplete == t) {
            result = (result + timeTravel) % MOD;
        }

        if (find(funnyTasks.begin(), funnyTasks.end(), tasks[i].first) != funnyTasks.end()) {
            if (numComplete < t) {
                numComplete++;
            }
        }

        if (numComplete == t) {
            result = (result + timeTravel) % MOD;
        }

        if (tasks[i].second < tasks[i].first) {
            timeTravel++;
        }
    }

    cout << result << endl;

    return 0;
}
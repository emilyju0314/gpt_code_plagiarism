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

    vector<int> completedTasks(n+1, 0);
    vector<int> timeTravels(n+1, 0);

    // Perform simulation
    int totalCompleted = 0;
    int totalTravels = 0;

    for (int i = 0; i < n; i++) {
        int currentTask = tasks[i].second;
        int requiredTask = tasks[i].first;

        for (int j = 1; j < currentTask; j++) {
            if (completedTasks[j] == 1) {
                completedTasks[j] = 0;
            }
        }

        completedTasks[currentTask] = 1;

        if (find(funnyTasks.begin(), funnyTasks.end(), currentTask) != funnyTasks.end()) {
            int completeCount = 0;
            for (int k : funnyTasks) {
                if (completedTasks[k] == 1) {
                    completeCount++;
                }
            }

            if (completeCount == t) {
                totalTravels += timeTravels[currentTask] % MOD;
                totalCompleted++;
            }
        }

        timeTravels[currentTask] = totalTravels;
        totalTravels++;

    }

    cout << totalTravels % MOD << endl;

    return 0;
}
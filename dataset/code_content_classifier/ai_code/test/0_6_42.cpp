#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int main() {
    int n, t;
    cin >> n;

    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    cin >> t;

    set<int> funnyTasks;
    for (int i = 0; i < t; i++) {
        int task;
        cin >> task;
        funnyTasks.insert(task);
    }

    sort(tasks.begin(), tasks.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int currentTime = 0;
    int timeTravels = 0;
    int completedFunnyTasks = 0;

    for (const auto& task : tasks) {
        if (funnyTasks.count(task.first)) {
            completedFunnyTasks++;
        }

        if (completedFunnyTasks == t) {
            timeTravels = (timeTravels + currentTime) % MOD;
        } else {
            currentTime = task.second;
        }
    }

    cout << timeTravels << endl;

    return 0;
}
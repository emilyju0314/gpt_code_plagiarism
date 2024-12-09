#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

#define MOD 1000000007

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> tasks(n);
    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        tasks[i] = {a, b};
        order[i] = i;
    }

    sort(order.begin(), order.end(), [&](int x, int y) {
        return tasks[x].second < tasks[y].second;
    });

    int t;
    cin >> t;

    unordered_set<int> sceneTasks;
    for (int i = 0; i < t; i++) {
        int task;
        cin >> task;
        sceneTasks.insert(task - 1);
    }

    long long answer = 0;
    vector<int> latestCompletionTime(n, 0);
    for (int i = 0; i < n; i++) {
        int taskIndex = order[i];
        int taskTime = tasks[taskIndex].first;

        for (int j = 0; j < n; j++) {
            if (tasks[j].second > taskTime) {
                latestCompletionTime[j] = 0;
            }
        }

        latestCompletionTime[taskIndex] = taskTime;

        int earliestCompletionTime = *min_element(latestCompletionTime.begin(), latestCompletionTime.end());
        int numTimeTravels = taskTime - earliestCompletionTime;

        int tasksCompleted = 0;
        for (int task : sceneTasks) {
            if (latestCompletionTime[task] > earliestCompletionTime) {
                tasksCompleted++;
            }
        }

        if (tasksCompleted == t) {
            answer = (answer + numTimeTravels) % MOD;
        }
    }

    cout << answer << endl;

    return 0;
}
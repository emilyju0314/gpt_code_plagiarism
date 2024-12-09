#include <iostream>
#include <vector>
#include <queue>

#define MOD 1000000007

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    int t;
    cin >> t;

    vector<int> funny_scene(t);
    for (int i = 0; i < t; i++) {
        cin >> funny_scene[i];
    }

    vector<int> completion_time(n+1, -1);
    vector<bool> completed(n+1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int time_travels = 0;
    int completed_tasks = 0;
    int result = 0;

    for (int i = 0; i < n; i++) {
        int task_index = i+1;
        while (!pq.empty() && pq.top().first <= tasks[task_index-1].second) {
            int completed_task = pq.top().second;
            pq.pop();
            if (!completed[completed_task]) {
                completed[completed_task] = true;
                completed_tasks++;
                if (completion_time[completed_task] == pq.top().first) {
                    pq.pop();
                }
            }
        }

        if (completed_tasks == t) {
            result = (result + time_travels) % MOD;
        }

        if (completed[task_index]) {
            pq.push({tasks[task_index-1].first, task_index});
        } else {
            pq.push({tasks[task_index-1].second, task_index});
            completion_time[task_index] = tasks[task_index-1].first;
            time_travels++;
        }
    }

    cout << result << endl;

    return 0;
}
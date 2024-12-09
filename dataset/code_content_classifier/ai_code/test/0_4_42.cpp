#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> tasks(n);
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        tasks[i] = make_pair(a, b);
    }

    sort(tasks.begin(), tasks.end());

    int t;
    cin >> t;

    vector<int> funnyTasks(t);
    for(int i = 0; i < t; i++) {
        cin >> funnyTasks[i];
    }

    sort(funnyTasks.begin(), funnyTasks.end());

    long long answer = 0;
    long long time = 0;
    int completedTasks = 0;

    for(auto task : tasks) {
        time = task.second;
        if(find(funnyTasks.begin(), funnyTasks.end(), task.first) != funnyTasks.end()) {
            completedTasks++;
        }

        if(completedTasks == t) {
            answer = (answer + (time - task.first) % MOD) % MOD;
            completedTasks = 0;
        }
    }

    cout << answer << "\n";

    return 0;
}
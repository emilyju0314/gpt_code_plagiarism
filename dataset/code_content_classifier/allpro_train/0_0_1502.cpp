#include <iostream>
#include <vector>

using namespace std;

struct Task {
    int start_time, duration, profit;
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<Task> tasks(n);
    for(int i = 0; i < n; i++) {
        cin >> tasks[i].start_time >> tasks[i].duration >> tasks[i].profit;
    }

    vector<int> selected_tasks(n, 0);
    for(int i = 0; i < n; i++) {
        int curr_profit = tasks[i].profit;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(tasks[j].start_time <= tasks[i].start_time + tasks[i].duration - 1 ||
               tasks[j].start_time >= tasks[i].start_time + tasks[i].duration + tasks[i].duration) {
                curr_profit += tasks[j].profit;
            }
        }
        if(curr_profit > tasks[i].profit) {
            selected_tasks[i] = 1;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << selected_tasks[i] << " ";
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Task {
    int time, servers, duration, id;
    Task(int t, int s, int d, int i) : time(t), servers(s), duration(d), id(i) {}
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> serverStatus(n + 1, 0); // 0 for unoccupied, 1 for occupied
    queue<Task> tasks;

    for (int i = 0; i < q; i++) {
        int t, k, d;
        cin >> t >> k >> d;
        tasks.push(Task(t, k, d, i));
    }

    for (int i = 0; i < q; i++) {
        Task currentTask = tasks.front();
        tasks.pop();

        int sumIds = 0;
        vector<int> availableServers;

        for (int j = 1; j <= n; j++) {
            if (serverStatus[j] <= currentTask.time) {
                availableServers.push_back(j);
                if (availableServers.size() == currentTask.servers) {
                    break;
                }
            }
        }

        if (availableServers.size() < currentTask.servers) {
            cout << "-1\n";
        } else {
            for (int server : availableServers) {
                sumIds += server;
                serverStatus[server] = currentTask.time + currentTask.duration;
            }
            cout << sumIds << endl;
        }
    }

    return 0;
}
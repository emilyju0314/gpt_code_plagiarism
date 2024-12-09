#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Worker {
    int index, l, v, r;
};

bool workerComparator(const Worker& w1, const Worker& w2) {
    return w1.v < w2.v;
}

int main() {
    int n;
    cin >> n;

    vector<Worker> workers(n);
    for (int i = 0; i < n; i++) {
        cin >> workers[i].l >> workers[i].v >> workers[i].r;
        workers[i].index = i + 1;
    }

    sort(workers.begin(), workers.end(), workerComparator);

    vector<int> dp(n, 1);
    vector<int> prev(n, -1);
    int maxTeamSize = 1;
    int maxTeamEndIndex = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (workers[i].l <= workers[j].v && workers[i].v >= workers[j].l && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;

                if (dp[i] > maxTeamSize) {
                    maxTeamSize = dp[i];
                    maxTeamEndIndex = i;
                }
            }
        }
    }

    cout << maxTeamSize << endl;
    vector<int> selectedWorkers;
    for (int i = maxTeamEndIndex; i != -1; i = prev[i]) {
        selectedWorkers.push_back(workers[i].index);
    }

    reverse(selectedWorkers.begin(), selectedWorkers.end());
    for (int i = 0; i < selectedWorkers.size(); i++) {
        cout << selectedWorkers[i] << " ";
    }

    return 0;
}
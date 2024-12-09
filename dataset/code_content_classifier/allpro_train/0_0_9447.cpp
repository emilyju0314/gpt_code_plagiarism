#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int c;
    cin >> c;

    while (c--) {
        int n, m, t;
        cin >> n >> m >> t;

        vector<int> tasks(n);
        for (int i = 0; i < n; i++) {
            cin >> tasks[i];
        }

        int maxTasks = 0, optimalD = 0;

        // Binary search for optimal value of d
        int left = 1, right = t;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int tasksCompleted = 0, timeSpent = 0, breaks = 0;

            for (int i = 0; i < n; i++) {
                if (tasks[i] <= mid) {
                    timeSpent += tasks[i];
                    if (timeSpent <= t) {
                        tasksCompleted++;
                    } else {
                        break;
                    }
                } else {
                    breaks++;
                    timeSpent += m;
                    if (timeSpent > t) {
                        break;
                    }
                }
            }

            if (tasksCompleted > maxTasks) {
                maxTasks = tasksCompleted;
                optimalD = mid;
            }

            if (tasksCompleted >= n) {
                break;
            }

            if (tasksCompleted < n) {
                if (breaks > 0) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        cout << maxTasks << " " << optimalD << endl;
    }

    return 0;
}
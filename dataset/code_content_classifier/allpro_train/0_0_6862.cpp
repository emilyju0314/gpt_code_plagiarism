#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string tasks;
        cin >> tasks;

        vector<int> taskCount(26, 0);
        bool suspicious = false;

        for (int i = 1; i < n; i++) {
            if (tasks[i] == tasks[i - 1]) continue;
            if (taskCount[tasks[i] - 'A'] > 0) {
                suspicious = true;
                break;
            }
            taskCount[tasks[i - 1] - 'A']++;
        }

        if (suspicious) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0;
}
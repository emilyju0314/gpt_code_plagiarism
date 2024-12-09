#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, U;

    while (true) {
        cin >> n >> U;

        if (n == 0 && U == 0) {
            break;
        }

        vector<int> credits(n);
        vector<vector<int>> prerequisites(n);
        vector<int> inDegree(n, 0);

        for (int i = 0; i < n; i++) {
            int c, k;
            cin >> c >> k;
            credits[i] = c;

            for (int j = 0; j < k; j++) {
                int preq;
                cin >> preq;
                prerequisites[i].push_back(preq);
                inDegree[preq]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int coursesTaken = 0;
        int totalCredits = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            coursesTaken++;
            totalCredits += credits[curr];

            for (int neighbor : prerequisites[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        cout << coursesTaken << endl;
    }

    return 0;
}
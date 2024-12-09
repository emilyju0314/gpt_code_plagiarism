#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, m, b;
    cin >> n >> m >> b;
    
    vector<int> friendCosts(n), friendMonitors(n), friendProblems(n);
    vector<vector<int>> friendProblemList(n);
    
    for (int i = 0; i < n; i++) {
        cin >> friendCosts[i] >> friendMonitors[i] >> friendProblems[i];
        friendProblemList[i].resize(friendProblems[i]);
        for (int j = 0; j < friendProblems[i]; j++) {
            cin >> friendProblemList[i][j];
        }
    }
    
    int minCost = INT_MAX;
    for (int mask = 0; mask < (1 << n); mask++) {
        bool canSolveAllProblems = true;
        int totalCost = 0;
        vector<int> monitors(n);
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                totalCost += friendCosts[i];
                for (int problem : friendProblemList[i]) {
                    monitors[i]++;
                }
            }
            if (monitors[i] < friendMonitors[i]) {
                totalCost += friendMonitors[i] * b;
            }
        }
        
        vector<int> problemsSolved(m);
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                for (int problem : friendProblemList[i]) {
                    problemsSolved[problem - 1]++;
                    if (problemsSolved[problem - 1] == 1) {
                        m--;
                    }
                }
            }
        }
        
        if (m == 0) {
            minCost = min(minCost, totalCost);
        }
    }
    
    if (minCost == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << minCost << endl;
    }
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> friendliness(n, vector<int>(n, 0));

    for(int i = 0; i < m; i++) {
        int u, v, f;
        cin >> u >> v >> f;
        friendliness[u-1][v-1] = f;
        friendliness[v-1][u-1] = f;
    }

    vector<int> maxFriendliness(n, 0);

    for(int i = 0; i < n; i++) {
        int minFriendliness = INT_MAX;
        for(int j = 0; j < n; j++) {
            if(i != j) {
                minFriendliness = min(minFriendliness, friendliness[i][j]);
            }
        }
        maxFriendliness[i] = minFriendliness;
    }

    int totalSatisfaction = 0;
    for(int i = 0; i < n; i++) {
        totalSatisfaction += maxFriendliness[i];
    }

    cout << totalSatisfaction * 2 << endl;

    return 0;
}
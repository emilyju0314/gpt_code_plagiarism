#include <iostream>
#include <vector>

using namespace std;

void constructTree(int n, vector<vector<int>>& restrictions) {
    vector<int> pathNodes;
    vector<int> remainingNodes;

    for (int i = 1; i <= n; i++) {
        bool isRestricted = false;
        for (vector<int>& restriction : restrictions) {
            if (restriction[1] == i) {
                isRestricted = true;
                break;
            }
        }

        if (isRestricted) {
            remainingNodes.push_back(i);
        } else {
            pathNodes.push_back(i);
        }
    }

    for (int i = 1; i < pathNodes.size(); i++) {
        cout << pathNodes[i-1] << " " << pathNodes[i] << "\n";
    }

    for (int i = 0; i < remainingNodes.size() - 1; i++) {
        cout << pathNodes[0] << " " << remainingNodes[i] << "\n";
    }

}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> restrictions;
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            restrictions.push_back({a, b, c});
        }

        constructTree(n, restrictions);
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isRobot(int n, vector<vector<int>>& rides) {
    unordered_map<int, unordered_map<int, int>> paths;

    for (auto& ride : rides) {
        for (int i = 1; i < ride.size() - 1; i++) {
            int start = ride[i];
            int end = ride[i + 1];
            if (paths[start][end] != 0 && paths[start][end] != i) {
                return false;
            } else {
                paths[start][end] = i;
            }
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<vector<int>> rides(q);
        for (int i = 0; i < q; i++) {
            int k;
            cin >> k;
            rides[i].resize(k);
            for (int j = 0; j < k; j++) {
                cin >> rides[i][j];
            }
        }

        if (isRobot(n, rides)) {
            cout << "Robot" << endl;
        } else {
            cout << "Human" << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool findPalindromePath(int n, int m, vector<vector<char>>& graph) {
    if (m % 2 != 0) {
        return false;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == graph[j][i]) {
                vector<int> path;
                path.push_back(i+1);

                if (m % 4 == 0) {
                    path.push_back(j+1);
                    for (int k = 0; k < m/4 - 1; k++) {
                        path.push_back(i+1);
                        path.push_back(j+1);
                    }
                    path.push_back(i+1);
                } else {
                    path.push_back(i+1);
                    for (int k = 0; k < m/4; k++) {
                        path.push_back(j+1);
                        path.push_back(i+1);
                    }
                }

                cout << "YES" << endl;
                for (int node : path) {
                    cout << node << " ";
                }
                cout << endl;

                return true;
            }
        }
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> graph(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> graph[i][j];
            }
        }

        if (!findPalindromePath(n, m, graph)) {
            cout << "NO" << endl;
        }
    }

    return 0;
}
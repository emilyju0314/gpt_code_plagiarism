#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<bool>> maze(2, vector<bool>(n, false));

    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        r--; // Adjust the row index to match the vector indexing
        c--; // Adjust the column index to match the vector indexing

        maze[r][c] = !maze[r][c]; // Toggle the state of the cell

        bool possible = false;
        // Check if it is possible to move from (1,1) to (2,n)
        if (!maze[0][0] && !maze[1][n-1]) {
            // Check if there exists a path from (1,1) to (2,n)
            bool visited[2][n] = {false};
            vector<pair<int,int>> toVisit;
            toVisit.push_back({0,0});

            while (!toVisit.empty()) {
                pair<int,int> curr = toVisit.back();
                toVisit.pop_back();

                if (curr.first == 1 && curr.second == n-1) {
                    possible = true;
                    break;
                }

                visited[curr.first][curr.second] = true;

                if (curr.first == 0) {
                    if (curr.second + 1 < n && !maze[0][curr.second+1] && !visited[0][curr.second+1]) {
                        toVisit.push_back({0, curr.second+1});
                    }
                    if (!visited[1][curr.second]) {
                        toVisit.push_back({1, curr.second});
                    }
                } else {
                    if (curr.second > 0 && !maze[1][curr.second-1] && !visited[1][curr.second-1]) {
                        toVisit.push_back({1, curr.second-1});
                    }
                    if (!visited[0][curr.second]) {
                        toVisit.push_back({0, curr.second});
                    }
                }
            }
        }

        if (possible) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
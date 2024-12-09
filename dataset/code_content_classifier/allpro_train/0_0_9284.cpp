#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Output initial positions of the bees
    cout << "1 2 3" << endl;
    cout.flush();

    int NastyaPosition;
    cin >> NastyaPosition;

    vector<int> edges[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int currentPositions[3] = {1, 2, 3};
    vector<int> nextPositions;
    vector<int> nextNastyaPositions;

    // Main game loop
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            nextPositions.clear();
            
            for (int k = 0; k < edges[currentPositions[j]].size(); k++) {
                int next = edges[currentPositions[j]][k];
                if (next != currentPositions[(j + 1) % 3] && next != currentPositions[(j + 2) % 3]) {
                    nextPositions.push_back(next);
                }
            }

            cout << nextPositions[0] << " " << nextPositions[1] << " " << currentPositions[j] << endl;
            cout.flush();

            int newPos;
            cin >> newPos;
            nextNastyaPositions.push_back(newPos);
        }

        for (int j = 0; j < 3; j++) {
            currentPositions[j] = nextNastyaPositions[j];
            if (currentPositions[j] == NastyaPosition) {
                return 0;
            }
        }
    }

    return 0;
}
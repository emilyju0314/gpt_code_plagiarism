#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int N, P;
    cin >> N >> P;

    // Initialize a vector to store the time needed to pass each line
    vector<vector<pair<int, int>>> lines(N, vector<pair<int,int>>(N, make_pair(INT_MAX, INT_MAX)));

    // Read input for each line connecting two flags
    for (int i = 0; i < P; i++) {
        int s, e, t1, t2;
        cin >> s >> e >> t1 >> t2;
        lines[s-1][e-1] = make_pair(t1, t2);
        lines[e-1][s-1] = make_pair(t1, t2);
    }

    // Applying Floyd-Warshall algorithm to find shortest path between all pairs of flags
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int new_time = min(lines[i][k].first + lines[k][j].second, lines[i][k].second + lines[k][j].first);
                if (new_time < lines[i][j].first) {
                    lines[i][j].second = lines[i][j].first;
                    lines[i][j].first = new_time;
                } else if (new_time < lines[i][j].second) {
                    lines[i][j].second = new_time;
                }
            }
        }
    }

    // Output the shortest total time to reach the goal from the start point
    cout << lines[0][N-1].second << endl;

    return 0;
}
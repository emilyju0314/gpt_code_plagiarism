#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> enmity(n + 1); // Initialize vector to store enemies for each student

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        enmity[a].push_back(b);
        enmity[b].push_back(a);
    }

    int result = 0;
    vector<bool> used(n + 1, false); // Keep track of used students

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            int team1 = 0, team2 = 0; // Count students in each team
            vector<int> Q; // Queue for BFS traversal
            Q.push_back(i);
            used[i] = true;
            team1++;

            while (!Q.empty()) {
                int v = Q.back();
                Q.pop_back();

                for (int u : enmity[v]) {
                    if (!used[u]) {
                        Q.push_back(u);
                        used[u] = true;
                        team2++;
                    }
                }
            }

            result += min(team1, team2);
        }
    }

    cout << result << endl;

    return 0;
}
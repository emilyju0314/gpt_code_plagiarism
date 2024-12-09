#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = 1e9+7;

int main() {
    int n, m, b;
    cin >> n >> m >> b;

    int ans = INF;

    vector<int> cost(m), monitors(m), problems(m);
    vector<vector<int>> friends(n);

    for (int i = 0; i < n; i++) {
        int xi, ki, mi;
        cin >> xi >> ki >> mi;

        friends[i].push_back(xi);

        for (int j = 0; j < mi; j++) {
            int problem;
            cin >> problem;
            problem--;
            friends[i].push_back(problem);
        }
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> problems_solved(m);

        int total_cost = 0;
        int total_monitors = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                total_cost += friends[i][0];

                for (int j = 1; j < friends[i].size(); j++) {
                    int problem = friends[i][j];
                    problems_solved[problem] = 1;
                }

                total_monitors += friends[i][1];
            }
        }

        bool solved_all_problems = true;

        for (int i = 0; i < m; i++) {
            if (!problems_solved[i]) {
                solved_all_problems = false;
                break;
            }
        }

        if (solved_all_problems) {
            int current_cost = total_cost + total_monitors * b;
            ans = min(ans, current_cost);
        }
    }

    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
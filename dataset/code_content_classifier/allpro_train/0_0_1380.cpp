#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    while (true) {
        cin >> n;
        if (n == 0) break;

        // Read cone colors
        vector<int> con_colors(n);
        for (int i = 0; i < n; i++) {
            cin >> cone_colors[i];
        }

        // Read arrows
        cin >> m;
        vector<vector<pair<int, int>>> arrows(n);
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            arrows[a-1].push_back({b-1, c});
        }

        // Read prohibited color pattern
        cin >> k;
        string pattern;
        cin >> pattern;

        // Initialize variables
        int max_reached = 0;
        int min_cost = 0;

        // Calculate the maximum number of people that can reach the goal
        for (int i = 0; i < k; i++) {
            int invalid = 0;
            for (int j = 0; j < n; j++) {
                if (pattern[cone_colors[j]-1] == '1') {
                    invalid = 1;
                    break;
                }
            }
            if (!invalid) {
                max_reached++;
            }
        }

        // Calculate the minimum cost
        if (max_reached == 0) {
            min_cost = 0;
        } else {
            min_cost = -1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < arrows[i].size(); j++) {
                    if (arrows[i][j].second >= 0 && (min_cost == -1 || arrows[i][j].second < min_cost)) {
                        min_cost = arrows[i][j].second;
                    }
                }
            }
        }

        // Output the result
        if (max_reached == 0) {
            cout << "0 0" << endl;
        } else if (min_cost == -1) {
            cout << max_reached << " -1" << endl;
        } else {
            cout << max_reached << " " << min_cost * max_reached << endl;
        }
    }

    return 0;
}
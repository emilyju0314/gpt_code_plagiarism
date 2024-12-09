#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> votes(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> votes[i][j];
        }
    }

    vector<int> city_winners(m, 1);
    vector<int> candidates_votes(n, 0);

    for (int i = 0; i < m; i++) {
        int max_votes = 0;
        for (int j = 0; j < n; j++) {
            if (votes[i][j] > max_votes) {
                max_votes = votes[i][j];
                city_winners[i] = j + 1;
            }
        }
        candidates_votes[city_winners[i] - 1]++;
    }

    int max_votes = 0;
    int winner = 1;
    for (int i = 0; i < n; i++) {
        if (candidates_votes[i] > max_votes) {
            max_votes = candidates_votes[i];
            winner = i + 1;
        }
    }

    cout << winner << endl;

    return 0;
}
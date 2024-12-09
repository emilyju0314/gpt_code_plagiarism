#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> scores(n);
    // Read current scores of reindeer
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    vector<pair<int, int>> requirements(m);
    // Read requirements
    for (int i = 0; i < m; i++) {
        cin >> requirements[i].first >> requirements[i].second;
    }

    // Find the maximum score among the two reindeer in each requirement
    vector<int> max_score(n + 1, 0);
    for (auto requirement : requirements) {
        max_score[requirement.first] = max(max_score[requirement.first], scores[requirement.second - 1]);
        max_score[requirement.second] = max(max_score[requirement.second], scores[requirement.first - 1]);
    }

    // Output the scores after operations
    for (int i = 0; i < n; i++) {
        cout << max(scores[i], max_score[i + 1]) << " ";
    }

    return 0;
}
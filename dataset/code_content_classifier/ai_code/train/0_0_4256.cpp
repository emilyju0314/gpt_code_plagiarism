#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;

    vector<pair<int, int>> projects(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        projects[i] = make_pair(a, b);
    }

    sort(projects.begin(), projects.end());

    vector<int> dp(r + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = r; j >= projects[i].first; j--) {
            dp[j] = max(dp[j], dp[j - projects[i].first] + projects[i].second);
        }
    }

    int maxProjects = 0;
    for (int i = 0; i <= r; i++) {
        maxProjects = max(maxProjects, dp[i]);
    }

    cout << maxProjects << endl;

    return 0;
}
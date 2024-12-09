#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> robbers(n);
    vector<pair<int, int>> searchlights(m);

    for(int i = 0; i < n; i++) {
        cin >> robbers[i].first >> robbers[i].second;
    }

    for(int i = 0; i < m; i++) {
        cin >> searchlights[i].first >> searchlights[i].second;
    }

    sort(robbers.begin(), robbers.end());
    sort(searchlights.begin(), searchlights.end());

    int minMoves = 0;
    for(int i = 0; i < m; i++) {
        int dx = searchlights[i].first - robbers[0].first;
        int dy = max(0, searchlights[i].second - robbers[0].second);

        for(int j = 0; j < n; j++) {
            int x = robbers[j].first + dx;
            int y = max(robbers[j].second + dy, searchlights[i].second);

            if(x < searchlights[i].first || y < searchlights[i].second) {
                minMoves = max(minMoves, max(searchlights[i].first-x, searchlights[i].second-y));
            }
        }
    }

    cout << minMoves << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    vector<pair<int, int>> coders;
    vector<int> agreed(n, 0);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        coders.push_back({x, y});
        agreed[x - 1]++;
        agreed[y - 1]++;
    }

    int possible_pairs = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int agreed_count = agreed[i] + agreed[j] - (coders[i].first == j + 1 || coders[i].second == j + 1 || coders[j].first == i + 1 || coders[j].second == i + 1);
            if (agreed_count >= p) {
                possible_pairs++;
            }
        }
    }

    cout << possible_pairs << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> flags;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        flags.push_back(make_pair(x, y));
    }

    // Sort the flags based on x coordinates
    sort(flags.begin(), flags.end());

    int max_d = 0;
    for (int i = 0; i < N - 1; i++) {
        int d = flags[i + 1].first - flags[i].first;
        max_d = max(max_d, d);
    }

    // Sort the flags based on y coordinates
    sort(flags.begin(), flags.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });

    for (int i = 0; i < N - 1; i++) {
        int d = flags[i + 1].second - flags[i].second;
        max_d = max(max_d, d);
    }

    cout << max_d << endl;

    return 0;
}
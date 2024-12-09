#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> sociability(n);

        for (int i = 0; i < n; i++) {
            cin >> sociability[i].first;
            sociability[i].second = i + 1;
        }

        sort(sociability.rbegin(), sociability.rend());

        vector<pair<int, int>> talks;

        for (int i = 0; i < n - 1; i++) {
            talks.push_back({sociability[i].second, sociability.back().second});
        }

        cout << n - 1 << endl;
        for (auto talk : talks) {
            cout << talk.first << " " << talk.second << endl;
        }
    }

    return 0;
}
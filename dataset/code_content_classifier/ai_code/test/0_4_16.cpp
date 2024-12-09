#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2) {
    return p1.second > p2.second;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> sociability(n);
        vector<pair<int, int>> sorted_sociability;

        for (int i = 0; i < n; i++) {
            cin >> sociability[i];
            sorted_sociability.push_back({i + 1, sociability[i]});
        }

        sort(sorted_sociability.begin(), sorted_sociability.end(), comp);

        int max_talks = 0;
        vector<pair<int, int>> talks;

        for (int i = 0; i < n - 1; i++) {
            max_talks += sorted_sociability[i].second;
            talks.push_back({sorted_sociability[i].first, sorted_sociability[i + 1].first});
        }
        
        max_talks += sorted_sociability[n - 1].second;

        cout << max_talks << endl;
        for (auto talk : talks) {
            cout << talk.first << " " << talk.second << endl;
        }
    }

    return 0;
}
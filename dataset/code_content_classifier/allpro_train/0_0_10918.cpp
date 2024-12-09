#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool intersect(pair<int, int> s1, pair<int, int> s2) {
    return s1.first <= s2.second && s2.first <= s1.second;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<pair<int, int>> segments(n);
        for (int i = 0; i < n; i++) {
            cin >> segments[i].first >> segments[i].second;
        }

        bool possible = true;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (intersect(segments[i], segments[j])) {
                    possible = false;
                    break;
                }
            }
            if (!possible) {
                cout << -1 << endl;
                break;
            }
        }

        if (possible) {
            int group = 1;
            for (int i = 0; i < n; i++) {
                cout << group << " ";
                group = 3 - group;
            }
            cout << endl;
        }
    }

    return 0;
}
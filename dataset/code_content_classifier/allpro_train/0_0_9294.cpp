#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> good_path(m);
    for (int i = 0; i < m; i++) {
        cin >> good_path[i];
    }

    unordered_map<int, vector<int>> shortcuts;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vector<int> shortcut(k);
        for (int j = 0; j < k; j++) {
            cin >> shortcut[j];
        }
        shortcuts[shortcut.front()] = shortcut;
    }

    int q;
    cin >> q;

    queue<pair<int, int>> missions;
    for (int i = 0; i < q; i++) {
        char event;
        int s, t;
        cin >> event >> s >> t;
        
        if (event == '+') {
            // Do nothing for now
        } else if (event == '?') {
            missions.push({s, t});
        }

        while (!missions.empty()) {
            int s = missions.front().first;
            int t = missions.front().second;
            missions.pop();

            int min_gnomes = n;
            for (int castle : good_path) {
                if (castle >= s && castle <= t) {
                    min_gnomes = min(min_gnomes, castle - s);
                } else if (castle <= s && castle >= t) {
                    min_gnomes = min(min_gnomes, s - castle);
                }
            }

            if (shortcuts.count(s) && shortcuts.count(t)) {
                for (int castle : shortcuts[s]) {
                    if (castle >= s && castle <= t) {
                        min_gnomes = min(min_gnomes, castle - s);
                    } else if (castle <= s && castle >= t) {
                        min_gnomes = min(min_gnomes, s - castle);
                    }
                }
                for (int castle : shortcuts[t]) {
                    if (castle >= s && castle <= t) {
                        min_gnomes = min(min_gnomes, castle - s);
                    } else if (castle <= s && castle >= t) {
                        min_gnomes = min(min_gnomes, s - castle);
                    }
                }
            }

            cout << min_gnomes << endl;
        }
    }

    return 0;
}
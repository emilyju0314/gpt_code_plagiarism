#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> districts(n);
        unordered_set<int> gangs;
        vector<pair<int, int>> roads;

        for (int i = 0; i < n; i++) {
            cin >> districts[i];
            gangs.insert(districts[i]);
        }

        if (gangs.size() == 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;

            int gang1 = -1, gang2 = -1;
            for (int i = 1; i < n; i++) {
                if (districts[i] != districts[0]) {
                    gang1 = districts[0];
                    gang2 = districts[i];
                    roads.push_back(make_pair(1, i + 1));
                }
            }

            for (int i = 1; i < n - 1; i++) {
                if (districts[i] == gang1) {
                    roads.push_back(make_pair(i + 1, n));
                } else {
                    roads.push_back(make_pair(i + 1, n - 1));
                }
            }

            for (auto road : roads) {
                cout << road.first << " " << road.second << endl;
            }
        }
    }

    return 0;
}
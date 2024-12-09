#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> players(2 * n, 0);
        for (int j = 1; j <= 2 * n; j++) {
            players[j - 1] = j;
        }

        vector<bool> selected(2 * n, false);

        for (int j = 0; j < n - 1; j++) {
            vector<pair<int, int>> matches;
            for (int k = 0; k < 2 * n; k++) {
                if (!selected[k]) {
                    for (int l = k + 1; l < 2 * n; l++) {
                        if (!selected[l]) {
                            cout << "? " << players[k] << " " << players[l] << endl;
                            cout.flush();
                            char outcome;
                            cin >> outcome;
                            if (outcome == '>') {
                                matches.push_back({players[k], players[l]});
                            } else {
                                matches.push_back({players[l], players[k]});
                            }
                        }
                    }
                }
            }

            vector<int> new_order;
            for (int k = 0; k < matches.size(); k++) {
                if (new_order.empty() || new_order.back() != matches[k].first) {
                    new_order.push_back(matches[k].first);
                }
                new_order.push_back(matches[k].second);
            }

            players = new_order;

            for (int k = 0; k < 2 * n; k++) {
                selected[k] = false;
            }

            for (int k = 0; k < n; k++) {
                selected[k] = true;
            }
        }

        cout << "!" << endl;
        cout.flush();
    }

    return 0;
}
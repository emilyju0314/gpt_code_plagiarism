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

        vector<vector<int>> sets;
        vector<unordered_set<int>> elements;

        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;

            sets.push_back(vector<int>(k));
            elements.push_back(unordered_set<int>());

            for (int j = 0; j < k; j++) {
                cin >> sets[i][j];
                elements[i].insert(sets[i][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int count = 0;
                int x, y;
                for (int elem : sets[i]) {
                    if (elements[j].count(elem) > 0) {
                        count++;
                        if (count == 1) {
                            x = elem;
                        } else if (count == 2) {
                            y = elem;
                            break;
                        }
                    }
                    if (count == 2) {
                        cout << i + 1 << " " << j + 1 << endl;
                        x = -1;
                        break;
                    }
                }

                if (x == -1) {
                    break;
                }
            }
        }

        if (x != -1) {
            cout << -1 << endl;
        }
    }

    return 0;
}
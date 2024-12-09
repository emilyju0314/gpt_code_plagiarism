#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> parts(n);
    for (int i = 0; i < n; i++) {
        cin >> parts[i].first >> parts[i].second;
    }

    int m;
    cin >> m;

    vector<tuple<int, int, int>> actors(m);
    for (int i = 0; i < m; i++) {
        int c, d, k;
        cin >> c >> d >> k;
        actors[i] = make_tuple(c, d, k);
    }

    vector<int> assignments(n, -1); // Initialize assignments as -1 for each part

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int c, d, k;
            tie(c, d, k) = actors[j];

            if (k > 0 && c <= parts[i].first && parts[i].second <= d) {
                assignments[i] = j + 1;
                actors[j] = make_tuple(c, d, k - 1);
                break;
            }
        }
    }

    bool valid_assignment = all_of(assignments.begin(), assignments.end(), [](int x){ return x != -1; });

    if (valid_assignment) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << assignments[i] << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
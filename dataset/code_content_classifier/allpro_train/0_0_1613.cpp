#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> max_values(n+1, 1e9);
    vector<pair<int, int>> assignments;

    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;

        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            for (int j = l; j <= r; j++) {
                max_values[j] = min(max_values[j], x);
            }
        } else {
            int k, d;
            cin >> k >> d;
            assignments.push_back({k, d});
        }
    }

    vector<int> sequence(n+1, 0);
    set<int> updated_indices;

    for (auto assignment : assignments) {
        int k = assignment.first;
        int d = assignment.second;

        sequence[k] = d;
        updated_indices.insert(k);
    }

    for (int i = 1; i <= n; i++) {
        if (sequence[i] == 0) {
            sequence[i] = max_values[i];
        }
    }

    int cuteness = 0;
    for (int num : sequence) {
        cuteness |= num;
    }

    bool possible = true;
    for (int i = 1; i <= n; i++) {
        if (updated_indices.count(i) == 0) {
            int temp = 0;
            for (int j = i; j <= n; j++) {
                temp |= sequence[j];
                if (temp > max_values[j]) {
                    possible = false;
                    break;
                }
            }
            break;
        }
    }

    if (possible) {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++) {
            cout << sequence[i] << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
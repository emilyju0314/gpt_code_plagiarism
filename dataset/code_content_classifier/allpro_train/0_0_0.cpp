#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b = a;
    sort(b.begin(), b.end());

    if (a == b) {
        cout << "0" << endl;
        return 0;
    }

    vector<pair<int, vector<int>>> operations;
    int q = 0;
    int sum_lengths = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            q++;
            int j = i;
            vector<int> cycle;
            int cycle_length = 0;
            int minimum = a[i];
            while (a[j] != b[i]) {
                j = find(a.begin(), a.end(), b[i]) - a.begin();
                a[j] = a[i];
                cycle.push_back(j+1);
                cycle_length++;
                minimum = min(minimum, a[j]);
            }
            sum_lengths += cycle_length;
            if (sum_lengths > s) {
                cout << "-1" << endl;
                return 0;
            }
            operations.push_back({cycle_length, cycle});
        }
    }

    cout << q << endl;
    for (int i = 0; i < operations.size(); i++) {
        cout << operations[i].first << endl;
        for (int j = 0; j < operations[i].first; j++) {
            cout << operations[i].second[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

vector<int> a;

void cyclicShift(int l, int r, int d) {
    vector<int> segment;
    for (int i = l - 1; i < r; i++) {
        segment.push_back(a[i]);
    }

    d %= segment.size();

    vector<int> newSegment(segment.size());
    for (int i = 0; i < segment.size(); i++) {
        newSegment[(i - d + segment.size()) % segment.size()] = segment[i];
    }

    for (int i = l - 1, j = 0; i < r; i++, j++) {
        a[i] = newSegment[j];
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        a.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<vector<int>> actions;
        for (int i = 1; i <= n; i++) {
            for (int j = n; j > i; j--) {
                actions.push_back({i, j, j-i});
            }
        }

        cout << actions.size() << endl;
        for (auto action : actions) {
            cyclicShift(action[0], action[1], action[2]);
            cout << action[0] << " " << action[1] << " " << action[2] << endl;
        }
    }

    return 0;
}
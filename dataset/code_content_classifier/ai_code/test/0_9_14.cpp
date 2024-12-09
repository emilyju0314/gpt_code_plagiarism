#include <iostream>
#include <vector>

using namespace std;

void cyclicShift(vector<int>& a, int l, int r, int d) {
    vector<int> segment;
    for (int i = l - 1; i < r; i++) {
        segment.push_back(a[i]);
    }

    d = d % segment.size();
    rotate(segment.begin(), segment.begin() + d, segment.end());

    for (int i = l - 1, j = 0; i < r; i++, j++) {
        a[i] = segment[j];
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<vector<int>> actions;
        for (int i = 0; i < n - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < n; j++) {
                if (a[j] < a[min_idx]) {
                    min_idx = j;
                }
            }

            if (min_idx == i) {
                continue;
            }

            int d = min_idx - i;
            actions.push_back({i + 1, min_idx + 1, d});
            cyclicShift(a, i + 1, min_idx + 1, d);
        }

        cout << actions.size() << endl;
        for (auto& action : actions) {
            cout << action[0] << " " << action[1] << " " << action[2] << endl;
        }
    }

    return 0;
}
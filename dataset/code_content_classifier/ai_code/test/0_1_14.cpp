#include <iostream>
#include <vector>

using namespace std;

void cyclicShift(vector<int>& a, int l, int r, int d) {
    vector<int> segment;
    for (int i = l - 1; i <= r - 1; i++) {
        segment.push_back(a[i]);
    }
    d %= (r - l + 1);
    rotate(segment.begin(), segment.begin() + d, segment.end());
    for (int i = l - 1, j = 0; i <= r - 1; i++, j++) {
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
        
        bool sorted = false;
        for (int k = 1; k <= n && !sorted; k++) {
            for (int i = 0; i <= n - k && !sorted; i++) {
                int j = i + k - 1;
                vector<int> original = a;
                cyclicShift(a, i + 1, j + 1, 1);
                for (int x = 1; x < n; x++) {
                    if (a[x] < a[x - 1]) {
                        a = original;
                        break;
                    }
                    if (x == n - 1) {
                        sorted = true;
                        actions.push_back({i + 1, j + 1, 1});
                    }
                }
            }
        }

        cout << actions.size() << endl;
        for (int i = 0; i < actions.size(); i++) {
            cout << actions[i][0] << " " << actions[i][1] << " " << actions[i][2] << endl;
        }
    }

    return 0;
}
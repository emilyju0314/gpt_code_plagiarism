#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> ranges(n);
        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            ranges[i] = make_pair(l, r);
        }

        vector<int> nums(n, 0);
        // Assigning values to each range in decreasing order
        for (int i = n; i > 0; i--) {
            for (int j = 0; j < n; j++) {
                if (ranges[j].second - ranges[j].first == i - 1) {
                    nums[j] = i;
                    int d = ranges[j].first;
                    cout << ranges[j].first << " " << ranges[j].second << " " << d << endl;
                    ranges.erase(ranges.begin() + j);
                    break;
                }
            }
        }
    }

    return 0;
}